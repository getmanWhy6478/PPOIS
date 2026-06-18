class ReversiLogic:
    def __init__(self, size=8):
        self.size = size
        self.board = [[0] * size for _ in range(size)]
        self.current_player = 1
        self.reset()

    def reset(self):
        mid = self.size // 2
        self.board = [[0] * self.size for _ in range(self.size)]
        self.board[mid - 1][mid - 1] = 1
        self.board[mid][mid] = 1
        self.board[mid - 1][mid] = -1
        self.board[mid][mid - 1] = -1
        self.current_player = 1

    def get_valid_moves(self, player):
        moves = []
        for x in range(self.size):
            for y in range(self.size):
                if self.board[x][y] == 0:
                    flips = self.check_flips(x, y, player)
                    if flips:
                        moves.append((x, y))
        return moves

    def check_flips(self, x, y, player):
        opponent = -player
        directions = [(0, 1), (1, 1), (1, 0), (1, -1),
                      (0, -1), (-1, -1), (-1, 0), (-1, 1)]
        total_flips = []

        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            current_flips = []
            while (0 <= nx < self.size and 0 <= ny < self.size
                   and self.board[nx][ny] == opponent):
                current_flips.append((nx, ny))
                nx += dx
                ny += dy

            if (current_flips and 0 <= nx < self.size and 0 <= ny < self.size
                    and self.board[nx][ny] == player):
                total_flips.extend(current_flips)

        return total_flips

    def make_move(self, x, y):
        if self.board[x][y] != 0:
            return False, []

        flips = self.check_flips(x, y, self.current_player)
        if not flips:
            return False, []

        self.board[x][y] = self.current_player
        for fx, fy in flips:
            self.board[fx][fy] = self.current_player

        flipped = flips.copy()
        self.current_player = -self.current_player
        return True, flipped

    def get_score(self):
        black = sum(row.count(1) for row in self.board)
        white = sum(row.count(-1) for row in self.board)
        return black, white

    def is_game_over(self):
        # Игра окончена, если у обоих игроков нет ходов
        if not self.get_valid_moves(1) and not self.get_valid_moves(-1):
            return True
        return False

    def must_skip_turn(self, player):
        """Проверка, должен ли игрок пропустить ход"""
        return len(self.get_valid_moves(player)) == 0

    def skip_turn(self):
        """Пропустить ход текущего игрока"""
        self.current_player = -self.current_player

    def get_board_state(self):
        return [row[:] for row in self.board]

    def set_board_state(self, board_state, current_player):
        self.board = [row[:] for row in board_state]
        self.current_player = current_player

    def has_valid_moves(self, player):
        return len(self.get_valid_moves(player)) > 0