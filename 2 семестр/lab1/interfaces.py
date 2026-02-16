from abc import ABC, abstractmethod
from settings import PrintSettings

class IPrintable(ABC):
    """Интерфейс печатаемого документа"""

    @property
    @abstractmethod
    def format(self) -> str:
        pass

    @property
    @abstractmethod
    def pages(self) -> int:
        pass

    @abstractmethod
    def validate(self) -> bool:
        pass


class IConsumable(ABC):
    """Интерфейс расходного материала"""

    @property
    @abstractmethod
    def is_empty(self) -> bool:
        pass

    @abstractmethod
    def consume(self, amount: float) -> None:
        pass


class IDriver(ABC):
    """Интерфейс драйвера принтера"""

    @abstractmethod
    def initialize(self) -> bool:
        pass

    @abstractmethod
    def send_print_command(self, document: IPrintable, settings: PrintSettings) -> bool:
        pass

    @abstractmethod
    def run_maintenance(self, operation: str) -> bool:
        pass