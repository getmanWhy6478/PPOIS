import unittest
from paper import Paper
from interfaces import IConsumable


class TestPaper(unittest.TestCase):
    """Тесты класса Paper"""

    # ========================================
    # Вспомогательные методы (вместо фикстур)
    # ========================================

    def create_default_paper(self):
        """Создание бумаги по умолчанию (A4, 100 листов)"""
        return Paper()

    def create_custom_paper(self):
        """Создание пользовательской бумаги (PHOTO, 50 листов)"""
        return Paper('PHOTO', 50)

    def create_empty_paper(self):
        """Создание пустого лотка бумаги"""
        return Paper('A4', 0)

    # ========================================
    # Тесты инициализации
    # ========================================

    def test_default_initialization(self):
        """Тест: инициализация по умолчанию"""
        paper = Paper()

        self.assertEqual(paper.type, 'A4')
        self.assertEqual(paper.quantity, 100)
        self.assertFalse(paper.is_empty)

    def test_custom_initialization(self):
        """Тест: инициализация с пользовательскими параметрами"""
        paper = Paper('A3', 200)

        self.assertEqual(paper.type, 'A3')
        self.assertEqual(paper.quantity, 200)
        self.assertFalse(paper.is_empty)

    def test_type_case_insensitive(self):
        """Тест: тип бумаги преобразуется в верхний регистр"""
        paper = Paper('a4', 100)
        self.assertEqual(paper.type, 'A4')

    def test_invalid_type_raises_error(self):
        """Тест: недопустимый тип бумаги вызывает исключение"""
        with self.assertRaises(ValueError) as context:
            Paper('B5', 100)

        self.assertIn("Недопустимый тип бумаги", str(context.exception))

    def test_invalid_type_message_contains_type(self):
        """Тест: сообщение об ошибке содержит недопустимый тип"""
        with self.assertRaises(ValueError) as context:
            Paper('INVALID', 100)

        self.assertIn('INVALID', str(context.exception))

    def test_all_valid_types_work(self):
        """Тест: все допустимые типы бумаги работают"""
        valid_types = ['A4', 'A3', 'PHOTO', 'LETTER']

        for paper_type in valid_types:
            with self.subTest(paper_type=paper_type):
                paper = Paper(paper_type, 100)
                self.assertEqual(paper.type, paper_type)

    def test_negative_quantity_becomes_zero(self):
        """Тест: отрицательное количество становится нулём"""
        paper = Paper('A4', -50)
        self.assertEqual(paper.quantity, 0)
        self.assertTrue(paper.is_empty)

    def test_zero_quantity(self):
        """Тест: нулевое количество"""
        paper = Paper('A4', 0)
        self.assertEqual(paper.quantity, 0)
        self.assertTrue(paper.is_empty)

    # ========================================
    # Тесты свойств
    # ========================================

    def test_properties_readonly(self):
        """Тест: свойства доступны только для чтения"""
        default_paper = self.create_default_paper()

        with self.assertRaises(AttributeError):
            default_paper.type = 'A3'

        with self.assertRaises(AttributeError):
            default_paper.quantity = 200

    def test_properties_return_correct_values(self):
        """Тест: свойства возвращают корректные значения"""
        custom_paper = self.create_custom_paper()

        self.assertEqual(custom_paper.type, 'PHOTO')
        self.assertEqual(custom_paper.quantity, 50)
        self.assertFalse(custom_paper.is_empty)

    # ========================================
    # Тесты метода consume()
    # ========================================

    def test_consume_default_amount(self):
        """Тест: потребление бумаги по умолчанию (1 лист)"""
        default_paper = self.create_default_paper()
        initial_quantity = default_paper.quantity
        default_paper.consume()

        self.assertEqual(default_paper.quantity, initial_quantity - 1)

    def test_consume_custom_amount(self):
        """Тест: потребление указанного количества листов"""
        default_paper = self.create_default_paper()
        initial_quantity = default_paper.quantity
        default_paper.consume(5)

        self.assertEqual(default_paper.quantity, initial_quantity - 5)

    def test_consume_multiple_times(self):
        """Тест: многократное потребление бумаги"""
        paper = Paper('A4', 10)

        paper.consume(3)
        self.assertEqual(paper.quantity, 7)

        paper.consume(2)
        self.assertEqual(paper.quantity, 5)

        paper.consume(5)
        self.assertEqual(paper.quantity, 0)
        self.assertTrue(paper.is_empty)

    def test_consume_makes_paper_empty(self):
        """Тест: потребление до нуля делает лоток пустым"""
        paper = Paper('A4', 5)
        paper.consume(5)

        self.assertEqual(paper.quantity, 0)
        self.assertTrue(paper.is_empty)

    def test_consume_zero_raises_error(self):
        """Тест: потребление нулевого количества вызывает исключение"""
        default_paper = self.create_default_paper()

        with self.assertRaises(ValueError) as context:
            default_paper.consume(0)

        self.assertIn("Количество должно быть положительным", str(context.exception))

    def test_consume_negative_raises_error(self):
        """Тест: потребление отрицательного количества вызывает исключение"""
        default_paper = self.create_default_paper()

        with self.assertRaises(ValueError) as context:
            default_paper.consume(-1)

        self.assertIn("Количество должно быть положительным", str(context.exception))

    def test_consume_more_than_available(self):
        """Тест: потребление больше, чем доступно (количество не может быть отрицательным)"""
        paper = Paper('A4', 5)
        paper.consume(10)

        self.assertEqual(paper.quantity, 0)
        self.assertTrue(paper.is_empty)

    def test_consume_exact_remaining_amount(self):
        """Тест: потребление точного оставшегося количества"""
        paper = Paper('A4', 7)
        paper.consume(7)

        self.assertEqual(paper.quantity, 0)
        self.assertTrue(paper.is_empty)

    # ========================================
    # Тесты метода refill()
    # ========================================

    def test_refill_increases_quantity(self):
        """Тест: заполнение увеличивает количество"""
        default_paper = self.create_default_paper()
        initial_quantity = default_paper.quantity
        default_paper.refill(50)

        self.assertEqual(default_paper.quantity, initial_quantity + 50)

    def test_refill_empty_paper(self):
        """Тест: заполнение пустого лотка"""
        empty_paper = self.create_empty_paper()
        empty_paper.refill(100)

        self.assertEqual(empty_paper.quantity, 100)
        self.assertFalse(empty_paper.is_empty)

    def test_refill_partial_paper(self):
        """Тест: заполнение частично заполненного лотка"""
        paper = Paper('A4', 30)
        paper.refill(70)

        self.assertEqual(paper.quantity, 100)

    def test_multiple_refills(self):
        """Тест: многократное заполнение"""
        paper = Paper('A4', 0)

        paper.refill(50)
        self.assertEqual(paper.quantity, 50)

        paper.refill(30)
        self.assertEqual(paper.quantity, 80)

        paper.refill(20)
        self.assertEqual(paper.quantity, 100)

    def test_refill_zero_raises_error(self):
        """Тест: заполнение нулевым количеством вызывает исключение"""
        default_paper = self.create_default_paper()

        with self.assertRaises(ValueError) as context:
            default_paper.refill(0)

        self.assertIn("Количество для заполнения должно быть положительным", str(context.exception))

    def test_refill_negative_raises_error(self):
        """Тест: заполнение отрицательным количеством вызывает исключение"""
        default_paper = self.create_default_paper()

        with self.assertRaises(ValueError) as context:
            default_paper.refill(-10)

        self.assertIn("Количество для заполнения должно быть положительным", str(context.exception))

    def test_refill_large_quantity(self):
        """Тест: заполнение большим количеством"""
        paper = Paper('A4', 0)
        paper.refill(10000)

        self.assertEqual(paper.quantity, 10000)

    # ========================================
    # Тесты свойства is_empty
    # ========================================

    def test_is_empty_threshold_negative_10(self):
        """Тест: пороговое значение для определения пустоты (-10)"""
        paper = Paper('A4', -10)
        self.assertTrue(paper.is_empty)

    def test_is_empty_threshold_negative_1(self):
        """Тест: пороговое значение для определения пустоты (-1)"""
        paper = Paper('A4', -1)
        self.assertTrue(paper.is_empty)

    def test_is_empty_threshold_zero(self):
        """Тест: пороговое значение для определения пустоты (0)"""
        paper = Paper('A4', 0)
        self.assertTrue(paper.is_empty)

    def test_is_empty_threshold_one(self):
        """Тест: пороговое значение для определения пустоты (1)"""
        paper = Paper('A4', 1)
        self.assertFalse(paper.is_empty)

    def test_is_empty_threshold_ten(self):
        """Тест: пороговое значение для определения пустоты (10)"""
        paper = Paper('A4', 10)
        self.assertFalse(paper.is_empty)

    def test_is_empty_threshold_hundred(self):
        """Тест: пороговое значение для определения пустоты (100)"""
        paper = Paper('A4', 100)
        self.assertFalse(paper.is_empty)

    def test_is_empty_after_consume_to_zero(self):
        """Тест: лоток становится пустым после потребления до нуля"""
        paper = Paper('A4', 5)
        paper.consume(5)
        self.assertTrue(paper.is_empty)

    def test_is_not_empty_after_refill(self):
        """Тест: лоток не пуст после заполнения"""
        empty_paper = self.create_empty_paper()
        empty_paper.refill(1)
        self.assertFalse(empty_paper.is_empty)

    # ========================================
    # Тесты реализации интерфейса IConsumable
    # ========================================

    def test_implements_iconsumable(self):
        """Тест: класс реализует интерфейс IConsumable"""
        paper = Paper('A4', 100)

        self.assertIsInstance(paper, IConsumable)
        self.assertTrue(hasattr(paper, 'consume'))
        self.assertTrue(hasattr(paper, 'refill'))
        self.assertTrue(hasattr(paper, 'is_empty'))

    def test_interface_methods_signature(self):
        """Тест: сигнатуры методов интерфейса"""
        default_paper = self.create_default_paper()

        # Проверяем, что методы вызываются без ошибок
        default_paper.consume(1)
        default_paper.refill(10)
        self.assertIsInstance(default_paper.is_empty, bool)

    # ========================================
    # Интеграционные тесты
    # ========================================

    def test_full_workflow(self):
        """Тест: полный цикл использования бумаги"""
        paper = Paper('A4', 100)

        # Печатаем несколько страниц
        paper.consume(10)
        self.assertEqual(paper.quantity, 90)

        # Печатаем ещё
        paper.consume(30)
        self.assertEqual(paper.quantity, 60)

        # Заполняем
        paper.refill(40)
        self.assertEqual(paper.quantity, 100)

        # Печатаем всё
        paper.consume(100)
        self.assertEqual(paper.quantity, 0)
        self.assertTrue(paper.is_empty)

        # Заполняем снова
        paper.refill(50)
        self.assertEqual(paper.quantity, 50)
        self.assertFalse(paper.is_empty)

    def test_alternating_consume_and_refill(self):
        """Тест: чередование потребления и заполнения"""
        paper = Paper('A4', 50)

        paper.consume(20)
        self.assertEqual(paper.quantity, 30)

        paper.refill(10)
        self.assertEqual(paper.quantity, 40)

        paper.consume(15)
        self.assertEqual(paper.quantity, 25)

        paper.refill(25)
        self.assertEqual(paper.quantity, 50)

    # ========================================
    # Тесты с разными типами бумаги
    # ========================================

    def test_different_paper_types(self):
        """Тест: работа с разными типами бумаги"""
        test_cases = [
            ('A4', 100),
            ('A3', 50),
            ('PHOTO', 20),
            ('LETTER', 75),
        ]

        for paper_type, quantity in test_cases:
            with self.subTest(paper_type=paper_type, quantity=quantity):
                paper = Paper(paper_type, quantity)

                self.assertEqual(paper.type, paper_type)
                self.assertEqual(paper.quantity, quantity)

                # Потребляем
                paper.consume(10)
                self.assertEqual(paper.quantity, quantity - 10)

                # Заполняем
                paper.refill(10)
                self.assertEqual(paper.quantity, quantity)

    # ========================================
    # Тесты граничных значений
    # ========================================

    def test_consume_single_sheet(self):
        """Тест: потребление одного листа"""
        paper = Paper('A4', 1)
        paper.consume()

        self.assertEqual(paper.quantity, 0)
        self.assertTrue(paper.is_empty)

    def test_refill_single_sheet(self):
        """Тест: заполнение одним листом"""
        empty_paper = self.create_empty_paper()
        empty_paper.refill(1)

        self.assertEqual(empty_paper.quantity, 1)
        self.assertFalse(empty_paper.is_empty)

    def test_large_initial_quantity(self):
        """Тест: большое начальное количество"""
        paper = Paper('A4', 10000)

        self.assertEqual(paper.quantity, 10000)
        self.assertFalse(paper.is_empty)

        paper.consume(5000)
        self.assertEqual(paper.quantity, 5000)

    def test_consume_all_at_once(self):
        """Тест: потребление всего сразу"""
        paper = Paper('A4', 100)
        paper.consume(100)

        self.assertEqual(paper.quantity, 0)
        self.assertTrue(paper.is_empty)

    # ========================================
    # Тесты исключений
    # ========================================

    def test_value_error_message_format(self):
        """Тест: формат сообщения об ошибке для недопустимого типа"""
        with self.assertRaises(ValueError) as context:
            Paper('INVALID', 100)

        self.assertIn("Недопустимый тип бумаги", str(context.exception))


if __name__ == '__main__':
    unittest.main(verbosity=2)