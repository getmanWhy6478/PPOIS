import unittest
from document import Document
from exceptions import InvalidDocumentError
from interfaces import IPrintable


class TestDocument(unittest.TestCase):
    """Тесты класса Document"""

    # ========================================
    # Инициализация
    # ========================================

    def test_create_valid_document(self):
        """Тест: успешное создание документа"""
        doc = Document("test.pdf", "PDF", 5, 2.5)

        self.assertEqual(doc.filename, "test.pdf")
        self.assertEqual(doc.format, "PDF")
        self.assertEqual(doc.pages, 5)
        self.assertEqual(doc.size_mb, 2.5)

    def test_format_uppercase(self):
        """Тест: формат преобразуется в верхний регистр"""
        doc = Document("file.jpg", "jpg", 3, 1.0)
        self.assertEqual(doc.format, "JPG")

    def test_pages_min_value_negative(self):
        """Тест: минимальное значение страниц для отрицательного значения"""
        doc = Document("file.pdf", "PDF", -5, 1.0)
        self.assertEqual(doc.pages, 1)

    def test_pages_min_value_zero(self):
        """Тест: минимальное значение страниц для нулевого значения"""
        doc = Document("file.pdf", "PDF", 0, 1.0)
        self.assertEqual(doc.pages, 1)

    def test_pages_min_value_one(self):
        """Тест: минимальное значение страниц = 1"""
        doc = Document("file.pdf", "PDF", 1, 1.0)
        self.assertEqual(doc.pages, 1)

    def test_pages_valid_value(self):
        """Тест: корректное значение страниц"""
        doc = Document("file.pdf", "PDF", 10, 1.0)
        self.assertEqual(doc.pages, 10)

    def test_size_mb_min_value_negative(self):
        """Тест: минимальное значение размера для отрицательного значения"""
        doc = Document("file.pdf", "PDF", 1, -2.0)
        self.assertEqual(doc.size_mb, 0.01)

    def test_size_mb_min_value_zero(self):
        """Тест: минимальное значение размера для нулевого значения"""
        doc = Document("file.pdf", "PDF", 1, 0.0)
        self.assertEqual(doc.size_mb, 0.01)

    def test_size_mb_min_value_boundary(self):
        """Тест: минимальное значение размера = 0.01"""
        doc = Document("file.pdf", "PDF", 1, 0.01)
        self.assertEqual(doc.size_mb, 0.01)

    def test_size_mb_valid_value(self):
        """Тест: корректное значение размера"""
        doc = Document("file.pdf", "PDF", 1, 5.0)
        self.assertEqual(doc.size_mb, 5.0)

    # ========================================
    # Валидация
    # ========================================

    def test_validate_valid(self):
        """Тест: валидный документ проходит проверку"""
        doc = Document("valid.pdf", "PDF", 5, 2.0)
        self.assertTrue(doc.validate())
    # ========================================
    # Поддерживаемые форматы
    # ========================================

    def test_all_supported_formats_work(self):
        """Тест: все поддерживаемые форматы работают"""
        formats = ['PDF', 'JPG', 'JPEG', 'PNG', 'TXT', 'DOCX']

        for fmt in formats:
            with self.subTest(format=fmt):
                doc = Document(f"file.{fmt.lower()}", fmt, 1, 1.0)
                self.assertEqual(doc.format, fmt)
                self.assertTrue(doc.validate())

    def test_case_variations_of_formats_lowercase(self):
        """Тест: форматы в нижнем регистре преобразуются правильно"""
        doc = Document("file", "pdf", 1, 1.0)
        self.assertEqual(doc.format, "PDF")

    def test_case_variations_of_formats_mixed(self):
        """Тест: форматы в смешанном регистре преобразуются правильно"""
        doc = Document("file", "PnG", 1, 1.0)
        self.assertEqual(doc.format, "PNG")

    # ========================================
    # Исключения
    # ========================================

    def test_invalid_format_raises_error(self):
        """Тест: некорректный формат вызывает исключение"""
        with self.assertRaises(InvalidDocumentError):
            Document("file.exe", "EXE", 1, 1.0)

    def test_exception_message_contains_filename(self):
        """Тест: сообщение об ошибке содержит имя файла"""
        with self.assertRaises(InvalidDocumentError) as context:
            Document("invalid.exe", "EXE", 1, 1.0)

        self.assertIn("invalid.exe", str(context.exception))

    # ========================================
    # Интерфейс
    # ========================================

    def test_implements_iprintable(self):
        """Тест: класс реализует интерфейс IPrintable"""
        doc = Document("test.pdf", "PDF", 5, 2.0)

        self.assertIsInstance(doc, IPrintable)
        self.assertTrue(hasattr(doc, 'filename'))
        self.assertTrue(hasattr(doc, 'format'))
        self.assertTrue(hasattr(doc, 'pages'))
        self.assertTrue(hasattr(doc, 'size_mb'))

    def test_document_has_all_properties(self):
        """Тест: документ имеет все необходимые свойства"""
        doc = Document("test.pdf", "PDF", 5, 2.0)

        self.assertIsNotNone(doc.filename)
        self.assertIsNotNone(doc.format)
        self.assertIsNotNone(doc.pages)
        self.assertIsNotNone(doc.size_mb)

    # ========================================
    # Свойства (только для чтения)
    # ========================================

    def test_properties_readonly(self):
        """Тест: свойства доступны только для чтения"""
        doc = Document("test.pdf", "PDF", 5, 2.0)

        with self.assertRaises(AttributeError):
            doc.filename = "new.pdf"

        with self.assertRaises(AttributeError):
            doc.format = "TXT"

        with self.assertRaises(AttributeError):
            doc.pages = 20

        with self.assertRaises(AttributeError):
            doc.size_mb = 5.0

    # ========================================
    # Граничные значения
    # ========================================

    def test_minimum_pages(self):
        """Тест: минимальное значение страниц"""
        doc = Document("file.pdf", "PDF", 1, 0.01)
        self.assertEqual(doc.pages, 1)
        self.assertTrue(doc.validate())

    def test_minimum_size(self):
        """Тест: минимальное значение размера"""
        doc = Document("file.pdf", "PDF", 1, 0.01)
        self.assertEqual(doc.size_mb, 0.01)
        self.assertTrue(doc.validate())

    def test_large_values(self):
        """Тест: большие значения параметров"""
        doc = Document("big.pdf", "PDF", 10000, 1000.0)
        self.assertEqual(doc.pages, 10000)
        self.assertEqual(doc.size_mb, 1000.0)
        self.assertTrue(doc.validate())

    # ========================================
    # Интеграционные тесты
    # ========================================

    def test_full_workflow(self):
        """Тест: полный цикл создания и валидации документа"""
        # Создаём валидный документ
        doc = Document("report.pdf", "PDF", 10, 2.5)

        # Проверяем свойства
        self.assertEqual(doc.filename, "report.pdf")
        self.assertEqual(doc.format, "PDF")
        self.assertEqual(doc.pages, 10)
        self.assertEqual(doc.size_mb, 2.5)

        # Проверяем валидацию
        self.assertTrue(doc.validate())

        # Проверяем интерфейс
        self.assertIsInstance(doc, IPrintable)

    def test_document_with_various_formats(self):
        """Тест: документы с различными форматами"""
        test_cases = [
            ("document.pdf", "PDF", 5, 1.0),
            ("image.jpg", "JPG", 1, 2.0),
            ("photo.png", "PNG", 1, 3.0),
            ("notes.txt", "TXT", 10, 0.5),
            ("report.docx", "DOCX", 20, 1.5),
        ]

        for filename, fmt, pages, size in test_cases:
            with self.subTest(filename=filename):
                doc = Document(filename, fmt, pages, size)
                self.assertEqual(doc.format, fmt)
                self.assertTrue(doc.validate())


if __name__ == '__main__':
    unittest.main(verbosity=2)
