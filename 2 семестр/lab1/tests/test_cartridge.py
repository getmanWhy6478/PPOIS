import unittest
from cartridge import InkCartridge
from exceptions import PrinterException
from interfaces import IConsumable


class TestInkCartridge(unittest.TestCase):
    """Тесты класса InkCartridge"""

    # ========================================
    # Фикстуры (вспомогательные методы)
    # ========================================

    def create_full_cartridge(self):
        """Создание полного картриджа"""
        return InkCartridge('C', 10.0, 10.0)

    def create_half_cartridge(self):
        """Создание наполовину заполненного картриджа"""
        return InkCartridge('M', 10.0, 5.0)

    def create_empty_cartridge(self):
        """Создание пустого картриджа"""
        return InkCartridge('K', 10.0, 0.0)

    # ========================================
    # Инициализация
    # ========================================

    def test_create_valid_cartridge(self):
        """Тест: успешное создание картриджа"""
        cartridge = InkCartridge('Y', 10.0, 8.5)

        self.assertEqual(cartridge.color, 'Y')
        self.assertEqual(cartridge.capacity, 10.0)
        self.assertEqual(cartridge.level, 8.5)
        self.assertEqual(cartridge.level_percent, 85.0)
        self.assertFalse(cartridge.is_empty)

    def test_default_level_is_full(self):
        """Тест: по умолчанию картридж полный"""
        cartridge = InkCartridge('K', 15.0)

        self.assertEqual(cartridge.level, 15.0)
        self.assertEqual(cartridge.level_percent, 100.0)

    def test_color_case_insensitive_lowercase(self):
        """Тест: цвет преобразуется в верхний регистр (строчные)"""
        cartridge = InkCartridge('c', 10.0)
        self.assertEqual(cartridge.color, 'C')

    def test_color_case_insensitive_mixed(self):
        """Тест: цвет преобразуется в верхний регистр (смешанный)"""
        cartridge = InkCartridge('m', 10.0)
        self.assertEqual(cartridge.color, 'M')

    def test_invalid_color_raises_error(self):
        """Тест: некорректный цвет вызывает исключение"""
        with self.assertRaises(ValueError) as context:
            InkCartridge('R', 10.0)

        self.assertIn("Недопустимый цвет чернил", str(context.exception))

    def test_invalid_color_message_contains_color(self):
        """Тест: сообщение об ошибке содержит недопустимый цвет"""
        with self.assertRaises(ValueError) as context:
            InkCartridge('RED', 10.0)

        self.assertIn('RED', str(context.exception))

    def test_all_valid_colors_work(self):
        """Тест: все допустимые цвета работают"""
        valid_colors = ['C', 'M', 'Y', 'K']

        for color in valid_colors:
            with self.subTest(color=color):
                cartridge = InkCartridge(color, 10.0)
                self.assertEqual(cartridge.color, color)

    def test_minimum_capacity(self):
        """Тест: минимальная ёмкость = 0.01"""
        cartridge = InkCartridge('M', -5.0)
        self.assertEqual(cartridge.capacity, 0.01)

    # ========================================
    # Свойства (только для чтения)
    # ========================================

    def test_properties_readonly(self):
        """Тест: свойства доступны только для чтения"""
        full_cartridge = self.create_full_cartridge()

        with self.assertRaises(AttributeError):
            full_cartridge.color = 'M'

        with self.assertRaises(AttributeError):
            full_cartridge.capacity = 20.0

        with self.assertRaises(AttributeError):
            full_cartridge.level = 8.0

    # ========================================
    # Метод consume()
    # ========================================

    def test_consume_valid_amount(self):
        """Тест: корректное потребление чернил"""
        full_cartridge = self.create_full_cartridge()
        full_cartridge.consume(2.5)

        self.assertEqual(full_cartridge.level, 7.5)
        self.assertEqual(full_cartridge.level_percent, 75.0)

    def test_consume_multiple_times(self):
        """Тест: многократное потребление чернил"""
        cartridge = InkCartridge('C', 10.0, 10.0)

        cartridge.consume(2.0)
        cartridge.consume(3.0)
        cartridge.consume(1.5)

        self.assertEqual(cartridge.level, 3.5)
        self.assertEqual(cartridge.level_percent, 35.0)

    def test_consume_zero_raises_error(self):
        """Тест: потребление нулевого количества вызывает исключение"""
        half_cartridge = self.create_half_cartridge()

        with self.assertRaises(ValueError) as context:
            half_cartridge.consume(0)

        self.assertIn("Количество чернил должно быть положительным", str(context.exception))

    def test_consume_negative_raises_error(self):
        """Тест: потребление отрицательного количества вызывает исключение"""
        half_cartridge = self.create_half_cartridge()

        with self.assertRaises(ValueError) as context:
            half_cartridge.consume(-1.0)

        self.assertIn("Количество чернил должно быть положительным", str(context.exception))

    def test_consume_from_empty_cartridge_raises_error(self):
        """Тест: потребление из пустого картриджа вызывает исключение"""
        empty_cartridge = self.create_empty_cartridge()

        with self.assertRaises(PrinterException) as context:
            empty_cartridge.consume(1.0)

        self.assertIn("K", str(context.exception))

    def test_consume_makes_cartridge_empty(self):
        """Тест: потребление до нуля делает картридж пустым"""
        cartridge = InkCartridge('C', 10.0, 2.0)
        cartridge.consume(2.0)

        self.assertEqual(cartridge.level, 0.0)
        self.assertTrue(cartridge.is_empty)

    def test_consume_exact_remaining_amount(self):
        """Тест: потребление точного оставшегося количества"""
        cartridge = InkCartridge('K', 10.0, 3.7)
        cartridge.consume(3.7)

        self.assertEqual(cartridge.level, 0.0)
        self.assertTrue(cartridge.is_empty)

    def test_consume_more_than_available(self):
        """Тест: потребление больше, чем доступно (уровень не может быть отрицательным)"""
        cartridge = InkCartridge('C', 10.0, 2.0)
        cartridge.consume(5.0)

        self.assertEqual(cartridge.level, 0.0)
        self.assertTrue(cartridge.is_empty)

    # ========================================
    # Метод refill()
    # ========================================

    def test_refill_fills_to_capacity(self):
        """Тест: заправка восстанавливает полную ёмкость"""
        half_cartridge = self.create_half_cartridge()
        half_cartridge.refill()

        self.assertEqual(half_cartridge.level, 10.0)
        self.assertEqual(half_cartridge.level_percent, 100.0)

    def test_refill_empty_cartridge(self):
        """Тест: заправка пустого картриджа"""
        empty_cartridge = self.create_empty_cartridge()
        empty_cartridge.refill()

        self.assertEqual(empty_cartridge.level, 10.0)
        self.assertFalse(empty_cartridge.is_empty)

    def test_refill_partial_cartridge(self):
        """Тест: заправка частично заполненного картриджа"""
        cartridge = InkCartridge('K', 20.0, 12.5)
        cartridge.refill()

        self.assertEqual(cartridge.level, 20.0)
        self.assertEqual(cartridge.level_percent, 100.0)

    # ========================================
    # Свойство is_empty
    # ========================================

    def test_is_empty_threshold_zero(self):
        """Тест: пороговое значение для определения пустоты (0.0)"""
        cartridge = InkCartridge('C', 10.0)
        cartridge._level = 0.0

        self.assertTrue(cartridge.is_empty)

    def test_is_empty_threshold_below(self):
        """Тест: пороговое значение для определения пустоты (ниже 0.01)"""
        cartridge = InkCartridge('C', 10.0)
        cartridge._level = 0.005

        self.assertTrue(cartridge.is_empty)

    def test_is_empty_threshold_equal(self):
        """Тест: пороговое значение для определения пустоты (равно 0.01)"""
        cartridge = InkCartridge('C', 10.0)
        cartridge._level = 0.01

        self.assertTrue(cartridge.is_empty)

    def test_is_empty_threshold_above(self):
        """Тест: пороговое значение для определения пустоты (выше 0.01)"""
        cartridge = InkCartridge('C', 10.0)
        cartridge._level = 0.015

        self.assertFalse(cartridge.is_empty)

    def test_is_empty_when_level_zero(self):
        """Тест: картридж пуст при уровне 0"""
        cartridge = InkCartridge('C', 10.0, 0.0)
        self.assertTrue(cartridge.is_empty)

    def test_is_not_empty_when_full(self):
        """Тест: картридж не пуст когда полный"""
        cartridge = InkCartridge('K', 10.0, 10.0)
        self.assertFalse(cartridge.is_empty)

    # ========================================
    # Свойство level_percent
    # ========================================

    def test_level_percent_zero(self):
        """Тест: процент заполнения для пустого картриджа"""
        cartridge = InkCartridge('M', 10.0)
        cartridge._level = 0.0

        self.assertEqual(cartridge.level_percent, 0.0)

    def test_level_percent_10_percent(self):
        """Тест: процент заполнения 10%"""
        cartridge = InkCartridge('M', 10.0)
        cartridge._level = 1.0

        self.assertEqual(cartridge.level_percent, 10.0)

    def test_level_percent_25_percent(self):
        """Тест: процент заполнения 25%"""
        cartridge = InkCartridge('M', 10.0)
        cartridge._level = 2.5

        self.assertEqual(cartridge.level_percent, 25.0)

    def test_level_percent_50_percent(self):
        """Тест: процент заполнения 50%"""
        cartridge = InkCartridge('M', 10.0)
        cartridge._level = 5.0

        self.assertEqual(cartridge.level_percent, 50.0)

    def test_level_percent_75_percent(self):
        """Тест: процент заполнения 75%"""
        cartridge = InkCartridge('M', 10.0)
        cartridge._level = 7.5

        self.assertEqual(cartridge.level_percent, 75.0)

    def test_level_percent_100_percent(self):
        """Тест: процент заполнения 100%"""
        cartridge = InkCartridge('M', 10.0)
        cartridge._level = 10.0

        self.assertEqual(cartridge.level_percent, 100.0)

    def test_level_percent_rounding(self):
        """Тест: округление процента заполнения до 1 знака"""
        cartridge = InkCartridge('K', 10.0)
        cartridge._level = 3.333

        self.assertEqual(cartridge.level_percent, 33.3)

    # ========================================
    # Реализация интерфейса IConsumable
    # ========================================

    def test_implements_iconsumable(self):
        """Тест: класс реализует интерфейс IConsumable"""
        cartridge = InkCartridge('C', 10.0)

        self.assertIsInstance(cartridge, IConsumable)
        self.assertTrue(hasattr(cartridge, 'consume'))
        self.assertTrue(hasattr(cartridge, 'refill'))
        self.assertTrue(hasattr(cartridge, 'is_empty'))

    # ========================================
    # Граничные значения
    # ========================================

    def test_large_capacity_cartridge(self):
        """Тест: картридж с большой ёмкостью"""
        cartridge = InkCartridge('M', 1000.0, 500.0)

        self.assertEqual(cartridge.capacity, 1000.0)
        self.assertEqual(cartridge.level, 500.0)
        self.assertEqual(cartridge.level_percent, 50.0)

    def test_very_small_capacity(self):
        """Тест: очень маленькая ёмкость"""
        cartridge = InkCartridge('Y', 0.01, 0.01)

        self.assertEqual(cartridge.capacity, 0.01)
        self.assertEqual(cartridge.level, 0.01)
        self.assertEqual(cartridge.level_percent, 100.0)

    # ========================================
    # Интеграционные тесты
    # ========================================

    def test_full_workflow(self):
        """Тест: полный цикл использования картриджа"""
        cartridge = InkCartridge('C', 10.0, 10.0)

        # Печатаем
        cartridge.consume(3.0)
        self.assertEqual(cartridge.level, 7.0)
        self.assertEqual(cartridge.level_percent, 70.0)

        # Печатаем ещё
        cartridge.consume(4.0)
        self.assertEqual(cartridge.level, 3.0)
        self.assertEqual(cartridge.level_percent, 30.0)

        # Заправляем
        cartridge.refill()
        self.assertEqual(cartridge.level, 10.0)
        self.assertEqual(cartridge.level_percent, 100.0)

        # Печатаем до конца
        cartridge.consume(10.0)
        self.assertEqual(cartridge.level, 0.0)
        self.assertTrue(cartridge.is_empty)

    def test_cannot_consume_after_empty(self):
        """Тест: нельзя печатать после опустошения картриджа"""
        cartridge = InkCartridge('K', 5.0, 5.0)

        cartridge.consume(5.0)
        self.assertTrue(cartridge.is_empty)

        with self.assertRaises(PrinterException):
            cartridge.consume(0.1)


if __name__ == '__main__':
    unittest.main(verbosity=2)