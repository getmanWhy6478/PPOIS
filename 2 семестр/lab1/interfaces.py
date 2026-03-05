from abc import ABC, abstractmethod
from settings import PrintSettings

class IPrintable(ABC):

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

    @property
    @abstractmethod
    def is_empty(self) -> bool:
        pass

    @abstractmethod
    def consume(self, amount: float) -> None:
        pass


class IDriver(ABC):

    @abstractmethod
    def initialize(self) -> bool:
        pass

    @abstractmethod
    def send_print_command(self, document: IPrintable, settings: PrintSettings) -> bool:
        pass

    @abstractmethod
    def run_maintenance(self, operation: str) -> bool:
        pass