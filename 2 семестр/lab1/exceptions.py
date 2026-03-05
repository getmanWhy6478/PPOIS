from typing import Optional

class PrinterException(Exception):
    def __init__(self, message: str, printer_state: Optional[str] = None):
        self.printer_state = printer_state
        super().__init__(message)

class OutOfPaperError(PrinterException):
    pass

class LowInkError(PrinterException):
    pass

class HardwareError(PrinterException):
    pass

class InvalidDocumentError(PrinterException):
    pass