import unittest
import json
import tempfile
from pathlib import Path
from unittest.mock import Mock, MagicMock
from saver import PrinterStateStorage
from printer import Printer, PrinterState
from interfaces import IDriver
from document import Document


class TestPrinterStateStorage(unittest.TestCase):
    """Тесты класса PrinterStateStorage"""

    # ========================================
    # Вспомогательные методы
    # ========================================

    def create_mock_driver(self):
        """Создание мок-драйвера"""
        driver = Mock(spec=IDriver)
        driver.initialize.return_value = True
        driver.send_print_command.return_value = True
        driver.run_maintenance.return_value = True
        return driver

    def create_printer(self, driver):
        """Создание принтера с предустановленным состоянием"""
        printer = Printer("TestPrinter", driver)
        printer._state = PrinterState.IDLE  # Исправлено: использование Enum вместо строки
        printer._paper._quantity = 75
        printer._maintenance_count = 2
        return printer

    # ========================================
    # Тесты инициализации
    # ========================================

    def test_init_with_default_path(self):
        """Тест: инициализация с путём по умолчанию"""
        storage = PrinterStateStorage()
        self.assertEqual(storage._storage_path.name, "printer_state.json")

    def test_init_with_custom_path(self):
        """Тест: инициализация с пользовательским путём"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "custom.json"
            storage = PrinterStateStorage(str(storage_path))
            self.assertEqual(storage._storage_path, storage_path)

    def test_init_with_relative_path(self):
        """Тест: инициализация с относительным путём"""
        storage = PrinterStateStorage("data/printer.json")
        self.assertEqual(storage._storage_path.name, "printer.json")

    # ========================================
    # Тесты save()
    # ========================================

    def test_save_creates_file(self):
        """Тест: сохранение создаёт файл"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()
            printer = self.create_printer(driver)

            result = storage.save(printer)

            self.assertTrue(result)
            self.assertTrue(storage_path.exists())

    def test_save_writes_valid_json(self):
        """Тест: сохранение записывает валидный JSON"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()
            printer = self.create_printer(driver)

            storage.save(printer)

            with open(storage_path, 'r', encoding='utf-8') as f:
                data = json.load(f)

            self.assertIn('model', data)
            self.assertIn('state', data)
            self.assertIn('paper', data)
            self.assertIn('cartridges', data)
            self.assertIn('maintenance_count', data)

    def test_save_preserves_printer_data(self):
        """Тест: сохранение сохраняет данные принтера"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()
            printer = self.create_printer(driver)

            storage.save(printer)

            with open(storage_path, 'r', encoding='utf-8') as f:
                data = json.load(f)

            self.assertEqual(data['model'], printer.model)
            self.assertEqual(data['state'], printer.state.value)
            self.assertEqual(data['paper']['quantity'], printer.paper.quantity)
            self.assertEqual(data['maintenance_count'], printer._maintenance_count)

    def test_save_overwrites_existing_file(self):
        """Тест: сохранение перезаписывает существующий файл"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()
            printer = self.create_printer(driver)

            # Первое сохранение
            storage.save(printer)

            # Изменяем принтер
            printer._maintenance_count = 5

            # Второе сохранение
            storage.save(printer)

            # Проверяем, что файл обновился
            with open(storage_path, 'r', encoding='utf-8') as f:
                data = json.load(f)

            self.assertEqual(data['maintenance_count'], 5)

    def test_save_with_io_error(self):
        """Тест: сохранение при ошибке ввода-вывода"""
        # Создаём хранилище с недоступным путём
        invalid_storage = PrinterStateStorage("/invalid/path/printer_state.json")
        driver = self.create_mock_driver()
        printer = self.create_printer(driver)

        result = invalid_storage.save(printer)

        self.assertFalse(result)

    # ========================================
    # Тесты load()
    # ========================================

    def test_load_returns_none_when_file_not_exists(self):
        """Тест: загрузка возвращает None, если файл не существует"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "nonexistent.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()

            result = storage.load(driver)

            self.assertIsNone(result)

    def test_load_restores_printer(self):
        """Тест: загрузка восстанавливает принтер"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()
            printer = self.create_printer(driver)

            # Сохраняем принтер
            storage.save(printer)

            # Загружаем
            loaded_printer = storage.load(driver)

            self.assertIsNotNone(loaded_printer)
            self.assertEqual(loaded_printer.model, printer.model)
            self.assertEqual(loaded_printer.state, printer.state)
            self.assertEqual(loaded_printer.paper.quantity, printer.paper.quantity)
            self.assertEqual(loaded_printer._maintenance_count, printer._maintenance_count)

    def test_load_restores_cartridges(self):
        """Тест: загрузка восстанавливает картриджи"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()
            printer = self.create_printer(driver)

            # Сохраняем принтер
            storage.save(printer)

            # Загружаем
            loaded_printer = storage.load(driver)

            # Проверяем картриджи
            self.assertEqual(len(loaded_printer._cartridges), len(printer._cartridges))

            for orig, loaded in zip(printer._cartridges, loaded_printer._cartridges):
                self.assertEqual(orig.color, loaded.color)
                self.assertEqual(orig.level, loaded.level)
                self.assertEqual(orig.capacity, loaded.capacity)

    def test_load_with_invalid_json(self):
        """Тест: загрузка при невалидном JSON"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()

            # Создаём файл с невалидным JSON
            with open(storage_path, 'w', encoding='utf-8') as f:
                f.write("invalid json content")

            result = storage.load(driver)

            self.assertIsNone(result)

    def test_load_with_missing_keys(self):
        """Тест: загрузка при отсутствующих ключах"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()

            # Создаём файл с неполными данными
            incomplete_data = {
                'model': 'TestPrinter',
                # Отсутствует 'state', 'paper', 'cartridges'
            }

            with open(storage_path, 'w', encoding='utf-8') as f:
                json.dump(incomplete_data, f)

            result = storage.load(driver)

            self.assertIsNone(result)

    def test_load_with_io_error(self):
        """Тест: загрузка при ошибке ввода-вывода"""
        # Создаём хранилище с недоступным путём
        invalid_storage = PrinterStateStorage("/invalid/path/printer_state.json")
        driver = self.create_mock_driver()

        result = invalid_storage.load(driver)

        self.assertIsNone(result)

    def test_load_with_corrupted_file(self):
        """Тест: загрузка при повреждённом файле"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()

            # Создаём пустой файл
            storage_path.touch()

            result = storage.load(driver)

            self.assertIsNone(result)

    # ========================================
    # Тесты exists()
    # ========================================

    def test_exists_returns_false_when_file_not_exists(self):
        """Тест: проверка существования файла (файл не существует)"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "nonexistent.json"
            storage = PrinterStateStorage(str(storage_path))
            self.assertFalse(storage.exists())

    def test_exists_returns_true_when_file_exists(self):
        """Тест: проверка существования файла (файл существует)"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()
            printer = self.create_printer(driver)
            storage.save(printer)
            self.assertTrue(storage.exists())

    def test_exists_after_delete(self):
        """Тест: проверка существования после удаления"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()
            printer = self.create_printer(driver)

            storage.save(printer)
            self.assertTrue(storage.exists())

            storage.delete()
            self.assertFalse(storage.exists())

    # ========================================
    # Тесты delete()
    # ========================================

    def test_delete_removes_file(self):
        """Тест: удаление удаляет файл"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()
            printer = self.create_printer(driver)

            storage.save(printer)
            self.assertTrue(storage.exists())

            result = storage.delete()

            self.assertTrue(result)
            self.assertFalse(storage.exists())

    def test_delete_when_file_not_exists(self):
        """Тест: удаление, когда файл не существует"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "nonexistent.json"
            storage = PrinterStateStorage(str(storage_path))
            result = storage.delete()
            self.assertTrue(result)  # Успешное удаление несуществующего файла

    # ========================================
    # Тесты get_path()
    # ========================================

    def test_get_path_returns_string(self):
        """Тест: get_path возвращает строку"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            path = storage.get_path()
            self.assertIsInstance(path, str)

    def test_get_path_returns_absolute_path(self):
        """Тест: get_path возвращает абсолютный путь"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            path = storage.get_path()
            self.assertTrue(Path(path).is_absolute())

    def test_get_path_matches_storage_path(self):
        """Тест: get_path соответствует пути хранения"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            self.assertEqual(storage.get_path(), str(storage_path))

    # ========================================
    # Интеграционные тесты
    # ========================================

    def test_save_and_load_roundtrip(self):
        """Тест: полный цикл сохранения и загрузки"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()
            printer = self.create_printer(driver)

            # Сохраняем
            save_result = storage.save(printer)
            self.assertTrue(save_result)

            # Загружаем
            loaded_printer = storage.load(driver)
            self.assertIsNotNone(loaded_printer)

            # Проверяем данные
            self.assertEqual(loaded_printer.model, printer.model)
            self.assertEqual(loaded_printer.state, printer.state)
            self.assertEqual(loaded_printer.paper.quantity, printer.paper.quantity)
            self.assertEqual(loaded_printer._maintenance_count, printer._maintenance_count)

            # Проверяем картриджи
            for orig, loaded in zip(printer._cartridges, loaded_printer._cartridges):
                self.assertEqual(orig.color, loaded.color)
                self.assertEqual(orig.level, loaded.level)

    def test_multiple_save_load_cycles(self):
        """Тест: несколько циклов сохранения и загрузки"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()
            printer = self.create_printer(driver)

            for i in range(3):
                # Изменяем принтер
                printer._maintenance_count = i + 1

                # Сохраняем
                storage.save(printer)

                # Загружаем
                loaded = storage.load(driver)

                # Проверяем
                self.assertEqual(loaded._maintenance_count, i + 1)

    def test_save_load_with_different_printers(self):
        """Тест: сохранение и загрузка разных принтеров"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()

            # Создаём первый принтер
            printer1 = Printer("Printer1", driver)
            printer1._maintenance_count = 10
            storage.save(printer1)

            # Создаём второй принтер
            printer2 = Printer("Printer2", driver)
            printer2._maintenance_count = 20
            storage.save(printer2)

            # Загружаем
            loaded = storage.load(driver)

            # Должен быть загружен второй принтер
            self.assertEqual(loaded.model, "Printer2")
            self.assertEqual(loaded._maintenance_count, 20)

    def test_save_load_preserves_state_transitions(self):
        """Тест: сохранение и загрузка сохраняют переходы состояний"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()

            # Создаём принтер и включаем его
            printer = Printer("Test", driver)
            printer.power_on()

            # Сохраняем в состоянии IDLE
            storage.save(printer)

            # Загружаем
            loaded = storage.load(driver)

            # Проверяем состояние
            self.assertEqual(loaded.state, printer.state)

    # ========================================
    # Тесты с реальным принтером
    # ========================================

    def test_save_load_with_printed_document(self):
        """Тест: сохранение и загрузка после печати документа"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()

            # Создаём принтер и включаем
            printer = Printer("Test", driver)
            printer.power_on()

            # Печатаем документ
            doc = Document("test.pdf", "PDF", 5, 2.5)
            printer.print_document(doc)

            # Сохраняем
            storage.save(printer)

            # Загружаем
            loaded = storage.load(driver)

            # Проверяем, что бумага была израсходована
            self.assertEqual(loaded.paper.quantity, printer.paper.quantity)
            self.assertLess(loaded.paper.quantity, 100)  # Должно быть меньше начального

    def test_save_load_with_maintenance(self):
        """Тест: сохранение и загрузка после обслуживания"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()

            # Создаём принтер
            printer = Printer("Test", driver)
            printer.power_on()

            # Выполняем обслуживание
            printer.start_maintenance('clean')

            # Сохраняем
            storage.save(printer)

            # Загружаем
            loaded = storage.load(driver)

            # Проверяем счётчик обслуживания
            self.assertEqual(loaded._maintenance_count, 1)

    # ========================================
    # Тесты граничных случаев
    # ========================================

    def test_save_empty_printer(self):
        """Тест: сохранение пустого принтера"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()
            printer = Printer("Empty", driver)

            result = storage.save(printer)
            self.assertTrue(result)

    def test_load_into_different_driver(self):
        """Тест: загрузка с другим драйвером"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver1 = self.create_mock_driver()
            printer = self.create_printer(driver1)

            # Сохраняем с одним драйвером
            storage.save(printer)

            # Создаём другой драйвер
            driver2 = Mock(spec=IDriver)
            driver2.initialize.return_value = True

            # Загружаем с другим драйвером
            loaded = storage.load(driver2)

            self.assertIsNotNone(loaded)
            self.assertEqual(loaded.model, printer.model)

    def test_save_with_special_characters_in_model(self):
        """Тест: сохранение с особыми символами в названии модели"""
        with tempfile.TemporaryDirectory() as tmpdir:
            storage_path = Path(tmpdir) / "printer_state.json"
            storage = PrinterStateStorage(str(storage_path))
            driver = self.create_mock_driver()
            printer = Printer("Printer №1 (Test)", driver)

            result = storage.save(printer)
            self.assertTrue(result)

            # Загружаем и проверяем
            loaded = storage.load(driver)
            self.assertEqual(loaded.model, "Printer №1 (Test)")


if __name__ == '__main__':
    unittest.main(verbosity=2)
