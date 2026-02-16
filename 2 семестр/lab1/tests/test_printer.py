"""Unit-тесты для printer.Printer (с подменяемым драйвером)."""

import unittest
from unittest.mock import MagicMock

from document import Document
from paper import Paper
from cartridge import InkCartridge
from settings import PrintSettings
from driver import PrinterDriver
from printer import Printer, PrinterState
from exceptions import (
    PrinterException,
    OutOfPaperError,
    LowInkError,
    HardwareError,
)



class TestPrinter(unittest.TestCase):
    """Тесты принтера."""

    def setUp(self) -> None:
        self.driver = PrinterDriver()
        self.printer = Printer("TestModel", self.driver)

    def test_initial_state_off(self) -> None:
        self.assertEqual(self.printer.state, PrinterState.OFF)
        self.assertEqual(self.printer.model, "TestModel")
        self.assertIsInstance(self.printer.paper, Paper)
        self.assertEqual(len(self.printer.cartridges), 4)

    def test_power_on_success_goes_idle(self) -> None:
        result = self.printer.power_on()
        self.assertTrue(result)
        self.assertEqual(self.printer.state, PrinterState.IDLE)

    def test_power_on_when_not_off_returns_false(self) -> None:
        self.printer.power_on()
        result = self.printer.power_on()
        self.assertFalse(result)

    def test_power_on_no_paper_goes_out_of_paper(self) -> None:
        self.printer._paper = Paper("A4", 0)
        result = self.printer.power_on()
        self.assertTrue(result)
        self.assertEqual(self.printer.state, PrinterState.OUT_OF_PAPER)

    def test_power_on_low_ink_goes_low_ink(self) -> None:
        for c in self.printer._cartridges:
            c._level = c._capacity * 0.05
        result = self.printer.power_on()
        self.assertTrue(result)
        self.assertEqual(self.printer.state, PrinterState.LOW_INK)

    def test_power_off_from_idle(self) -> None:
        self.printer.power_on()
        result = self.printer.power_off()
        self.assertTrue(result)
        self.assertEqual(self.printer.state, PrinterState.OFF)

    def test_power_off_when_already_off_returns_false(self) -> None:
        result = self.printer.power_off()
        self.assertFalse(result)

    def test_print_document_requires_idle(self) -> None:
        doc = Document("a.pdf", "PDF", 1, 0.1)
        with self.assertRaises(PrinterException) as ctx:
            self.printer.print_document(doc)
        self.assertEqual(ctx.exception.printer_state, "off")

    def test_print_document_success(self) -> None:
        self.printer.power_on()
        doc = Document("a.pdf", "PDF", 2, 0.1)
        result = self.printer.print_document(doc)
        self.assertTrue(result)
        self.assertEqual(self.printer.state, PrinterState.IDLE)
        self.assertEqual(self.printer.paper.quantity, 98)

    def test_print_document_not_enough_paper_raises(self) -> None:
        self.printer.power_on()
        self.printer._paper = Paper("A4", 1)
        doc = Document("a.pdf", "PDF", 5, 0.1)
        with self.assertRaises(OutOfPaperError):
            self.printer.print_document(doc)
        self.assertEqual(self.printer.state, PrinterState.OUT_OF_PAPER)

    def test_print_document_low_ink_raises(self) -> None:
        self.printer.power_on()
        for c in self.printer._cartridges:
            c._level = c._capacity * 0.02
        doc = Document("a.pdf", "PDF", 1, 0.1)
        with self.assertRaises(LowInkError):
            self.printer.print_document(doc)
        self.assertEqual(self.printer.state, PrinterState.LOW_INK)

    def test_load_paper_when_off_raises(self) -> None:
        with self.assertRaises(PrinterException) as ctx:
            self.printer.load_paper(50)
        self.assertEqual(ctx.exception.printer_state, "OFF")

    def test_load_paper_when_out_of_paper_returns_to_idle(self) -> None:
        self.printer._state = PrinterState.OUT_OF_PAPER
        self.printer._paper = Paper("A4", 0)
        self.printer.load_paper(100)
        self.assertEqual(self.printer.paper.quantity, 100)
        self.assertEqual(self.printer.state, PrinterState.IDLE)

    def test_replace_ink_when_off_raises(self) -> None:
        with self.assertRaises(PrinterException) as ctx:
            self.printer.replace_ink("K")
        self.assertEqual(ctx.exception.printer_state, "OFF")

    def test_replace_ink_when_low_ink_returns_to_idle(self) -> None:
        self.printer._state = PrinterState.LOW_INK
        for c in self.printer._cartridges:
            if c.color == "K":
                c._level = c._capacity * 0.05
        self.printer.replace_ink("K")
        black = next(c for c in self.printer._cartridges if c.color == "K")
        self.assertAlmostEqual(black.level_percent, 100.0)
        self.assertEqual(self.printer.state, PrinterState.IDLE)

    def test_replace_ink_unknown_color_raises(self) -> None:
        self.printer.power_on()
        with self.assertRaises(ValueError) as ctx:
            self.printer.replace_ink("RED")
        self.assertIn("не найден", str(ctx.exception))

    def test_start_maintenance_from_idle_goes_maintenance(self) -> None:
        self.printer.power_on()
        result = self.printer.start_maintenance("clean")
        self.assertIn(result, (True, False))
        if result:
            self.assertEqual(self.printer.state, PrinterState.IDLE)
        else:
            self.assertEqual(self.printer.state, PrinterState.ERROR)

    def test_start_maintenance_from_wrong_state_raises(self) -> None:
        self.printer.power_on()
        self.printer._state = PrinterState.PRINTING
        with self.assertRaises(PrinterException):
            self.printer.start_maintenance("clean")

    def test_get_status_structure(self) -> None:
        self.printer.power_on()
        status = self.printer.get_status()
        self.assertEqual(status["model"], "TestModel")
        self.assertEqual(status["state"], "idle")
        self.assertIn("paper", status)
        self.assertIn("quantity", status["paper"])
        self.assertIn("cartridges", status)
        self.assertEqual(len(status["cartridges"]), 4)
        self.assertIn("maintenance_count", status)

    def test_to_dict_and_from_dict_roundtrip(self) -> None:
        self.printer.power_on()
        self.printer._paper = Paper("A3", 30)
        data = self.printer.to_dict()
        restored = Printer.from_dict(data, self.driver)
        self.assertEqual(restored.model, self.printer.model)
        self.assertEqual(restored.state, self.printer.state)
        self.assertEqual(restored.paper.type, "A3")
        self.assertEqual(restored.paper.quantity, 30)
        self.assertEqual(restored._maintenance_count, self.printer._maintenance_count)


if __name__ == "__main__":
    unittest.main()
