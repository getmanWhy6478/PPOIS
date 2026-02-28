from interfaces import IDriver, IPrintable
from settings import PrintSettings
import time
import random


class PrinterDriver(IDriver):
    """Реализация драйвера принтера"""

    def __init__(self):
        self._initialized = False
        self._supported_commands = {
            'init': self.initialize,
            'clean': self._cmd_clean,
            'calibrate': self._cmd_calibrate
        }

    def initialize(self) -> bool:
        """Инициализация драйвера"""
        time.sleep(0.2)  # имитация инициализации
        self._initialized = True
        return True

    def send_print_command(self, document: IPrintable, settings: PrintSettings) -> bool:
        """Отправка команды печати"""
        if not self._initialized:
            raise RuntimeError("Драйвер не инициализирован")

        # Имитация процесса печати
        time.sleep(0.1 * document.pages * (1.5 if settings.quality == 'high' else 1.0))

        # Моделирование возможных ошибок
        if random.random() < 0.005:  # 0.5% вероятность ошибки
            return False
        return True

    def run_maintenance(self, operation: str) -> bool:
        """Выполнение операции обслуживания"""
        if not self._initialized and operation != 'init':
            raise RuntimeError("Драйвер не инициализирован")

        if operation not in self._supported_commands:
            raise ValueError(f"Неподдерживаемая операция: {operation}")

        time.sleep(0.5)  # имитация обслуживания
        return self._supported_commands[operation]()

    def _cmd_clean(self) -> bool:
        return random.random() > 0.02  # 2% вероятность неудачи очистки

    def _cmd_calibrate(self) -> bool:
        return random.random() > 0.01  # 1% вероятность неудачи калибровки