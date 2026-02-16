"""Unit-тесты для settings.PrintSettings."""

import unittest

from settings import PrintSettings


class TestPrintSettings(unittest.TestCase):
    """Тесты параметров печати."""

    def test_default_values(self) -> None:
        s = PrintSettings()
        self.assertEqual(s.quality, "normal")
        self.assertEqual(s.color_mode, "color")
        self.assertEqual(s.paper_type, "plain")
        self.assertEqual(s.copies, 1)
        self.assertFalse(s.duplex)

    def test_custom_values(self) -> None:
        s = PrintSettings(
            quality="high",
            color_mode="grayscale",
            paper_type="photo",
            copies=3,
            duplex=True,
        )
        self.assertEqual(s.quality, "high")
        self.assertEqual(s.color_mode, "grayscale")
        self.assertEqual(s.paper_type, "photo")
        self.assertEqual(s.copies, 3)
        self.assertTrue(s.duplex)

    def test_copies_must_be_at_least_one(self) -> None:
        with self.assertRaises(ValueError) as ctx:
            PrintSettings(copies=0)
        self.assertIn("копий", str(ctx.exception).lower() or "копий")

        with self.assertRaises(ValueError):
            PrintSettings(copies=-1)


if __name__ == "__main__":
    unittest.main()
