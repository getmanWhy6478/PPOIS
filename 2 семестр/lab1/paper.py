from interfaces import IConsumable
from exceptions import PrinterException


class Paper(IConsumable):
    """Модель бумаги как расходного материала"""
    VALID_TYPES = {'A4', 'A3', 'PHOTO', 'LETTER'}

    def __init__(self, paper_type: str = 'A4', quantity: int = 100):
        if paper_type.upper() not in self.VALID_TYPES:
            raise ValueError(f"Недопустимый тип бумаги: {paper_type}")

        self._type = paper_type.upper()
        self._quantity = max(0, quantity)

    @property
    def type(self) -> str:
        return self._type

    @property
    def quantity(self) -> int:
        return self._quantity

    @property
    def is_empty(self) -> bool:
        return self._quantity <= 0

    def consume(self, amount: int = 1) -> None:
        if amount <= 0:
            raise ValueError("Количество должно быть положительным")
        if self.is_empty:
            raise PrinterException("Попытка использовать пустой лоток бумаги", "OUT_OF_PAPER")
        self._quantity = max(0, self._quantity - amount)

    def refill(self, quantity: int) -> None:
        if quantity <= 0:
            raise ValueError("Количество для заполнения должно быть положительным")
        self._quantity += quantity


