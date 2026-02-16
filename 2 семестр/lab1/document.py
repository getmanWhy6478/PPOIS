from interfaces import IPrintable
from exceptions import InvalidDocumentError
from typing import Union


class Document(IPrintable):
    """Модель печатаемого документа"""
    SUPPORTED_FORMATS = {'PDF', 'JPG', 'JPEG', 'PNG', 'TXT', 'DOCX'}

    def __init__(self, filename: str, format: str, pages: int, size_mb: float):
        self._filename = filename
        self._format = format.upper()
        self._pages = max(1, pages)
        self._size_mb = max(0.01, size_mb)

        if not self.validate():
            raise InvalidDocumentError(f"Недопустимый документ: {filename}")

    @property
    def filename(self) -> str:
        return self._filename

    @property
    def format(self) -> str:
        return self._format

    @property
    def pages(self) -> int:
        return self._pages

    @property
    def size_mb(self) -> float:
        return self._size_mb

    def validate(self) -> bool:
        if self._format not in self.SUPPORTED_FORMATS:
            return False
        if self._pages <= 0:
            return False
        if self._size_mb <= 0:
            return False
        return True

    def __str__(self) -> str:
        return f"Документ '{self._filename}' ({self._format}, {self._pages} стр., {self._size_mb:.2f}МБ)"