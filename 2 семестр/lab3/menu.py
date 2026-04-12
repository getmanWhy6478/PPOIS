import pygame
from config import CONFIG


class Menu:
    def __init__(self, screen):
        self.screen = screen
        self.font_large = pygame.font.SysFont('Arial', 40, bold=True)
        self.font_small = pygame.font.SysFont('Arial', 20)
        self.buttons = []

    def create_main_menu(self):
        """Создаёт кнопки главного меню"""
        self.buttons = [
            {"text": "Начать игру (Локально)", "rect": pygame.Rect(300, 150, 200, 50), "action": "play_local"},
            {"text": "Онлайн игра", "rect": pygame.Rect(300, 220, 200, 50), "action": "play_online"},
            {"text": "Таблица рекордов", "rect": pygame.Rect(300, 290, 200, 50), "action": "leaderboard"},
            {"text": "Справка", "rect": pygame.Rect(300, 360, 200, 50), "action": "help"},
            {"text": "Выход", "rect": pygame.Rect(300, 430, 200, 50), "action": "quit"}
        ]

    def create_online_menu(self):
        """Создаёт кнопки меню онлайн-игры"""
        self.buttons = [
            {"text": "Найти игру", "rect": pygame.Rect(300, 200, 200, 50), "action": "find_game"},
            {"text": "Назад", "rect": pygame.Rect(300, 450, 200, 50), "action": "back"}  # ← Исправлено: y=450
        ]

    def draw(self):
        """Отрисовывает кнопки меню"""
        mouse_pos = pygame.mouse.get_pos()
        for button in self.buttons:
            if button["rect"].collidepoint(mouse_pos):
                color = (100, 255, 100)  # Светло-зелёный при наведении
            else:
                color = (50, 150, 50)  # Тёмно-зелёный

            pygame.draw.rect(self.screen, color, button["rect"])
            pygame.draw.rect(self.screen, (255, 255, 255), button["rect"], 2)

            text_surf = self.font_small.render(button["text"], True, CONFIG["colors"]["text"])
            text_rect = text_surf.get_rect(center=button["rect"].center)
            self.screen.blit(text_surf, text_rect)

    def handle_click(self, pos):
        """Обрабатывает клик по кнопке и возвращает action"""
        for button in self.buttons:
            if button["rect"].collidepoint(pos):
                print(f"Кнопка нажата: {button['text']} (action={button['action']})")  # ← Отладка
                return button["action"]
        return None

    def draw_help(self):
        """Отрисовывает справку"""
        rules = [
            "ПРАВИЛА ИГРЫ:",
            "1. Чёрные ходят первыми.",
            "2. Поставьте шашку так, чтобы между ней",
            "   и вашей шашкой были шашки противника.",
            "3. Все шашки противника переворачиваются.",
            "4. Если ходов нет - ход переходит сопернику.",
            "5. Побеждает тот, у кого больше шашек.",
            "",
            "ЛОКАЛЬНАЯ ИГРА:",
            "- Доска переворачивается после каждого хода",
            "- Игра на одном экране для двух игроков",
            "",
            "ОНЛАЙН ИГРА:",
            "- Запустите server.py перед игрой",
            "- Доска зафиксирована под ваш цвет",
            "- Используйте чат для общения (Enter)",
            "",
            "Нажмите ESC для возврата"
        ]

        y = 50
        for line in rules:
            surf = self.font_small.render(line, True, CONFIG["colors"]["text"])
            self.screen.blit(surf, (100, y))
            y += 35

    def draw_leaderboard(self, scores):
        """Отрисовывает таблицу рекордов"""
        title = self.font_large.render("ТАБЛИЦА РЕКОРДОВ", True, CONFIG["colors"]["text"])
        self.screen.blit(title, (250, 50))

        y = 150
        for i, entry in enumerate(scores, 1):
            line = f"{i}. {entry['name']}: {entry['score']}"
            surf = self.font_small.render(line, True, CONFIG["colors"]["text"])
            self.screen.blit(surf, (300, y))
            y += 40

        back = self.font_small.render("Нажмите ESC для возврата", True, (200, 200, 200))
        self.screen.blit(back, (280, 500))

    def draw_input_name(self, input_text):
        """Отрисовывает ввод имени для рекорда"""
        msg = self.font_large.render("НОВЫЙ РЕКОРД!", True, (255, 215, 0))
        self.screen.blit(msg, (250, 150))

        prompt = self.font_small.render("Введите имя:", True, CONFIG["colors"]["text"])
        self.screen.blit(prompt, (250, 250))

        pygame.draw.rect(self.screen, (255, 255, 255), (250, 300, 300, 40))
        text_surf = self.font_small.render(input_text, True, (0, 0, 0))
        self.screen.blit(text_surf, (260, 310))

        hint = self.font_small.render("Нажмите Enter для сохранения", True, (150, 150, 150))
        self.screen.blit(hint, (250, 360))