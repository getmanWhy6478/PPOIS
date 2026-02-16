"""Unit-тесты для saver.PrinterStateStorage."""

import json
import os
import tempfile
import unittest

from printer import Printer
from saver import PrinterStateStorage
from driver import PrinterDriver


class TestPrinterStateStorage(unittest.TestCase):
    """Тесты хранилища состояния принтера."""

    def setUp(self) -> None:
        self.tmpdir = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmpdir.cleanup)
        self.path = os.path.join(self.tmpdir.name, "printer_state.json")
        self.storage = PrinterStateStorage(self.path)

    def test_get_path_returns_given_path(self) -> None:
        self.assertEqual(self.storage.get_path(), self.path)

    def test_exists_false_when_file_missing(self) -> None:
        self.assertFalse(self.storage.exists())

    def test_save_creates_file_and_load_restores(self) -> None:
        from paper import Paper
        driver = PrinterDriver()
        driver.initialize()
        printer = Printer("SavedModel", driver)
        printer.power_on()
        printer._paper = Paper("A4", 42)

        success = self.storage.save(printer)
        self.assertTrue(success)
        self.assertTrue(self.storage.exists())

        loaded = self.storage.load(driver)
        self.assertIsNotNone(loaded)
        self.assertEqual(loaded.model, "SavedModel")
        self.assertEqual(loaded.paper.quantity, 42)
        self.assertEqual(loaded.state.value, "idle")

    def test_load_returns_none_when_file_missing(self) -> None:
        loaded = self.storage.load(PrinterDriver())
        self.assertIsNone(loaded)

    def test_load_returns_none_on_invalid_json(self) -> None:
        with open(self.path, "w", encoding="utf-8") as f:
            f.write("not json {")
        loaded = self.storage.load(PrinterDriver())
        self.assertIsNone(loaded)

    def test_delete_removes_file(self) -> None:
        with open(self.path, "w", encoding="utf-8") as f:
            f.write("{}")
        self.assertTrue(self.storage.exists())
        result = self.storage.delete()
        self.assertTrue(result)
        self.assertFalse(self.storage.exists())

    def test_delete_when_no_file_succeeds(self) -> None:
        result = self.storage.delete()
        self.assertTrue(result)


if __name__ == "__main__":
    unittest.main()
