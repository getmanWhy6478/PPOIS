from interfaces import IConsumable
from exceptions import PrinterException

class InkCartridge(IConsumable):
    """Модель картриджа с чернилами"""
    VALID_COLORS = {'C', 'M', 'Y', 'K', 'BK'}  # Cyan, Magenta, Yellow, Black, Black (photo)

    def __init__(self, color: str, capacity_ml: float = 10.0, current_level: float = None):
        if color.upper() not in self.VALID_COLORS:
            raise ValueError(f"Недопустимый цвет чернил: {color}")

        self._color = color.upper()
        self._capacity = max(0.1, capacity_ml)
        self._level = current_level if current_level is not None else self._capacity

    @property
    def color(self) -> str:
        return self._color

    @property
    def capacity(self) -> float:
        return self._capacity

    @property
    def level(self) -> float:
        return round(self._level, 2)

    @property
    def level_percent(self) -> float:
        return round((self._level / self._capacity) * 100, 1)

    @property
    def is_empty(self) -> bool:
        return self._level <= 0.1  # 1% от емкости считается пустым

    def consume(self, amount_ml: float) -> None:
        if amount_ml <= 0:
            raise ValueError("Количество чернил должно быть положительным")
        if self.is_empty:
            raise PrinterException(f"Картридж {self._color} пуст", "LOW_INK")
        self._level = max(0.0, self._level - amount_ml)

    def refill(self) -> None:
        self._level = self._capacity

    def __str__(self) -> str:
        status = "пустой" if self.is_empty else f"{self.level_percent}%"
        return f"Чернила {self._color}: {status} ({self._level:.1f}мл/{self._capacity:.1f}мл)"