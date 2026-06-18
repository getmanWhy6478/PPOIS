import socket
import json
import threading
from config import CONFIG


class NetworkClient:
    def __init__(self):
        self.client = None
        self.connected = False
        self.player_id = None
        self.receive_thread = None
        self.callbacks = {}
        self.lock = threading.Lock()


    def connect(self, host=None, port=None):
        # Получаем значения с дефолтными fallback
        host = host or CONFIG.get_server_host()
        port = port or CONFIG.get_server_port()

        try:
            self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.client.settimeout(5.0)
            self.client.connect((host, port))
            self.client.settimeout(None)
            self.connected = True

            data = self.client.recv(4096).decode()
            msg = json.loads(data)
            self.player_id = msg.get('player_id')
            print(f"Подключён как игрок {self.player_id}")

            self.receive_thread = threading.Thread(target=self.receive_loop)
            self.receive_thread.daemon = True
            self.receive_thread.start()

            return True
        except Exception as e:
            print(f"Ошибка подключения: {e}")
            self.connected = False
            return False

    def receive_loop(self):
        buffer = ""
        while self.connected:
            try:
                data = self.client.recv(4096).decode()
                if not data:
                    self.connected = False
                    break

                buffer += data
                while '\n' in buffer:
                    line, buffer = buffer.split('\n', 1)
                    if line.strip():
                        msg = json.loads(line)
                        msg_type = msg.get('type')

                        with self.lock:
                            if msg_type in self.callbacks:
                                self.callbacks[msg_type](msg)

            except socket.timeout:
                continue
            except Exception as e:
                print(f"Ошибка получения: {e}")
                self.connected = False
                break

        self.connected = False

    def send(self, msg_type, data=None):
        if not self.connected or not self.client:
            return False

        message = json.dumps({'type': msg_type, 'data': data or {}}) + '\n'
        try:
            with self.lock:
                self.client.send(message.encode())
            return True
        except Exception as e:
            print(f"Ошибка отправки: {e}")
            self.connected = False
            return False

    def send_move(self, x, y):
        return self.send('move', {'x': x, 'y': y})

    def send_find_game(self):
        return self.send('find_game', {})

    def register_callback(self, msg_type, callback):
        with self.lock:
            self.callbacks[msg_type] = callback

    def disconnect(self):
        self.connected = False
        if self.client:
            try:
                self.client.close()
            except:
                pass
        self.client = None


