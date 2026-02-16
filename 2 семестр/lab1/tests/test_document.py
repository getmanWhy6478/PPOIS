"""Unit-тесты для document.Document и проверки IPrintable."""

import unittest

from document import Document
from exceptions import InvalidDocumentError


class TestDocument(unittest.TestCase):
    """Тесты модели документа."""

    def test_create_valid_document(self) -> None:
        doc = Document("report.pdf", "PDF", 5, 1.2)
        self.assertEqual(doc.filename, "report.pdf")
        self.assertEqual(doc.format, "PDF")
        self.assertEqual(doc.pages, 5)
        self.assertAlmostEqual(doc.size_mb, 1.2)
        self.assertTrue(doc.validate())

    def test_format_normalized_to_upper(self) -> None:
        doc = Document("img.jpg", "jpg", 1, 0.5)
        self.assertEqual(doc.format, "JPG")

    def test_pages_min_one(self) -> None:
        doc = Document("x.txt", "TXT", 0, 0.1)
        self.assertEqual(doc.pages, 1)

    def test_size_mb_min(self) -> None:
        doc = Document("x.pdf", "PDF", 1, 0.0)
        self.assertGreaterEqual(doc.size_mb, 0.01)

    def test_invalid_format_raises(self) -> None:
        with self.assertRaises(InvalidDocumentError):
            Document("file.xyz", "XYZ", 1, 0.1)

    def test_validate_rejects_unsupported_format(self) -> None:
        # Создаём документ с допустимым форматом, затем проверяем валидацию форматов
        for fmt in ("PDF", "JPG", "PNG", "TXT", "DOCX"):
            doc = Document("a." + fmt.lower(), fmt, 1, 0.1)
            self.assertTrue(doc.validate(), f"Format {fmt} should be valid")
        doc = Document("a.pdf", "PDF", 1, 0.1)
        doc._format = "UNSUPPORTED"
        self.assertFalse(doc.validate())

    def test_validate_rejects_zero_pages(self) -> None:
        doc = Document("a.pdf", "PDF", 2, 0.1)
        doc._pages = 0
        self.assertFalse(doc.validate())

    def test_validate_rejects_zero_size(self) -> None:
        doc = Document("a.pdf", "PDF", 1, 0.1)
        doc._size_mb = 0
        self.assertFalse(doc.validate())

    def test_str_representation(self) -> None:
        doc = Document("doc.pdf", "PDF", 3, 0.5)
        s = str(doc)
        self.assertIn("doc.pdf", s)
        self.assertIn("PDF", s)
        self.assertIn("3", s)
        self.assertIn("0.50", s)


if __name__ == "__main__":
    unittest.main()
