import unittest
from unittest.mock import patch, MagicMock
from driver import PrinterDriver
from interfaces import IPrintable, IDriver
from settings import PrintSettings
from document import Document


class TestPrinterDriver(unittest.TestCase):
    """Тесты класса PrinterDriver"""

    # ========================================
    # Вспомогательные методы (вместо фикстур)
    # ========================================

    def create_driver(self):
        """Создание нового драйвера"""
        return PrinterDriver()

    def create_initialized_driver(self):
        """Создание инициализированного драйвера"""
        driver = PrinterDriver()
        driver.initialize()
        return driver

    def create_mock_document(self):
        """Создание мок-документа"""
        doc = MagicMock(spec=IPrintable)
        doc.pages = 5
        doc.filename = "test.pdf"
        return doc

    def create_real_document(self):
        """Создание реального документа"""
        return Document("test.pdf", "PDF", 5, 2.5)

    def create_default_settings(self):
        """Создание настроек по умолчанию"""
        return PrintSettings()

    # ========================================
    # Тесты инициализации
    # ========================================

    def test_driver_initial_state(self):
        """Тест: начальное состояние драйвера"""
        driver = self.create_driver()

        self.assertFalse(driver._initialized)
        self.assertTrue(hasattr(driver, '_supported_commands'))
        self.assertIn('init', driver._supported_commands)
        self.assertIn('clean', driver._supported_commands)
        self.assertIn('calibrate', driver._supported_commands)

    def test_initialize_sets_flag(self):
        """Тест: инициализация устанавливает флаг"""
        driver = self.create_driver()
        result = driver.initialize()

        self.assertTrue(result)
        self.assertTrue(driver._initialized)

    def test_initialize_returns_true(self):
        """Тест: инициализация возвращает True"""
        driver = self.create_driver()
        result = driver.initialize()
        self.assertTrue(result)

    def test_initialize_can_be_called_multiple_times(self):
        """Тест: инициализацию можно вызывать несколько раз"""
        driver = self.create_driver()
        driver.initialize()
        driver.initialize()
        driver.initialize()

        self.assertTrue(driver._initialized)

    # ========================================
    # Тесты send_print_command()
    # ========================================

    def test_send_print_requires_initialization(self):
        """Тест: печать требует инициализации"""
        driver = self.create_driver()
        mock_document = self.create_mock_document()
        settings = self.create_default_settings()

        with self.assertRaises(RuntimeError) as context:
            driver.send_print_command(mock_document, settings)

        self.assertIn("Драйвер не инициализирован", str(context.exception))

    def test_send_print_successful(self):
        """Тест: успешная отправка команды печати"""
        driver = self.create_initialized_driver()
        mock_document = self.create_mock_document()
        settings = self.create_default_settings()

        with patch('random.random', return_value=0.5):  # > 0.005, значит успех
            result = driver.send_print_command(mock_document, settings)

        self.assertTrue(result)

    def test_send_print_with_high_quality(self):
        """Тест: печать с высоким качеством"""
        driver = self.create_initialized_driver()
        mock_document = self.create_mock_document()
        settings = PrintSettings(quality='high')

        with patch('random.random', return_value=0.5):
            result = driver.send_print_command(mock_document, settings)

        self.assertTrue(result)

    def test_send_print_with_draft_quality(self):
        """Тест: печать с черновым качеством"""
        driver = self.create_initialized_driver()
        mock_document = self.create_mock_document()
        settings = PrintSettings(quality='draft')

        with patch('random.random', return_value=0.5):
            result = driver.send_print_command(mock_document, settings)

        self.assertTrue(result)

    def test_send_print_failure_simulation(self):
        """Тест: симуляция неудачи печати (0.5% вероятность)"""
        driver = self.create_initialized_driver()
        mock_document = self.create_mock_document()
        settings = self.create_default_settings()

        with patch('random.random', return_value=0.001):  # < 0.005, значит неудача
            result = driver.send_print_command(mock_document, settings)

        self.assertFalse(result)

    def test_send_print_with_real_document(self):
        """Тест: печать реального документа"""
        driver = self.create_initialized_driver()
        real_document = self.create_real_document()
        settings = self.create_default_settings()

        with patch('random.random', return_value=0.5):
            result = driver.send_print_command(real_document, settings)

        self.assertTrue(result)

    # ========================================
    # Тесты run_maintenance()
    # ========================================

    def test_run_maintenance_requires_initialization(self):
        """Тест: обслуживание требует инициализации (кроме 'init')"""
        driver = self.create_driver()

        with self.assertRaises(RuntimeError) as context:
            driver.run_maintenance('clean')

        self.assertIn("Драйвер не инициализирован", str(context.exception))

    def test_run_maintenance_init_without_initialization(self):
        """Тест: операция 'init' не требует предварительной инициализации"""
        driver = self.create_driver()
        result = driver.run_maintenance('init')

        self.assertTrue(result)
        self.assertTrue(driver._initialized)

    def test_run_maintenance_unknown_operation(self):
        """Тест: неизвестная операция обслуживания"""
        driver = self.create_initialized_driver()

        with self.assertRaises(ValueError) as context:
            driver.run_maintenance('unknown')

        self.assertIn("Неподдерживаемая операция", str(context.exception))

    def test_run_maintenance_clean_successful(self):
        """Тест: успешная очистка"""
        driver = self.create_initialized_driver()

        with patch('random.random', return_value=0.5):  # > 0.02, значит успех
            result = driver.run_maintenance('clean')

        self.assertTrue(result)

    def test_run_maintenance_clean_failure(self):
        """Тест: неудачная очистка (2% вероятность)"""
        driver = self.create_initialized_driver()

        with patch('random.random', return_value=0.01):  # < 0.02, значит неудача
            result = driver.run_maintenance('clean')

        self.assertFalse(result)

    def test_run_maintenance_calibrate_successful(self):
        """Тест: успешная калибровка"""
        driver = self.create_initialized_driver()

        with patch('random.random', return_value=0.5):  # > 0.01, значит успех
            result = driver.run_maintenance('calibrate')

        self.assertTrue(result)

    def test_run_maintenance_calibrate_failure(self):
        """Тест: неудачная калибровка (1% вероятность)"""
        driver = self.create_initialized_driver()

        with patch('random.random', return_value=0.005):  # < 0.01, значит неудача
            result = driver.run_maintenance('calibrate')

        self.assertFalse(result)

    def test_all_supported_operations_work(self):
        """Тест: все поддерживаемые операции работают"""
        operations = ['clean', 'calibrate', 'init']

        for operation in operations:
            with self.subTest(operation=operation):
                driver = self.create_initialized_driver()

                with patch('random.random', return_value=0.5):
                    result = driver.run_maintenance(operation)

                self.assertTrue(result)

    # ========================================
    # Тесты внутренних методов
    # ========================================

    def test_cmd_clean_success_probability(self):
        """Тест: вероятность успеха очистки (98%)"""
        driver = self.create_driver()

        with patch('random.random', return_value=0.99):  # > 0.02
            result = driver._cmd_clean()

        self.assertTrue(result)

    def test_cmd_clean_failure_probability(self):
        """Тест: вероятность неудачи очистки (2%)"""
        driver = self.create_driver()

        with patch('random.random', return_value=0.01):  # < 0.02
            result = driver._cmd_clean()

        self.assertFalse(result)

    def test_cmd_calibrate_success_probability(self):
        """Тест: вероятность успеха калибровки (99%)"""
        driver = self.create_driver()

        with patch('random.random', return_value=0.99):  # > 0.01
            result = driver._cmd_calibrate()

        self.assertTrue(result)

    def test_cmd_calibrate_failure_probability(self):
        """Тест: вероятность неудачи калибровки (1%)"""
        driver = self.create_driver()

        with patch('random.random', return_value=0.005):  # < 0.01
            result = driver._cmd_calibrate()

        self.assertFalse(result)

    # ========================================
    # Тесты реализации интерфейса IDriver
    # ========================================

    def test_implements_idriver_interface(self):
        """Тест: класс реализует интерфейс IDriver"""
        driver = self.create_driver()

        self.assertIsInstance(driver, IDriver)
        self.assertTrue(hasattr(driver, 'initialize'))
        self.assertTrue(hasattr(driver, 'send_print_command'))
        self.assertTrue(hasattr(driver, 'run_maintenance'))

    def test_interface_methods_signature(self):
        """Тест: сигнатуры методов интерфейса"""
        driver = self.create_initialized_driver()
        mock_document = self.create_mock_document()
        settings = self.create_default_settings()

        # Проверяем, что методы вызываются без ошибок
        self.assertTrue(driver.initialize())
        result = driver.send_print_command(mock_document, settings)
        self.assertIn(result, (True, False))
        result = driver.run_maintenance('clean')
        self.assertIn(result, (True, False))

    # ========================================
    # Интеграционные тесты
    # ========================================

    def test_full_workflow(self):
        """Тест: полный цикл работы драйвера"""
        driver = PrinterDriver()

        # 1. Инициализация
        self.assertFalse(driver._initialized)
        self.assertTrue(driver.initialize())
        self.assertTrue(driver._initialized)

        # 2. Печать документа
        doc = Document("test.pdf", "PDF", 3, 1.5)
        settings = PrintSettings()

        with patch('random.random', return_value=0.5):
            result = driver.send_print_command(doc, settings)
            self.assertTrue(result)

        # 3. Обслуживание
        with patch('random.random', return_value=0.5):
            result = driver.run_maintenance('clean')
            self.assertTrue(result)

        # 4. Калибровка
        with patch('random.random', return_value=0.5):
            result = driver.run_maintenance('calibrate')
            self.assertTrue(result)

    def test_multiple_print_jobs(self):
        """Тест: несколько последовательных заданий на печать"""
        driver = self.create_initialized_driver()
        mock_document = self.create_mock_document()
        settings = self.create_default_settings()

        with patch('random.random', return_value=0.5):
            for _ in range(5):
                result = driver.send_print_command(mock_document, settings)
                self.assertTrue(result)

    # ========================================
    # Тесты с разными настройками качества
    # ========================================

    def test_print_with_draft_quality(self):
        """Тест: печать с черновым качеством"""
        driver = self.create_initialized_driver()
        mock_document = self.create_mock_document()
        settings = PrintSettings(quality='draft')

        with patch('random.random', return_value=0.5):
            result = driver.send_print_command(mock_document, settings)

        self.assertTrue(result)

    def test_print_with_normal_quality(self):
        """Тест: печать с нормальным качеством"""
        driver = self.create_initialized_driver()
        mock_document = self.create_mock_document()
        settings = PrintSettings(quality='normal')

        with patch('random.random', return_value=0.5):
            result = driver.send_print_command(mock_document, settings)

        self.assertTrue(result)

    def test_print_with_high_quality(self):
        """Тест: печать с высоким качеством"""
        driver = self.create_initialized_driver()
        mock_document = self.create_mock_document()
        settings = PrintSettings(quality='high')

        with patch('random.random', return_value=0.5):
            result = driver.send_print_command(mock_document, settings)

        self.assertTrue(result)

    # ========================================
    # Тесты граничных случаев
    # ========================================

    def test_print_with_zero_pages(self):
        """Тест: печать документа с нулевым количеством страниц"""
        driver = self.create_initialized_driver()
        settings = self.create_default_settings()

        doc = MagicMock(spec=IPrintable)
        doc.pages = 0
        doc.filename = "empty.pdf"

        with patch('random.random', return_value=0.5):
            result = driver.send_print_command(doc, settings)

        self.assertTrue(result)  # Должно работать, time.sleep(0)

    def test_print_with_many_pages(self):
        """Тест: печать документа с большим количеством страниц"""
        driver = self.create_initialized_driver()
        settings = self.create_default_settings()

        doc = MagicMock(spec=IPrintable)
        doc.pages = 100
        doc.filename = "large.pdf"

        with patch('random.random', return_value=0.5):
            result = driver.send_print_command(doc, settings)

        self.assertTrue(result)

    # ========================================
    # Тесты производительности
    # ========================================

    def test_initialize_performance(self):
        """Тест: производительность инициализации"""
        driver = self.create_driver()
        import time

        start = time.time()
        result = driver.initialize()
        elapsed = time.time() - start

        self.assertTrue(result)
        self.assertGreaterEqual(elapsed, 0.2)  # time.sleep(0.2)

    def test_maintenance_performance(self):
        """Тест: производительность обслуживания"""
        driver = self.create_initialized_driver()
        import time

        start = time.time()
        with patch('random.random', return_value=0.5):
            result = driver.run_maintenance('clean')
        elapsed = time.time() - start

        self.assertTrue(result)
        self.assertGreaterEqual(elapsed, 0.5)  # time.sleep(0.5)

    # ========================================
    # Тесты с реальными документами
    # ========================================

    def test_print_documents_of_various_sizes(self):
        """Тест: печать документов разного размера"""
        test_cases = [
            (1, 0.1),
            (10, 1.0),
            (50, 5.0),
            (100, 10.0),
        ]

        for pages, size_mb in test_cases:
            with self.subTest(pages=pages, size_mb=size_mb):
                driver = self.create_initialized_driver()
                doc = Document(f"doc_{pages}p.pdf", "PDF", pages, size_mb)
                settings = self.create_default_settings()

                with patch('random.random', return_value=0.5):
                    result = driver.send_print_command(doc, settings)

                self.assertTrue(result)

    # ========================================
    # Тесты повторной инициализации
    # ========================================

    def test_reinitialize_after_failure(self):
        """Тест: повторная инициализация после неудачи"""
        driver = PrinterDriver()

        # Первая инициализация
        self.assertTrue(driver.initialize())
        self.assertTrue(driver._initialized)

        # Повторная инициализация
        self.assertTrue(driver.initialize())
        self.assertTrue(driver._initialized)

    # ========================================
    # Тесты с разными цветовыми режимами
    # ========================================

    def test_print_with_color_mode(self):
        """Тест: печать в цветном режиме"""
        driver = self.create_initialized_driver()
        mock_document = self.create_mock_document()
        settings = PrintSettings(color_mode='color')

        with patch('random.random', return_value=0.5):
            result = driver.send_print_command(mock_document, settings)

        self.assertTrue(result)

    def test_print_with_grayscale_mode(self):
        """Тест: печать в режиме серого"""
        driver = self.create_initialized_driver()
        mock_document = self.create_mock_document()
        settings = PrintSettings(color_mode='grayscale')

        with patch('random.random', return_value=0.5):
            result = driver.send_print_command(mock_document, settings)

        self.assertTrue(result)

    def test_print_with_black_and_white_mode(self):
        """Тест: печать в чёрно-белом режиме"""
        driver = self.create_initialized_driver()
        mock_document = self.create_mock_document()
        settings = PrintSettings(color_mode='black_and_white')

        with patch('random.random', return_value=0.5):
            result = driver.send_print_command(mock_document, settings)

        self.assertTrue(result)


if __name__ == '__main__':
    unittest.main(verbosity=2)