class NetworkServer:
    def __init__(self, host=None, port=None):
        # Явно получаем значения с дефолтными fallback
        self.host = host if host else CONFIG.get_server_host()
        self.port = port if port else CONFIG.get_server_port()

        # Дополнительная проверка
        if self.host is None:
            self.host = "127.0.0.1"
        if self.port is None:
            self.port = 5555

        self.server = None
        self.clients = {}
        self.games = {}
        self.running = False
        self.player_counter = 0
        self.lock = threading.Lock()
        self.game_counter = 0

    def start(self):
        print(f"Инициализация сервера...")
        print(f"Хост: {self.host}, Порт: {self.port}")

        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

        try:
            self.server.bind((self.host, self.port))
            print(f"Сервер успешно привязан к {self.host}:{self.port}")
        except Exception as e:
            print(f"Ошибка привязки: {e}")
            raise

        self.server.listen(10)
        self.server.settimeout(1.0)
        self.running = True

        print(f"Сервер запущен на {self.host}:{self.port}")
        print("Ожидание подключений...")

        while self.running:
            try:
                client, addr = self.server.accept()
                with self.lock:
                    self.player_counter += 1
                    player_id = self.player_counter

                self.clients[player_id] = {
                    'client': client,
                    'addr': addr,
                    'game_id': None,
                    'player_color': None,
                    'board': None,
                    'current_player': None
                }

                msg = json.dumps({'type': 'connected', 'player_id': player_id}) + '\n'
                client.send(msg.encode())

                print(f"Игрок {player_id} подключился из {addr}")

                thread = threading.Thread(target=self.handle_client, args=(player_id,))
                thread.daemon = True
                thread.start()

            except socket.timeout:
                continue
            except Exception as e:
                if self.running:
                    print(f"Ошибка сервера: {e}")
    def handle_client(self, player_id):
        client = self.clients[player_id]['client']
        client.settimeout(1.0)
        buffer = ""

        while self.running and player_id in self.clients:
            try:
                data = client.recv(4096).decode()
                if not data:
                    break

                buffer += data
                while '\n' in buffer:
                    line, buffer = buffer.split('\n', 1)
                    if line.strip():
                        msg = json.loads(line)
                        msg_type = msg.get('type')
                        msg_data = msg.get('data', {})

                        if msg_type == 'move':
                            self.handle_move(player_id, msg_data)
                        elif msg_type == 'find_game':
                            self.find_game(player_id)

            except socket.timeout:
                continue
            except Exception as e:
                print(f"Ошибка клиента {player_id}: {e}")
                break

        self.remove_client(player_id)

    def handle_move(self, player_id, data):
        with self.lock:
            if player_id not in self.clients:
                return

            game_id = self.clients[player_id].get('game_id')
            if not game_id or game_id not in self.games:
                return

            game = self.games[game_id]

            if game['current_player'] != self.clients[player_id]['player_color']:
                return

            self.broadcast_to_game(game_id, {
                'type': 'move_made',
                'data': {
                    'x': data['x'],
                    'y': data['y'],
                    'next_player': -game['current_player']
                }
            })

            game['current_player'] = -game['current_player']

    def find_game(self, player_id):
        with self.lock:
            for game_id, game in self.games.items():
                if game['player2'] is None:
                    game['player2'] = player_id
                    self.clients[player_id]['game_id'] = game_id
                    self.clients[player_id]['player_color'] = -1
                    self.clients[player_id]['board'] = game['board']
                    self.clients[player_id]['current_player'] = game['current_player']

                    self.notify_game_start(game_id)
                    return

            self.game_counter += 1
            game_id = self.game_counter

            board = [[0] * 8 for _ in range(8)]
            board[3][3] = 1
            board[4][4] = 1
            board[3][4] = -1
            board[4][3] = -1

            self.games[game_id] = {
                'player1': player_id,
                'player2': None,
                'board': board,
                'current_player': 1
            }

            self.clients[player_id]['game_id'] = game_id
            self.clients[player_id]['player_color'] = 1
            self.clients[player_id]['board'] = board
            self.clients[player_id]['current_player'] = 1

            msg = json.dumps({
                'type': 'waiting',
                'data': {'message': 'Ожидание соперника...'}
            }) + '\n'

            try:
                self.clients[player_id]['client'].send(msg.encode())
            except:
                pass

    def notify_game_start(self, game_id):
        game = self.games[game_id]

        for pid in [game['player1'], game['player2']]:
            if pid and pid in self.clients:
                msg = json.dumps({
                    'type': 'game_start',
                    'data': {
                        'player_color': self.clients[pid]['player_color'],
                        'board': game['board'],
                        'current_player': game['current_player']
                    }
                }) + '\n'

                try:
                    self.clients[pid]['client'].send(msg.encode())
                except:
                    pass

    def broadcast_to_game(self, game_id, msg_data):
        game = self.games.get(game_id)
        if not game:
            return

        msg = json.dumps(msg_data) + '\n'

        for pid in [game['player1'], game['player2']]:
            if pid and pid in self.clients:
                try:
                    self.clients[pid]['client'].send(msg.encode())
                except:
                    pass

    def remove_client(self, player_id):
        with self.lock:
            if player_id not in self.clients:
                return

            game_id = self.clients[player_id].get('game_id')
            if game_id and game_id in self.games:
                game = self.games[game_id]
                opponent_id = (game['player1'] if player_id == game['player2']
                               else game['player2'])

                if opponent_id and opponent_id in self.clients:
                    msg = json.dumps({
                        'type': 'opponent_disconnected',
                        'data': {}
                    }) + '\n'
                    try:
                        self.clients[opponent_id]['client'].send(msg.encode())
                    except:
                        pass

                del self.games[game_id]

            del self.clients[player_id]
            print(f"Игрок {player_id} отключился")

    def stop(self):
        self.running = False
        if self.server:
            self.server.close()
