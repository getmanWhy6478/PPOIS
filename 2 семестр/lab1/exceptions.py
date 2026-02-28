from typing import Optional

class PrinterException(Exception):
    """Базовое исключение системы печати"""
    def __init__(self, message: str, printer_state: Optional[str] = None):
        self.printer_state = printer_state
        super().__init__(message)

class OutOfPaperError(PrinterException):
    """Ошибка: закончилась бумага"""
    pass

class LowInkError(PrinterException):
    """Ошибка: низкий уровень чернил"""
    pass

class HardwareError(PrinterException):
    """Ошибка: аппаратная неисправность"""
    pass

class InvalidDocumentError(PrinterException):
    """Ошибка: недопустимый формат документа"""
    pass