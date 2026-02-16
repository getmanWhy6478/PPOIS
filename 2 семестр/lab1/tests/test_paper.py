"""Unit-тесты для paper.Paper и paper.InkCartridge."""

import unittest

from paper import Paper
from cartridge import InkCartridge
from exceptions import PrinterException


class TestPaper(unittest.TestCase):
    """Тесты модели бумаги."""

    def test_create_default_a4(self) -> None:
        p = Paper()
        self.assertEqual(p.type, "A4")
        self.assertEqual(p.quantity, 100)
        self.assertFalse(p.is_empty)

    def test_create_custom_type_and_quantity(self) -> None:
        p = Paper("A3", 50)
        self.assertEqual(p.type, "A3")
        self.assertEqual(p.quantity, 50)

    def test_type_normalized_to_upper(self) -> None:
        p = Paper("letter", 10)
        self.assertEqual(p.type, "LETTER")

    def test_invalid_type_raises(self) -> None:
        with self.assertRaises(ValueError) as ctx:
            Paper("invalid", 10)
        self.assertIn("бумаги", str(ctx.exception).lower() or "бумаги")

    def test_quantity_negative_becomes_zero(self) -> None:
        p = Paper(quantity=-5)
        self.assertEqual(p.quantity, 0)
        self.assertTrue(p.is_empty)

    def test_consume_reduces_quantity(self) -> None:
        p = Paper("A4", 10)
        p.consume(3)
        self.assertEqual(p.quantity, 7)
        p.consume(1)
        self.assertEqual(p.quantity, 6)

    def test_consume_zero_or_negative_raises(self) -> None:
        p = Paper("A4", 10)
        with self.assertRaises(ValueError):
            p.consume(0)
        with self.assertRaises(ValueError):
            p.consume(-1)

    def test_consume_when_empty_raises(self) -> None:
        p = Paper("A4", 0)
        with self.assertRaises(PrinterException) as ctx:
            p.consume(1)
        self.assertEqual(ctx.exception.printer_state, "OUT_OF_PAPER")

    def test_refill_increases_quantity(self) -> None:
        p = Paper("A4", 5)
        p.refill(20)
        self.assertEqual(p.quantity, 25)

    def test_refill_zero_or_negative_raises(self) -> None:
        p = Paper("A4", 10)
        with self.assertRaises(ValueError):
            p.refill(0)
        with self.assertRaises(ValueError):
            p.refill(-5)

    def test_str_contains_type_and_status(self) -> None:
        p = Paper("A4", 10)
        s = str(p)
        self.assertIn("A4", s)
        self.assertIn("10", s)


class TestInkCartridge(unittest.TestCase):
    """Тесты модели картриджа."""

    def test_create_default_full(self) -> None:
        c = InkCartridge("K")
        self.assertEqual(c.color, "K")
        self.assertEqual(c.capacity, 10.0)
        self.assertAlmostEqual(c.level, 10.0)
        self.assertAlmostEqual(c.level_percent, 100.0)
        self.assertFalse(c.is_empty)

    def test_create_custom_level(self) -> None:
        c = InkCartridge("C", capacity_ml=10.0, current_level=5.0)
        self.assertAlmostEqual(c.level, 5.0)
        self.assertAlmostEqual(c.level_percent, 50.0)

    def test_color_normalized_to_upper(self) -> None:
        c = InkCartridge("m")
        self.assertEqual(c.color, "M")

    def test_invalid_color_raises(self) -> None:
        with self.assertRaises(ValueError) as ctx:
            InkCartridge("RED")
        self.assertIn("чернил", str(ctx.exception).lower() or "чернил")

    def test_consume_reduces_level(self) -> None:
        c = InkCartridge("K", capacity_ml=10.0, current_level=10.0)
        c.consume(2.0)
        self.assertAlmostEqual(c.level, 8.0)
        self.assertAlmostEqual(c.level_percent, 80.0)

    def test_consume_zero_or_negative_raises(self) -> None:
        c = InkCartridge("K")
        with self.assertRaises(ValueError):
            c.consume(0)
        with self.assertRaises(ValueError):
            c.consume(-0.5)

    def test_consume_when_empty_raises(self) -> None:
        c = InkCartridge("K", capacity_ml=10.0, current_level=0.05)
        with self.assertRaises(PrinterException) as ctx:
            c.consume(0.1)
        self.assertEqual(ctx.exception.printer_state, "LOW_INK")

    def test_is_empty_at_low_level(self) -> None:
        c = InkCartridge("K", capacity_ml=10.0, current_level=0.05)
        self.assertTrue(c.is_empty)

    def test_refill_restores_capacity(self) -> None:
        c = InkCartridge("K", capacity_ml=10.0, current_level=2.0)
        c.refill()
        self.assertAlmostEqual(c.level, 10.0)
        self.assertAlmostEqual(c.level_percent, 100.0)


if __name__ == "__main__":
    unittest.main()
