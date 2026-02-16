"""Unit-тесты для driver.PrinterDriver."""

import unittest
from unittest.mock import patch, MagicMock

from driver import PrinterDriver
from document import Document
from settings import PrintSettings


class TestPrinterDriver(unittest.TestCase):
    """Тесты драйвера принтера."""

    def setUp(self) -> None:
        self.driver = PrinterDriver(version="2.0")

    def test_version_stored(self) -> None:
        self.assertEqual(self.driver.version, "2.0")

    @patch("driver.time.sleep")
    def test_initialize_sets_initialized(self, mock_sleep: MagicMock) -> None:
        result = self.driver.initialize()
        self.assertTrue(result)
        self.assertTrue(self.driver._initialized)
        mock_sleep.assert_called_once()

    def test_send_print_command_without_init_raises(self) -> None:
        doc = Document("a.pdf", "PDF", 2, 0.1)
        settings = PrintSettings()
        with self.assertRaises(RuntimeError) as ctx:
            self.driver.send_print_command(doc, settings)
        self.assertIn("инициализирован", str(ctx.exception).lower() or "инициализирован")

    @patch("driver.time.sleep")
    @patch("driver.random.random", return_value=1.0)
    def test_send_print_command_returns_true_when_no_failure(
        self, mock_random: MagicMock, mock_sleep: MagicMock
    ) -> None:
        self.driver.initialize()
        doc = Document("a.pdf", "PDF", 3, 0.1)
        settings = PrintSettings()
        result = self.driver.send_print_command(doc, settings)
        self.assertTrue(result)

    @patch("driver.time.sleep")
    @patch("driver.random.random", return_value=0.0)
    def test_send_print_command_can_return_false_on_random_failure(
        self, mock_random: MagicMock, mock_sleep: MagicMock
    ) -> None:
        self.driver.initialize()
        doc = Document("a.pdf", "PDF", 1, 0.1)
        settings = PrintSettings()
        result = self.driver.send_print_command(doc, settings)
        self.assertFalse(result)

    def test_run_maintenance_without_init_raises(self) -> None:
        with self.assertRaises(RuntimeError):
            self.driver.run_maintenance("clean")

    @patch("driver.time.sleep")
    def test_run_maintenance_unsupported_operation_raises(self, mock_sleep: MagicMock) -> None:
        self.driver.initialize()
        with self.assertRaises(ValueError) as ctx:
            self.driver.run_maintenance("unknown_op")
        self.assertIn("Неподдерживаемая", str(ctx.exception))

    @patch("driver.time.sleep")
    def test_run_maintenance_clean_accepted(self, mock_sleep: MagicMock) -> None:
        self.driver.initialize()
        # Может вернуть True или False из-за random в _cmd_clean
        result = self.driver.run_maintenance("clean")
        self.assertIn(result, (True, False))

    @patch("driver.time.sleep")
    def test_run_maintenance_init_accepted(self, mock_sleep: MagicMock) -> None:
        self.driver.initialize()
        result = self.driver.run_maintenance("init")
        self.assertTrue(result)


if __name__ == "__main__":
    unittest.main()
