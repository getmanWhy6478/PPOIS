import unittest
from unittest.mock import Mock
from printer import Printer, PrinterState
from document import Document
from settings import PrintSettings
from exceptions import (
    OutOfPaperError, LowInkError, HardwareError, PrinterException
)
from interfaces import IDriver, IPrintable


class TestPrinter(unittest.TestCase):
    """Тесты класса Printer"""

    # ========================================
    # Вспомогательные методы (вместо фикстур)
    # ========================================

    def create_mock_driver(self):
        """Создание мок-драйвера"""
        driver = Mock(spec=IDriver)
        driver.initialize.return_value = True
        driver.send_print_command.return_value = True
        driver.run_maintenance.return_value = True
        return driver

    def create_printer(self):
        """Создание принтера с мок-драйвером"""
        driver = self.create_mock_driver()
        return Printer("TestPrinter", driver)

    def create_initialized_printer(self):
        """Создание включённого принтера"""
        printer = self.create_printer()
        printer.power_on()
        return printer

    def create_document(self):
        """Создание документа для печати"""
        return Document("test.pdf", "PDF", 5, 2.5)

    def create_default_settings(self):
        """Создание настроек по умолчанию"""
        return PrintSettings()

    # ========================================
    # Тесты инициализации
    # ========================================

    def test_init_creates_printer(self):
        """Тест: создание принтера"""
        driver = self.create_mock_driver()
        printer = Printer("MyPrinter", driver)

        self.assertEqual(printer.model, "MyPrinter")
        self.assertEqual(printer.state, PrinterState.OFF)
        self.assertEqual(printer.paper.quantity, 100)
        self.assertEqual(len(printer.cartridges), 4)
        colors = {c.color for c in printer.cartridges}
        self.assertEqual(colors, {'C', 'M', 'Y', 'K'})

    def test_init_creates_default_cartridges(self):
        """Тест: создание картриджей по умолчанию"""
        printer = self.create_printer()

        self.assertEqual(len(printer._cartridges), 4)
        colors = {c.color for c in printer._cartridges}
        self.assertEqual(colors, {'C', 'M', 'Y', 'K'})

    def test_init_sets_maintenance_count_to_zero(self):
        """Тест: счётчик обслуживания равен нулю"""
        printer = self.create_printer()
        self.assertEqual(printer._maintenance_count, 0)

    # ========================================
    # Тесты свойств
    # ========================================

    def test_model_property(self):
        """Тест: свойство model"""
        printer = self.create_printer()
        self.assertEqual(printer.model, "TestPrinter")

    def test_state_property(self):
        """Тест: свойство state"""
        printer = self.create_printer()
        self.assertEqual(printer.state, PrinterState.OFF)

    def test_paper_property(self):
        """Тест: свойство paper"""
        printer = self.create_printer()
        self.assertEqual(printer.paper.quantity, 100)
        self.assertEqual(printer.paper.type, "A4")

    def test_cartridges_property_returns_copy(self):
        """Тест: свойство cartridges возвращает копию"""
        printer = self.create_printer()
        cartridges1 = printer.cartridges
        cartridges2 = printer.cartridges

        self.assertIsNot(cartridges1, cartridges2)
        self.assertEqual(len(cartridges1), len(cartridges2))
        self.assertEqual(len(cartridges1), 4)

    def test_properties_readonly(self):
        """Тест: свойства только для чтения"""
        printer = self.create_printer()

        with self.assertRaises(AttributeError):
            printer.model = "NewModel"

        with self.assertRaises(AttributeError):
            printer.state = PrinterState.IDLE

    # ========================================
    # Тесты power_on()
    # ========================================

    def test_power_on_from_off(self):
        """Тест: включение из состояния OFF"""
        printer = self.create_printer()
        driver = printer._driver

        result = printer.power_on()

        self.assertTrue(result)
        self.assertEqual(printer.state, PrinterState.IDLE)
        driver.initialize.assert_called_once()

    def test_power_on_when_already_on(self):
        """Тест: повторное включение возвращает False"""
        printer = self.create_initialized_printer()
        result = printer.power_on()
        self.assertFalse(result)

    def test_power_on_with_empty_paper(self):
        """Тест: включение с пустым лотком бумаги"""
        printer = self.create_printer()
        printer._paper._quantity = 0

        result = printer.power_on()

        self.assertTrue(result)
        self.assertEqual(printer.state, PrinterState.OUT_OF_PAPER)

    def test_power_on_with_low_ink(self):
        """Тест: включение с низким уровнем чернил"""
        printer = self.create_printer()
        # Уменьшаем уровень чернил в одном картридже
        printer._cartridges[0]._level = 0.5  # 5% от 10.0

        result = printer.power_on()

        self.assertTrue(result)
        self.assertEqual(printer.state, PrinterState.LOW_INK)

    def test_power_on_driver_initialization_fails(self):
        """Тест: включение при неудачной инициализации драйвера"""
        printer = self.create_printer()
        driver = printer._driver
        driver.initialize.return_value = False

        result = printer.power_on()

        self.assertFalse(result)
        self.assertEqual(printer.state, PrinterState.ERROR)

    def test_power_on_driver_raises_exception(self):
        """Тест: включение при исключении драйвера"""
        printer = self.create_printer()
        driver = printer._driver
        driver.initialize.side_effect = Exception("Driver error")

        with self.assertRaises(HardwareError):
            printer.power_on()

        self.assertEqual(printer.state, PrinterState.ERROR)

    # ========================================
    # Тесты power_off()
    # ========================================

    def test_power_off_from_idle(self):
        """Тест: выключение из состояния IDLE"""
        printer = self.create_initialized_printer()

        result = printer.power_off()

        self.assertTrue(result)
        self.assertEqual(printer.state, PrinterState.OFF)

    def test_power_off_when_already_off(self):
        """Тест: повторное выключение возвращает False"""
        printer = self.create_printer()
        result = printer.power_off()
        self.assertFalse(result)

    def test_power_off_from_other_states(self):
        """Тест: выключение из разных состояний"""
        printer = self.create_printer()
        states = [PrinterState.PRINTING, PrinterState.OUT_OF_PAPER,
                  PrinterState.LOW_INK, PrinterState.ERROR]

        for state in states:
            with self.subTest(state=state.value):
                printer._state = state
                result = printer.power_off()
                self.assertTrue(result)
                self.assertEqual(printer.state, PrinterState.OFF)

    # ========================================
    # Тесты print_document()
    # ========================================

    def test_print_document_from_idle(self):
        """Тест: печать документа из состояния IDLE"""
        printer = self.create_initialized_printer()
        document = self.create_document()
        settings = self.create_default_settings()

        result = printer.print_document(document, settings)

        self.assertTrue(result)
        self.assertEqual(printer.state, PrinterState.IDLE)
        self.assertEqual(printer.paper.quantity, 95)  # 100 - 5 страниц

    def test_print_document_from_wrong_state(self):
        """Тест: печать из неправильного состояния вызывает исключение"""
        printer = self.create_printer()
        document = self.create_document()
        printer._state = PrinterState.OFF

        with self.assertRaises(PrinterException):
            printer.print_document(document)

    def test_print_document_consumes_paper(self):
        """Тест: печать потребляет бумагу"""
        printer = self.create_initialized_printer()
        document = self.create_document()
        initial_quantity = printer.paper.quantity
        printer.print_document(document)

        self.assertEqual(printer.paper.quantity, initial_quantity - document.pages)

    def test_print_document_consumes_ink_color_mode(self):
        """Тест: печать в цветном режиме потребляет все картриджи"""
        printer = self.create_initialized_printer()
        document = self.create_document()
        initial_levels = [c.level for c in printer._cartridges]

        settings = PrintSettings(color_mode='color')
        printer.print_document(document, settings)

        # Все картриджи должны быть израсходованы
        for i, cartridge in enumerate(printer._cartridges):
            self.assertLess(cartridge.level, initial_levels[i])

    def test_print_document_consumes_ink_grayscale_mode(self):
        """Тест: печать в монохромном режиме потребляет только чёрный картридж"""
        printer = self.create_initialized_printer()
        document = self.create_document()
        black_cartridge = printer._get_black_cartridge()
        initial_black_level = black_cartridge.level
        initial_other_levels = [c.level for c in printer._cartridges if c.color != 'K']

        settings = PrintSettings(color_mode='grayscale')
        printer.print_document(document, settings)

        # Только чёрный картридж изменился
        black_cartridge = printer._get_black_cartridge()
        self.assertLess(black_cartridge.level, initial_black_level)

        # Остальные картриджи не изменились
        other_levels = [c.level for c in printer._cartridges if c.color != 'K']
        self.assertEqual(other_levels, initial_other_levels)

    def test_print_document_with_multiple_copies(self):
        """Тест: печать с несколькими копиями"""
        printer = self.create_initialized_printer()
        document = self.create_document()
        copies = 3
        settings = PrintSettings(copies=copies)

        initial_paper = printer.paper.quantity
        printer.print_document(document, settings)

        self.assertEqual(printer.paper.quantity, initial_paper - (document.pages * copies))

    def test_print_document_out_of_paper_during_print(self):
        """Тест: закончилась бумага во время печати"""
        printer = self.create_initialized_printer()
        document = self.create_document()
        # Устанавливаем мало бумаги
        printer._paper._quantity = 2

        with self.assertRaises(OutOfPaperError):
            printer.print_document(document)

        self.assertEqual(printer.state, PrinterState.OUT_OF_PAPER)

    def test_print_document_low_ink_during_print(self):
        """Тест: закончились чернила во время печати"""
        printer = self.create_initialized_printer()
        document = self.create_document()
        # Устанавливаем мало чернил
        black_cartridge = printer._get_black_cartridge()
        black_cartridge._level = 0.1

        with self.assertRaises(LowInkError):
            printer.print_document(document)

        self.assertEqual(printer.state, PrinterState.LOW_INK)

    def test_print_document_driver_fails(self):
        """Тест: ошибка драйвера при печати"""
        printer = self.create_initialized_printer()
        driver = printer._driver
        document = self.create_document()
        driver.send_print_command.return_value = False

        with self.assertRaises(HardwareError):
            printer.print_document(document)

        self.assertEqual(printer.state, PrinterState.ERROR)

    def test_print_document_insufficient_paper(self):
        """Тест: недостаточно бумаги для печати"""
        printer = self.create_initialized_printer()
        document = self.create_document()
        printer._paper._quantity = 2  # Меньше, чем нужно

        with self.assertRaises(OutOfPaperError):
            printer.print_document(document)

        self.assertEqual(printer.state, PrinterState.OUT_OF_PAPER)

    def test_print_document_insufficient_ink(self):
        """Тест: недостаточно чернил для печати"""
        printer = self.create_initialized_printer()
        document = self.create_document()
        # Устанавливаем критически низкий уровень чернил
        for cartridge in printer._cartridges:
            cartridge._level = 0.4  # 4% от 10.0

        with self.assertRaises(LowInkError):
            printer.print_document(document)

        self.assertEqual(printer.state, PrinterState.LOW_INK)

    # ========================================
    # Тесты load_paper()
    # ========================================

    def test_load_paper_increases_quantity(self):
        """Тест: загрузка бумаги увеличивает количество"""
        printer = self.create_initialized_printer()
        initial_quantity = printer.paper.quantity
        quantity_to_add = 50

        printer.load_paper(quantity_to_add)

        self.assertEqual(printer.paper.quantity, initial_quantity + quantity_to_add)

    def test_load_paper_from_out_of_paper_to_idle(self):
        """Тест: переход из OUT_OF_PAPER в IDLE после загрузки бумаги"""
        printer = self.create_printer()
        # Создаём принтер без бумаги
        printer._paper._quantity = 0
        printer.power_on()

        self.assertEqual(printer.state, PrinterState.OUT_OF_PAPER)

        printer.load_paper(100)

        self.assertEqual(printer.state, PrinterState.IDLE)

    def test_load_paper_when_off_raises_error(self):
        """Тест: загрузка бумаги при выключенном принтере вызывает исключение"""
        printer = self.create_printer()

        with self.assertRaises(PrinterException):
            printer.load_paper(50)

    def test_load_paper_with_low_ink_stays_in_low_ink(self):
        """Тест: загрузка бумаги при низких чернилах остаётся в состоянии LOW_INK"""
        printer = self.create_printer()
        # Создаём принтер с низкими чернилами
        printer._cartridges[0]._level = 0.5
        printer.power_on()

        self.assertEqual(printer.state, PrinterState.LOW_INK)

        printer.load_paper(50)

        self.assertEqual(printer.state, PrinterState.LOW_INK)

    # ========================================
    # Тесты replace_ink()
    # ========================================

    def test_replace_ink_refills_cartridge(self):
        """Тест: замена чернил заправляет картридж"""
        printer = self.create_initialized_printer()
        cartridge = printer._cartridges[0]
        initial_level = cartridge.level

        # Имитируем расход чернил
        cartridge.consume(2.0)
        self.assertLess(cartridge.level, initial_level)

        # Заправляем
        printer.replace_ink(cartridge.color)

        self.assertEqual(cartridge.level, cartridge.capacity)

    def test_replace_ink_from_low_ink_to_idle(self):
        """Тест: переход из LOW_INK в IDLE после замены чернил"""
        printer = self.create_printer()
        # Создаём принтер с низкими чернилами
        printer._cartridges[0]._level = 0.5
        printer.power_on()

        self.assertEqual(printer.state, PrinterState.LOW_INK)

        printer.replace_ink('C')

        self.assertEqual(printer.state, PrinterState.IDLE)

    def test_replace_ink_when_off_raises_error(self):
        """Тест: замена чернил при выключенном принтере вызывает исключение"""
        printer = self.create_printer()

        with self.assertRaises(PrinterException):
            printer.replace_ink('C')

    def test_replace_ink_invalid_color(self):
        """Тест: замена несуществующего цвета вызывает исключение"""
        printer = self.create_initialized_printer()

        with self.assertRaises(ValueError) as context:
            printer.replace_ink('R')

        self.assertIn("Картридж цвета", str(context.exception))

    def test_replace_ink_case_insensitive(self):
        """Тест: замена чернил нечувствительна к регистру"""
        printer = self.create_initialized_printer()
        cartridge = printer._get_black_cartridge()
        cartridge.consume(2.0)

        printer.replace_ink('k')  # нижний регистр

        self.assertEqual(cartridge.level, cartridge.capacity)

    # ========================================
    # Тесты start_maintenance()
    # ========================================

    def test_start_maintenance_from_idle(self):
        """Тест: обслуживание из состояния IDLE"""
        printer = self.create_initialized_printer()
        driver = printer._driver

        result = printer.start_maintenance('clean')

        self.assertTrue(result)
        self.assertEqual(printer.state, PrinterState.IDLE)
        self.assertEqual(printer._maintenance_count, 1)
        driver.run_maintenance.assert_called_once_with('clean')

    def test_start_maintenance_from_error(self):
        """Тест: обслуживание из состояния ERROR"""
        printer = self.create_printer()
        printer._state = PrinterState.ERROR

        result = printer.start_maintenance('clean')

        self.assertTrue(result)
        self.assertEqual(printer.state, PrinterState.IDLE)
        self.assertEqual(printer._maintenance_count, 1)

    def test_start_maintenance_from_wrong_state(self):
        """Тест: обслуживание из неправильного состояния вызывает исключение"""
        printer = self.create_printer()
        printer._state = PrinterState.OFF

        with self.assertRaises(PrinterException):
            printer.start_maintenance('clean')

    def test_start_maintenance_driver_fails(self):
        """Тест: неудачное обслуживание переводит в состояние ERROR"""
        printer = self.create_initialized_printer()
        driver = printer._driver
        driver.run_maintenance.return_value = False

        result = printer.start_maintenance('clean')

        self.assertFalse(result)
        self.assertEqual(printer.state, PrinterState.ERROR)

    def test_start_maintenance_driver_raises_exception(self):
        """Тест: исключение драйвера при обслуживании"""
        printer = self.create_initialized_printer()
        driver = printer._driver
        driver.run_maintenance.side_effect = Exception("Maintenance error")

        with self.assertRaises(HardwareError):
            printer.start_maintenance('clean')

        self.assertEqual(printer.state, PrinterState.ERROR)

    def test_start_maintenance_increments_count(self):
        """Тест: счётчик обслуживания увеличивается"""
        printer = self.create_initialized_printer()
        initial_count = printer._maintenance_count

        printer.start_maintenance('clean')
        printer.start_maintenance('calibrate')

        self.assertEqual(printer._maintenance_count, initial_count + 2)

    # ========================================
    # Тесты вспомогательных методов
    # ========================================

    def test_get_black_cartridge(self):
        """Тест: получение чёрного картриджа"""
        printer = self.create_printer()
        black_cartridge = printer._get_black_cartridge()

        self.assertEqual(black_cartridge.color, 'K')
        self.assertIn(black_cartridge, printer._cartridges)

    def test_get_black_cartridge_not_found(self):
        """Тест: исключение при отсутствии чёрного картриджа"""
        driver = self.create_mock_driver()
        printer = Printer("Test", driver)
        printer._cartridges = []  # Удаляем все картриджи

        with self.assertRaises(RuntimeError) as context:
            printer._get_black_cartridge()

        self.assertIn("Черный картридж не найден", str(context.exception))

    # ========================================
    # Тесты get_status()
    # ========================================

    def test_get_status_structure(self):
        """Тест: структура статуса"""
        printer = self.create_initialized_printer()
        status = printer.get_status()

        self.assertIn('model', status)
        self.assertIn('state', status)
        self.assertIn('paper', status)
        self.assertIn('cartridges', status)
        self.assertIn('maintenance_count', status)

        self.assertEqual(status['model'], "TestPrinter")
        self.assertEqual(status['state'], PrinterState.IDLE.value)

    def test_get_status_paper_info(self):
        """Тест: информация о бумаге в статусе"""
        printer = self.create_initialized_printer()
        status = printer.get_status()

        self.assertIn('type', status['paper'])
        self.assertIn('quantity', status['paper'])
        self.assertIn('is_empty', status['paper'])

        self.assertEqual(status['paper']['type'], "A4")
        self.assertEqual(status['paper']['quantity'], 100)

    def test_get_status_cartridges_info(self):
        """Тест: информация о картриджах в статусе"""
        printer = self.create_initialized_printer()
        status = printer.get_status()

        self.assertEqual(len(status['cartridges']), 4)

        for cartridge in status['cartridges']:
            self.assertIn('color', cartridge)
            self.assertIn('level_percent', cartridge)
            self.assertIn('level_ml', cartridge)
            self.assertIn('capacity_ml', cartridge)
            self.assertIn('is_empty', cartridge)

    # ========================================
    # Тесты to_dict() и from_dict()
    # ========================================

    def test_to_dict_structure(self):
        """Тест: структура сериализованного состояния"""
        printer = self.create_initialized_printer()
        data = printer.to_dict()

        self.assertIn('model', data)
        self.assertIn('state', data)
        self.assertIn('paper', data)
        self.assertIn('cartridges', data)
        self.assertIn('maintenance_count', data)

        self.assertEqual(data['model'], "TestPrinter")
        self.assertEqual(data['state'], PrinterState.IDLE.value)

    def test_to_dict_paper_info(self):
        """Тест: информация о бумаге в сериализации"""
        printer = self.create_initialized_printer()
        data = printer.to_dict()

        self.assertEqual(data['paper']['type'], "A4")
        self.assertEqual(data['paper']['quantity'], 100)

    def test_to_dict_cartridges_info(self):
        """Тест: информация о картриджах в сериализации"""
        printer = self.create_initialized_printer()
        data = printer.to_dict()

        self.assertEqual(len(data['cartridges']), 4)

        for cartridge in data['cartridges']:
            self.assertIn('color', cartridge)
            self.assertIn('capacity', cartridge)
            self.assertIn('level', cartridge)

    def test_from_dict_restores_printer(self):
        """Тест: восстановление принтера из словаря"""
        driver = self.create_mock_driver()
        data = {
            'model': 'RestoredPrinter',
            'state': 'idle',
            'paper': {'type': 'A4', 'quantity': 50},
            'cartridges': [
                {'color': 'C', 'capacity': 10.0, 'level': 8.0},
                {'color': 'M', 'capacity': 10.0, 'level': 7.0},
                {'color': 'Y', 'capacity': 10.0, 'level': 6.0},
                {'color': 'K', 'capacity': 10.0, 'level': 9.0},
            ],
            'maintenance_count': 3
        }

        printer = Printer.from_dict(data, driver)

        self.assertEqual(printer.model, 'RestoredPrinter')
        self.assertEqual(printer.state, PrinterState.IDLE)
        self.assertEqual(printer.paper.quantity, 50)
        self.assertEqual(printer._maintenance_count, 3)

        # Проверяем картриджи
        colors = {c.color for c in printer._cartridges}
        self.assertEqual(colors, {'C', 'M', 'Y', 'K'})

        black_cartridge = printer._get_black_cartridge()
        self.assertEqual(black_cartridge.level, 9.0)

    def test_from_dict_with_invalid_state(self):
        """Тест: восстановление с недопустимым состоянием"""
        driver = self.create_mock_driver()
        data = {
            'model': 'Test',
            'state': 'invalid_state',
            'paper': {'type': 'A4', 'quantity': 100},
            'cartridges': [
                {'color': 'C', 'capacity': 10.0, 'level': 10.0},
                {'color': 'M', 'capacity': 10.0, 'level': 10.0},
                {'color': 'Y', 'capacity': 10.0, 'level': 10.0},
                {'color': 'K', 'capacity': 10.0, 'level': 10.0},
            ],
            'maintenance_count': 0
        }

        printer = Printer.from_dict(data, driver)

        self.assertEqual(printer.state, PrinterState.OFF)  # Состояние по умолчанию

    def test_to_dict_and_from_dict_roundtrip(self):
        """Тест: полный цикл сериализации и десериализации"""
        driver = self.create_mock_driver()
        printer = Printer("TestPrinter", driver)

        # Изменяем состояние принтера
        printer._paper._quantity = 75
        printer._cartridges[0]._level = 8.5
        printer._maintenance_count = 2
        printer._state = PrinterState.IDLE

        # Сериализуем
        data = printer.to_dict()

        # Десериализуем
        restored_printer = Printer.from_dict(data, driver)

        # Проверяем, что состояние восстановилось
        self.assertEqual(restored_printer.model, printer.model)
        self.assertEqual(restored_printer.state, printer.state)
        self.assertEqual(restored_printer.paper.quantity, printer.paper.quantity)
        self.assertEqual(restored_printer._maintenance_count, printer._maintenance_count)

        # Проверяем картриджи
        for orig, restored in zip(printer._cartridges, restored_printer._cartridges):
            self.assertEqual(orig.color, restored.color)
            self.assertEqual(orig.level, restored.level)
            self.assertEqual(orig.capacity, restored.capacity)

    # ========================================
    # Интеграционные тесты
    # ========================================

    def test_full_workflow(self):
        """Тест: полный цикл работы принтера"""
        driver = self.create_mock_driver()
        printer = Printer("WorkflowPrinter", driver)

        # 1. Включение
        self.assertTrue(printer.power_on())
        self.assertEqual(printer.state, PrinterState.IDLE)

        # 2. Печать документа
        doc = Document("test.pdf", "PDF", 3, 1.5)
        self.assertTrue(printer.print_document(doc))
        self.assertEqual(printer.state, PrinterState.IDLE)

        # 3. Загрузка бумаги
        initial_paper = printer.paper.quantity
        printer.load_paper(50)
        self.assertEqual(printer.paper.quantity, initial_paper + 50)

        # 4. Замена чернил
        black_cartridge = printer._get_black_cartridge()
        black_cartridge.consume(2.0)
        printer.replace_ink('K')
        self.assertEqual(black_cartridge.level, black_cartridge.capacity)

        # 5. Обслуживание
        self.assertTrue(printer.start_maintenance('clean'))
        self.assertEqual(printer._maintenance_count, 1)

        # 6. Выключение
        self.assertTrue(printer.power_off())
        self.assertEqual(printer.state, PrinterState.OFF)

    def test_print_multiple_documents(self):
        """Тест: печать нескольких документов подряд"""
        printer = self.create_initialized_printer()
        document = self.create_document()

        for _ in range(3):
            self.assertTrue(printer.print_document(document))
            self.assertEqual(printer.state, PrinterState.IDLE)

    def test_state_transitions(self):
        """Тест: переходы между состояниями"""
        printer = self.create_printer()

        # OFF -> IDLE
        printer.power_on()
        self.assertEqual(printer.state, PrinterState.IDLE)

        # IDLE -> PRINTING -> IDLE
        doc = Document("test.pdf", "PDF", 1, 0.1)
        printer.print_document(doc)
        self.assertEqual(printer.state, PrinterState.IDLE)

        # IDLE -> MAINTENANCE -> IDLE
        printer.start_maintenance('clean')
        self.assertEqual(printer.state, PrinterState.IDLE)

        # IDLE -> OFF
        printer.power_off()
        self.assertEqual(printer.state, PrinterState.OFF)

    # ========================================
    # Тесты граничных случаев
    # ========================================

    def test_print_zero_pages_document(self):
        """Тест: печать документа с нулевым количеством страниц"""
        printer = self.create_initialized_printer()
        doc = Document("empty.pdf", "PDF", 0, 0.1)

        result = printer.print_document(doc)

        self.assertTrue(result)
        self.assertEqual(printer.state, PrinterState.IDLE)

    def test_replace_ink_multiple_times(self):
        """Тест: многократная замена чернил"""
        printer = self.create_initialized_printer()
        cartridge = printer._get_black_cartridge()

        for _ in range(3):
            cartridge.consume(2.0)
            printer.replace_ink('K')
            self.assertEqual(cartridge.level, cartridge.capacity)

    def test_maintenance_count_increments_correctly(self):
        """Тест: счётчик обслуживания увеличивается корректно"""
        printer = self.create_initialized_printer()
        self.assertEqual(printer._maintenance_count, 0)

        for i in range(1, 6):
            printer.start_maintenance('clean')
            self.assertEqual(printer._maintenance_count, i)


if __name__ == '__main__':
    unittest.main(verbosity=2)
