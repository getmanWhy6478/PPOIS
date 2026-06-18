#!/usr/bin/env python3
import pygame
import sys
import time
from config import CONFIG
from game_logic import ReversiLogic
from ui import GameUI
from menu import Menu
from sound import SoundManager
from leaderboard import Leaderboard
from network import NetworkClient


class GameApp:
    def __init__(self):
        pygame.init()
        self.screen = pygame.display.set_mode(
            (CONFIG["window_width"], CONFIG["window_height"])
        )
        pygame.display.set_caption("Реверси (Othello)")
        self.clock = pygame.time.Clock()

        self.sound_manager = SoundManager()
        self.leaderboard = Leaderboard()
        self.menu = Menu(self.screen)
        self.menu.create_main_menu()

        self.state = "MENU"
        self.logic = ReversiLogic()
        self.ui = GameUI(self.screen, self.logic)
        self.ui.game_mode = "local"

        self.input_text = ""
        self.final_score = 0
        self.chat_messages = []
        self.chat_input = ""

        self.network_client = None
        self.waiting_for_opponent = False
        self.online_game_started = False
        self.last_move_time = 0

        self.skip_turn_pending = False
        self.skip_turn_checked = False

        # ← НОВОЕ: Информация о победителе
        self.winner = None
        self.final_score_detail = (0, 0)  # (чёрные, белые)

    def run(self):
        running = True
        while running:
            dt = self.clock.tick(CONFIG["fps"]) / 1000.0
            self.screen.fill(CONFIG["colors"]["background"])

            mouse_x, mouse_y = pygame.mouse.get_pos()

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False

                if self.state == "MENU":
                    self.handle_menu_events(event)
                elif self.state == "PLAYING_LOCAL":
                    self.handle_local_game_events(event, mouse_x, mouse_y)
                elif self.state == "PLAYING_ONLINE":
                    self.handle_online_game_events(event, mouse_x, mouse_y)
                elif self.state == "GAME_OVER":
                    self.handle_game_over_events(event)
                elif self.state == "LEADERBOARD":
                    self.handle_leaderboard_events(event)
                elif self.state == "HELP":
                    self.handle_help_events(event)
                elif self.state == "INPUT_NAME":
                    self.handle_input_events(event)
                elif self.state == "ONLINE_MENU":
                    self.handle_online_menu_events(event)

            if self.state in ["PLAYING_LOCAL", "PLAYING_ONLINE"]:
                self.ui.update_hover(mouse_x, mouse_y)
                self.ui.update_skip_turn_timer(dt)

            if self.state == "PLAYING_LOCAL" and not self.skip_turn_checked:
                self.check_skip_turn_local()

            self.draw()
            pygame.display.flip()

        if self.network_client:
            self.network_client.disconnect()
        pygame.quit()
        sys.exit()

    def draw(self):
        if self.state == "MENU":
            title = self.ui.font_large.render("РЕВЕРСИ", True, CONFIG["colors"]["text"])
            self.screen.blit(title, (320, 50))
            self.menu.draw()

        elif self.state == "ONLINE_MENU":
            title = self.ui.font_large.render("ОНЛАЙН ИГРА", True, CONFIG["colors"]["text"])
            self.screen.blit(title, (320, 50))
            self.menu.draw()

        elif self.state == "PLAYING_LOCAL":
            self.ui.draw_board()
            self.ui.draw_pieces()
            self.ui.draw_valid_moves()
            self.ui.draw_scores()
            self.ui.update_animations()
            self.ui.draw_skip_turn_message()

        elif self.state == "PLAYING_ONLINE":
            self.ui.draw_board()
            self.ui.draw_pieces()
            self.ui.draw_valid_moves()
            self.ui.draw_scores()
            self.ui.update_animations()
            self.ui.draw_skip_turn_message()
            if self.chat_input:
                self.ui.draw_chat_input(self.chat_input)

            if self.waiting_for_opponent:
                self.ui.draw_waiting("Ожидание соперника...")

        elif self.state == "GAME_OVER":
            self.draw_game_over()

        elif self.state == "LEADERBOARD":
            self.menu.draw_leaderboard(self.leaderboard.get_top())

        elif self.state == "HELP":
            self.menu.draw_help()

        # ← ИСПРАВЛЕНО: Передача информации о победителе
        elif self.state == "INPUT_NAME":
            self.menu.draw_input_name(self.input_text, self.winner, self.final_score_detail)

    def check_skip_turn_local(self):
        self.skip_turn_checked = True

        if self.logic.must_skip_turn(self.logic.current_player):
            opponent = -self.logic.current_player
            if self.logic.has_valid_moves(opponent):
                self.sound_manager.play_sfx('error')
                self.ui.show_skip_turn_message(self.logic.current_player)
                self.logic.skip_turn()
                self.ui.rotate_board_for_player()
                self.skip_turn_pending = True
                return

        if self.logic.is_game_over():
            self.state = "GAME_OVER"
            b, w = self.logic.get_score()
            self.final_score = max(b, w)
            self.final_score_detail = (b, w)  # ← НОВОЕ: Сохраняем детальный счёт

            if b > w:
                self.winner = "Чёрные"
            elif w > b:
                self.winner = "Белые"
            else:
                self.winner = "Ничья"

            if self.leaderboard.is_high_score(self.final_score):
                self.state = "INPUT_NAME"
            else:
                self.sound_manager.play_sfx('win')

    def handle_menu_events(self, event):
        if event.type == pygame.MOUSEBUTTONDOWN:
            action = self.menu.handle_click(event.pos)
            if action == "play_local":
                self.start_local_game()
            elif action == "play_online":
                self.state = "ONLINE_MENU"
                self.menu.create_online_menu()
            elif action == "leaderboard":
                self.state = "LEADERBOARD"
            elif action == "help":
                self.state = "HELP"
            elif action == "quit":
                pygame.quit()
                sys.exit()

    def handle_online_menu_events(self, event):
        if event.type == pygame.MOUSEBUTTONDOWN:
            action = self.menu.handle_click(event.pos)
            print(f"Действие в онлайн-меню: {action}")

            if action == "find_game":
                self.connect_to_server()
            elif action == "back":
                print("Возврат в главное меню...")
                self.state = "MENU"
                self.menu.create_main_menu()

        if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
            self.state = "MENU"
            self.menu.create_main_menu()

    def connect_to_server(self):
        self.network_client = NetworkClient()
        if self.network_client.connect():
            self.network_client.register_callback('game_start', self.on_game_start)
            self.network_client.register_callback('waiting', self.on_waiting)
            self.network_client.register_callback('move_made', self.on_move_made)
            self.network_client.register_callback('opponent_disconnected', self.on_opponent_disconnect)
            self.network_client.register_callback('chat_message', self.on_chat_message)
            self.network_client.register_callback('skip_turn', self.on_skip_turn)

            self.network_client.send_find_game()
            self.waiting_for_opponent = True
            self.online_game_started = False
            self.state = "PLAYING_ONLINE"
        else:
            self.chat_messages.append({'sender': 'system', 'text': 'Не удалось подключиться к серверу!'})
            self.state = "MENU"

    def on_game_start(self, msg):
        data = msg['data']
        self.ui.my_color = data['player_color']
        self.ui.game_mode = "online"
        self.ui.rotate_board_for_player()

        if 'board' in data:
            board = data['board']
            for r in range(8):
                for c in range(8):
                    self.logic.board[r][c] = board[r][c]
            self.logic.current_player = data['current_player']

        self.waiting_for_opponent = False
        self.online_game_started = True
        self.chat_messages.append(
            {'sender': 'system', 'text': f'Вы играете за {"Чёрных" if self.ui.my_color == 1 else "Белых"}'})

    def on_waiting(self, msg):
        self.waiting_for_opponent = True
        self.online_game_started = False

    def on_move_made(self, msg):
        data = msg['data']
        x, y = data['x'], data['y']

        self.logic.make_move(x, y)
        self.ui.rotate_board_for_player()
        self.sound_manager.play_sfx('move')

        if self.logic.must_skip_turn(self.logic.current_player):
            if self.logic.has_valid_moves(-self.logic.current_player):
                self.logic.skip_turn()
                self.ui.rotate_board_for_player()
                self.ui.show_skip_turn_message(-self.logic.current_player)
                self.sound_manager.play_sfx('error')

        if self.logic.is_game_over():
            self.state = "GAME_OVER"
            b, w = self.logic.get_score()
            self.final_score = max(b, w)
            self.final_score_detail = (b, w)

            if b > w:
                self.winner = "Чёрные"
            elif w > b:
                self.winner = "Белые"
            else:
                self.winner = "Ничья"

            if self.leaderboard.is_high_score(self.final_score):
                self.state = "INPUT_NAME"

    def on_skip_turn(self, msg):
        data = msg['data']
        player = data.get('player', self.logic.current_player)

        self.logic.skip_turn()
        self.ui.rotate_board_for_player()
        self.ui.show_skip_turn_message(player)
        self.sound_manager.play_sfx('error')

    def on_opponent_disconnect(self, msg):
        self.waiting_for_opponent = True
        self.online_game_started = False
        self.chat_messages.append({'sender': 'system', 'text': 'Соперник отключился!'})

    def on_chat_message(self, msg):
        data = msg['data']
        self.chat_messages.append({'sender': 'opp', 'text': f"Игрок {data['player_id']}: {data['message']}"})

    def handle_local_game_events(self, event, mouse_x, mouse_y):
        if event.type == pygame.MOUSEBUTTONDOWN and not self.ui.animations:
            if self.skip_turn_pending:
                self.skip_turn_pending = False
                self.skip_turn_checked = False
                return

            row, col = self.ui.get_logical_pos(mouse_x, mouse_y)

            if row is not None and col is not None:
                if self.logic.board[row][col] != 0:
                    self.sound_manager.play_sfx('error')
                    return

                valid_moves = self.logic.get_valid_moves(self.logic.current_player)
                if (row, col) not in valid_moves:
                    self.sound_manager.play_sfx('error')
                    return

                success, flips = self.logic.make_move(row, col)
                if success:
                    self.sound_manager.play_sfx('move')
                    x, y = self.ui.get_cell_pos(row, col)
                    last_player = -self.logic.current_player
                    anim_color = (CONFIG["colors"]["black_piece"]
                                  if last_player == 1
                                  else CONFIG["colors"]["white_piece"])
                    self.ui.add_animation(x, y, anim_color)

                    self.ui.rotate_board_for_player()
                    self.skip_turn_checked = False

                    if self.logic.is_game_over():
                        self.state = "GAME_OVER"
                        b, w = self.logic.get_score()
                        self.final_score = max(b, w)
                        self.final_score_detail = (b, w)  # ← НОВОЕ

                        # ← НОВОЕ: Определяем победителя
                        if b > w:
                            self.winner = "Чёрные"
                        elif w > b:
                            self.winner = "Белые"
                        else:
                            self.winner = "Ничья"

                        if self.leaderboard.is_high_score(self.final_score):
                            self.state = "INPUT_NAME"
                        else:
                            self.sound_manager.play_sfx('win')
                else:
                    self.sound_manager.play_sfx('error')

        if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
            self.state = "MENU"
            self.menu.create_main_menu()

    def handle_online_game_events(self, event, mouse_x, mouse_y):
        if self.waiting_for_opponent or not self.online_game_started:
            if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                if self.network_client:
                    self.network_client.disconnect()
                self.state = "MENU"
                self.menu.create_main_menu()
            return

        if self.logic.current_player != self.ui.my_color:
            if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                if self.network_client:
                    self.network_client.disconnect()
                self.state = "MENU"
                self.menu.create_main_menu()
            return

        if event.type == pygame.MOUSEBUTTONDOWN and not self.ui.animations:
            row, col = self.ui.get_logical_pos(mouse_x, mouse_y)

            if row is not None and col is not None:
                if self.logic.board[row][col] != 0:
                    self.sound_manager.play_sfx('error')
                    return

                valid_moves = self.logic.get_valid_moves(self.logic.current_player)
                if (row, col) in valid_moves:
                    current_time = time.time()
                    if current_time - self.last_move_time > 0.5:
                        self.network_client.send_move(row, col)
                        self.last_move_time = current_time
                else:
                    self.sound_manager.play_sfx('error')

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE:
                if self.network_client:
                    self.network_client.disconnect()
                self.state = "MENU"
                self.menu.create_main_menu()
            elif event.key == pygame.K_BACKSPACE:
                self.chat_input = self.chat_input[:-1]
            elif len(event.unicode) == 1 and len(self.chat_input) < 50:
                self.chat_input += event.unicode

    def handle_game_over_events(self, event):
        if event.type == pygame.MOUSEBUTTONDOWN:
            x, y = event.pos
            if 300 < x < 500 and 400 < y < 450:
                self.state = "MENU"
                self.menu.create_main_menu()
                self.logic.reset()
                self.ui.game_mode = "local"

        if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
            self.state = "MENU"
            self.menu.create_main_menu()
            self.logic.reset()
            self.ui.game_mode = "local"

    def handle_leaderboard_events(self, event):
        if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
            self.state = "MENU"

    def handle_help_events(self, event):
        if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
            self.state = "MENU"

    def handle_input_events(self, event):
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RETURN:
                if self.input_text:
                    self.leaderboard.add_score(self.input_text, self.final_score)
                    self.state = "LEADERBOARD"
                    self.input_text = ""
            elif event.key == pygame.K_BACKSPACE:
                self.input_text = self.input_text[:-1]
            elif len(self.input_text) < 10:
                self.input_text += event.unicode

    def start_local_game(self):
        self.logic.reset()
        self.ui.my_color = 1
        self.ui.game_mode = "local"
        self.ui.rotation_angle = 0
        self.skip_turn_checked = False
        self.skip_turn_pending = False
        self.winner = None
        self.final_score_detail = (0, 0)
        self.state = "PLAYING_LOCAL"

    def draw_game_over(self):
        b, w = self.logic.get_score()
        if b > w:
            winner = "Чёрные"
        elif w > b:
            winner = "Белые"
        else:
            winner = "Ничья"

        msg = f"Игра окончена! Победили: {winner}"
        score_msg = f"Счёт: {b} - {w}"

        t1 = self.ui.font_large.render(msg, True, CONFIG["colors"]["text"])
        t2 = self.ui.font_small.render(score_msg, True, CONFIG["colors"]["text"])
        t3 = self.ui.font_small.render("В меню", True, CONFIG["colors"]["text"])

        self.screen.blit(t1, (150, 200))
        self.screen.blit(t2, (350, 250))

        pygame.draw.rect(self.screen, (100, 100, 255), (300, 400, 200, 50))
        self.screen.blit(t3, (340, 415))


def main():
    app = GameApp()
    app.run()


if __name__ == "__main__":
    main()