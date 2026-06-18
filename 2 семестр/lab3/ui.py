import pygame
from config import CONFIG


class Animation:
    def __init__(self, x, y, color, max_size):
        self.x = x
        self.y = y
        self.color = color
        self.current_size = 0
        self.max_size = max_size
        self.speed = 8
        self.finished = False

    def update(self):
        if self.current_size < self.max_size:
            self.current_size += self.speed
            if self.current_size > self.max_size:
                self.current_size = self.max_size
            self.finished = False
        else:
            self.finished = True

    def draw(self, surface):
        if not self.finished:
            pygame.draw.circle(surface, self.color, (self.x, self.y), int(self.current_size))


class GameUI:
    def __init__(self, screen, logic):
        self.screen = screen
        self.logic = logic
        self.animations = []
        self.rotation_angle = 0
        self.my_color = 1
        self.game_mode = "local"

        self.font_large = pygame.font.SysFont('Arial', 40, bold=True)
        self.font_small = pygame.font.SysFont('Arial', 20)
        self.font_medium = pygame.font.SysFont('Arial', 28)
        self.hovered_cell = None

        self.skip_turn_message = ""
        self.skip_turn_timer = 0

    def get_board_offset(self):
        offset_x = (CONFIG["window_width"] - CONFIG["board_size"] * CONFIG["cell_size"]) // 2
        offset_y = (CONFIG["window_height"] - CONFIG["board_size"] * CONFIG["cell_size"]) // 2 + 40
        return offset_x, offset_y

    def get_cell_pos(self, row, col):
        if self.rotation_angle == 180:
            r = self.logic.size - 1 - row
            c = self.logic.size - 1 - col
        else:
            r, c = row, col

        offset_x, offset_y = self.get_board_offset()

        return (
            offset_x + c * CONFIG["cell_size"] + CONFIG["cell_size"] // 2,
            offset_y + r * CONFIG["cell_size"] + CONFIG["cell_size"] // 2
        )

    def get_logical_pos(self, screen_x, screen_y):
        offset_x, offset_y = self.get_board_offset()

        board_left = offset_x
        board_right = offset_x + CONFIG["board_size"] * CONFIG["cell_size"]
        board_top = offset_y
        board_bottom = offset_y + CONFIG["board_size"] * CONFIG["cell_size"]

        if not (board_left <= screen_x <= board_right and board_top <= screen_y <= board_bottom):
            return None, None

        col = int((screen_x - offset_x) / CONFIG["cell_size"])
        row = int((screen_y - offset_y) / CONFIG["cell_size"])

        col = max(0, min(col, self.logic.size - 1))
        row = max(0, min(row, self.logic.size - 1))

        if self.rotation_angle == 180:
            row = self.logic.size - 1 - row
            col = self.logic.size - 1 - col

        return row, col

    def update_hover(self, mouse_x, mouse_y):
        row, col = self.get_logical_pos(mouse_x, mouse_y)
        if row is not None and col is not None:
            self.hovered_cell = (row, col)
        else:
            self.hovered_cell = None

    def draw_board(self):
        offset_x, offset_y = self.get_board_offset()

        board_rect = pygame.Rect(offset_x, offset_y,
                                 CONFIG["board_size"] * CONFIG["cell_size"],
                                 CONFIG["board_size"] * CONFIG["cell_size"])
        pygame.draw.rect(self.screen, CONFIG["colors"]["board"], board_rect)
        pygame.draw.rect(self.screen, CONFIG["colors"]["board_border"], board_rect, 5)

        for i in range(CONFIG["board_size"] + 1):
            start = (offset_x, offset_y + i * CONFIG["cell_size"])
            end = (offset_x + CONFIG["board_size"] * CONFIG["cell_size"], offset_y + i * CONFIG["cell_size"])
            pygame.draw.line(self.screen, CONFIG["colors"]["board_border"], start, end, 2)

            start = (offset_x + i * CONFIG["cell_size"], offset_y)
            end = (offset_x + i * CONFIG["cell_size"], offset_y + CONFIG["board_size"] * CONFIG["cell_size"])
            pygame.draw.line(self.screen, CONFIG["colors"]["board_border"], start, end, 2)

    def draw_pieces(self):
        for r in range(self.logic.size):
            for c in range(self.logic.size):
                val = self.logic.board[r][c]
                if val != 0:
                    x, y = self.get_cell_pos(r, c)
                    color = CONFIG["colors"]["black_piece"] if val == 1 else CONFIG["colors"]["white_piece"]
                    radius = CONFIG["cell_size"] // 2 - 5
                    pygame.draw.circle(self.screen, color, (x, y), radius)
                    pygame.draw.circle(self.screen,
                                       (100, 100, 100) if val == 1 else (200, 200, 200),
                                       (x - radius // 3, y - radius // 3), radius // 4)

    def draw_valid_moves(self):
        valid = self.logic.get_valid_moves(self.logic.current_player)

        for r, c in valid:
            if self.logic.board[r][c] != 0:
                continue

            x, y = self.get_cell_pos(r, c)

            if self.hovered_cell == (r, c):
                pygame.draw.circle(self.screen, (150, 255, 150), (x, y), CONFIG["cell_size"] // 2 - 2)
                pygame.draw.circle(self.screen, (50, 200, 50), (x, y), CONFIG["cell_size"] // 2 - 2, 3)
            else:
                s = pygame.Surface((CONFIG["cell_size"], CONFIG["cell_size"]), pygame.SRCALPHA)
                pygame.draw.circle(s, (*CONFIG["colors"]["highlight"], 100),
                                   (CONFIG["cell_size"] // 2, CONFIG["cell_size"] // 2),
                                   CONFIG["cell_size"] // 2 - 5)
                self.screen.blit(s, (x - CONFIG["cell_size"] // 2, y - CONFIG["cell_size"] // 2))

    def draw_scores(self):
        b_score, w_score = self.logic.get_score()

        if self.game_mode == "online":
            if self.my_color == 1:
                my_score = b_score
                opp_score = w_score
                my_name = "Вы (Чёрные)"
                opp_name = "Игрок 2 (Белые)"
            else:
                my_score = w_score
                opp_score = b_score
                my_name = "Вы (Белые)"
                opp_name = "Игрок 2 (Чёрные)"
        else:
            if self.logic.current_player == 1:
                my_name = "Игрок 1 (Чёрные)"
                opp_name = "Игрок 2 (Белые)"
            else:
                my_name = "Игрок 2 (Белые)"
                opp_name = "Игрок 1 (Чёрные)"
            my_score = b_score if self.logic.current_player == 1 else w_score
            opp_score = w_score if self.logic.current_player == 1 else b_score

        if self.game_mode == "online":
            if self.logic.current_player == self.my_color:
                turn_text = "ВАШ ХОД"
                turn_color = (100, 255, 100)
            else:
                turn_text = "ХОД ИГРОКА 2"
                turn_color = (255, 200, 100)
        else:
            if self.logic.current_player == 1:
                turn_text = "ХОД ИГРОКА 1"
            else:
                turn_text = "ХОД ИГРОКА 2"
            turn_color = (255, 255, 255)

        text_surf = self.font_large.render(turn_text, True, turn_color)
        self.screen.blit(text_surf, (20, 10))

        score_text = f"{my_name}: {my_score} | {opp_name}: {opp_score}"
        score_surf = self.font_small.render(score_text, True, CONFIG["colors"]["text"])
        self.screen.blit(score_surf, (20, 50))

    #Отрисовка сообщения о пропуске хода
    def draw_skip_turn_message(self):
        if self.skip_turn_message and self.skip_turn_timer > 0:
            # Полупрозрачный фон
            overlay = pygame.Surface((CONFIG["window_width"], 100))
            overlay.set_alpha(180)
            overlay.fill((0, 0, 0))
            self.screen.blit(overlay, (0, 100))

            # Текст сообщения
            text_surf = self.font_medium.render(self.skip_turn_message, True, (255, 255, 100))
            text_rect = text_surf.get_rect(center=(CONFIG["window_width"] // 2, 150))
            self.screen.blit(text_surf, text_rect)

    def add_animation(self, x, y, color):
        self.animations.append(Animation(x, y, color, CONFIG["cell_size"] // 2 - 5))

    def update_animations(self):
        for anim in self.animations[:]:
            anim.update()
            anim.draw(self.screen)
            if anim.finished:
                self.animations.remove(anim)
        return len(self.animations) > 0

    def update_skip_turn_timer(self, dt):
        if self.skip_turn_timer > 0:
            self.skip_turn_timer -= dt
            if self.skip_turn_timer <= 0:
                self.skip_turn_message = ""

    def show_skip_turn_message(self, player):
        player_name = "Игрок 1" if player == 1 else "Игрок 2"
        if self.game_mode == "online":
            player_name = "Вы" if player == self.my_color else "Игрок 2"
        self.skip_turn_message = f"{player_name} пропускает ход (нет доступных ходов)!"
        self.skip_turn_timer = 3.0  # Показывать 3 секунды

    def rotate_board_for_player(self):
        if self.game_mode == "local":
            if self.logic.current_player == 1:
                self.rotation_angle = 0
            else:
                self.rotation_angle = 180
        elif self.game_mode == "online":
            if self.my_color == 1:
                self.rotation_angle = 0
            else:
                self.rotation_angle = 180

    def draw_waiting(self, message):
        overlay = pygame.Surface((CONFIG["window_width"], CONFIG["window_height"]))
        overlay.set_alpha(200)
        overlay.fill((0, 0, 0))
        self.screen.blit(overlay, (0, 0))

        text = self.font_large.render(message, True, (255, 255, 255))
        rect = text.get_rect(center=(CONFIG["window_width"] // 2, CONFIG["window_height"] // 2))
        self.screen.blit(text, rect)

    def draw_chat_input(self, chat_input):
        pygame.draw.rect(self.screen, (50, 50, 50), (20, 570, 400, 25))
        text_surf = self.font_small.render(chat_input, True, (255, 255, 255))
        self.screen.blit(text_surf, (25, 573))