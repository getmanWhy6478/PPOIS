"""Unit-тесты для иерархии исключений."""

import unittest

from exceptions import (
    PrinterException,
    OutOfPaperError,
    LowInkError,
    PaperJamError,
    HardwareError,
    InvalidDocumentError,
)


class TestExceptions(unittest.TestCase):
    """Тесты исключений системы печати."""

    def test_printer_exception_base(self) -> None:
        exc = PrinterException("Test message", "IDLE")
        self.assertEqual(str(exc), "Test message")
        self.assertEqual(exc.printer_state, "IDLE")

    def test_printer_exception_state_optional(self) -> None:
        exc = PrinterException("Only message")
        self.assertIsNone(exc.printer_state)

    def test_out_of_paper_inherits_printer_exception(self) -> None:
        exc = OutOfPaperError("No paper", "OUT_OF_PAPER")
        self.assertIsInstance(exc, PrinterException)
        self.assertEqual(exc.printer_state, "OUT_OF_PAPER")

    def test_low_ink_inherits_printer_exception(self) -> None:
        exc = LowInkError("Low ink", "LOW_INK")
        self.assertIsInstance(exc, PrinterException)

    def test_paper_jam_inherits_printer_exception(self) -> None:
        exc = PaperJamError("Jam", "PAPER_JAM")
        self.assertIsInstance(exc, PrinterException)

    def test_hardware_error_inherits_printer_exception(self) -> None:
        exc = HardwareError("Hardware failed", "ERROR")
        self.assertIsInstance(exc, PrinterException)

    def test_invalid_document_inherits_printer_exception(self) -> None:
        exc = InvalidDocumentError("Bad format")
        self.assertIsInstance(exc, PrinterException)


if __name__ == "__main__":
    unittest.main()
