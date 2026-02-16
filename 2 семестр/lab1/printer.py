from enum import Enum
from typing import List, Optional
from interfaces import IPrintable, IDriver
from paper import Paper
from cartridge import  InkCartridge
from settings import PrintSettings
from exceptions import (
    OutOfPaperError, LowInkError,
    HardwareError, PrinterException
)

class PrinterState(Enum):
    """Состояния принтера"""
    OFF = "off"
    IDLE = "idle"
    PRINTING = "printing"
    PAUSED = "paused"
    OUT_OF_PAPER = "out_of_paper"
    LOW_INK = "low_ink"
    ERROR = "error"
    MAINTENANCE = "maintenance"


class Printer:
    """Основной класс принтера с управлением состояниями"""

    INK_CONSUMPTION_RATES = 0.1
    def __init__(self, model: str, driver: IDriver):
        self._model = model
        self._driver = driver
        self._state = PrinterState.OFF
        self._paper = Paper()
        self._cartridges: List[InkCartridge] = [
            InkCartridge('C'),
            InkCartridge('M'),
            InkCartridge('Y'),
            InkCartridge('K')
        ]
        self._maintenance_count = 0

    @property
    def model(self) -> str:
        return self._model

    @property
    def state(self) -> PrinterState:
        return self._state

    @property
    def paper(self) -> Paper:
        return self._paper

    @property
    def cartridges(self) -> List[InkCartridge]:
        return self._cartridges.copy()

    def power_on(self) -> bool:
        """Включение принтера"""
        if self._state != PrinterState.OFF:
            return False

        try:
            if not self._driver.initialize():
                self._state = PrinterState.ERROR
                return False

            # Проверка базовой конфигурации
            if self._paper.is_empty:
                self._state = PrinterState.OUT_OF_PAPER
            elif any(c.level_percent < 10 for c in self._cartridges):
                self._state = PrinterState.LOW_INK
            else:
                self._state = PrinterState.IDLE

            return True
        except Exception as e:
            self._state = PrinterState.ERROR
            raise HardwareError(f"Ошибка включения: {str(e)}", "ERROR")

    def power_off(self) -> bool:
        """Выключение принтера"""
        if self._state == PrinterState.OFF:
            return False

        self._state = PrinterState.OFF
        return True

    def print_document(self, document: IPrintable, settings: Optional[PrintSettings] = None) -> bool:
        """Печать документа с полной проверкой состояния"""
        if self._state != PrinterState.IDLE:
            raise PrinterException(
                f"Печать невозможна в состоянии {self._state.value}",
                self._state.value
            )

        # Применение настроек по умолчанию
        settings = settings or PrintSettings()

        # Проверка расходников
        self._check_consumables(settings.copies * document.pages)

        try:
            # Установка состояния печати
            self._state = PrinterState.PRINTING

            # Расчет потребления ресурсов
            pages_to_print = settings.copies * document.pages
            ink_per_page = self.INK_CONSUMPTION_RATES

            # Имитация постраничной печати
            for page_num in range(1, pages_to_print + 1):
                # Потребление бумаги
                self._paper.consume(1)

                # Потребление чернил (для цветной печати используем все картриджи)
                if settings.color_mode == 'color':
                    for cartridge in self._cartridges:
                        cartridge.consume(ink_per_page / 4)  # делим между 4 картриджами
                else:
                    # Для монохромной печати используем только черный
                    self._get_black_cartridge().consume(ink_per_page)

                # Проверка критических уровней после каждой страницы
                if self._paper.is_empty:
                    raise OutOfPaperError("Закончилась бумага во время печати", "OUT_OF_PAPER")

                if any(c.is_empty for c in self._cartridges):
                    raise LowInkError("Закончились чернила во время печати", "LOW_INK")

            # Отправка команды драйверу
            success = self._driver.send_print_command(document, settings)

            if not success:
                self._state = PrinterState.ERROR
                raise HardwareError("Сбой печати на аппаратном уровне", "ERROR")

            # Возврат в состояние ожидания
            self._state = PrinterState.IDLE
            return True

        except Exception as e:
            self._state = PrinterState.ERROR
            raise

    def _check_consumables(self, pages_needed: int) -> None:
        """Проверка достаточности расходников перед печатью"""
        # Проверка бумаги
        if self._paper.quantity < pages_needed:
            self._state = PrinterState.OUT_OF_PAPER
            raise OutOfPaperError(
                f"Недостаточно бумаги: нужно {pages_needed}, доступно {self._paper.quantity}",
                "OUT_OF_PAPER"
            )

        # Проверка чернил
        for cartridge in self._cartridges:
            if cartridge.level_percent < 5:  # критический уровень
                self._state = PrinterState.LOW_INK
                raise LowInkError(
                    f"Критически низкий уровень чернил в картридже {cartridge.color}",
                    "LOW_INK"
                )

    def _get_black_cartridge(self) -> InkCartridge:
        """Получение черного картриджа"""
        for c in self._cartridges:
            if c.color == 'K':
                return c
        raise RuntimeError("Черный картридж не найден")

    def load_paper(self, quantity: int = 100) -> None:
        """Загрузка бумаги"""
        if self._state == PrinterState.OFF:
            raise PrinterException("Невозможно загрузить бумагу при выключенном принтере", "OFF")

        self._paper.refill(quantity)

        # Автоматический переход в состояние ожидания при наличии бумаги и достаточных чернилах
        if self._state == PrinterState.OUT_OF_PAPER:
            if all(c.level_percent >= 10 for c in self._cartridges):
                self._state = PrinterState.IDLE

    def replace_ink(self, color: str) -> None:
        """Замена картриджа указанного цвета"""
        if self._state == PrinterState.OFF:
            raise PrinterException("Невозможно заменить чернила при выключенном принтере", "OFF")

        color_upper = color.upper()
        for cartridge in self._cartridges:
            if cartridge.color == color_upper:
                cartridge.refill()
                break
        else:
            raise ValueError(f"Картридж цвета {color} не найден")

        # Проверка, можно ли вернуться в состояние ожидания
        if self._state == PrinterState.LOW_INK:
            if not any(c.level_percent < 10 for c in self._cartridges):
                self._state = PrinterState.IDLE

    def start_maintenance(self, operation: str = 'clean') -> bool:
        """Запуск операции обслуживания"""
        if self._state not in (PrinterState.IDLE, PrinterState.ERROR):
            raise PrinterException(
                f"Обслуживание невозможно в состоянии {self._state.value}",
                self._state.value
            )

        previous_state = self._state
        self._state = PrinterState.MAINTENANCE

        try:
            success = self._driver.run_maintenance(operation)
            self._maintenance_count += 1

            if success:
                # После успешного обслуживания возвращаемся в исходное состояние или в ожидание
                if previous_state == PrinterState.ERROR:
                    self._state = PrinterState.IDLE
                else:
                    self._state = previous_state
                return True
            else:
                self._state = PrinterState.ERROR
                return False
        except Exception as e:
            self._state = PrinterState.ERROR
            raise HardwareError(f"Ошибка обслуживания: {str(e)}", "ERROR")

    def get_status(self) -> dict:
        """Получение полного статуса принтера"""
        return {
            'model': self._model,
            'state': self._state.value,
            'paper': {
                'type': self._paper.type,
                'quantity': self._paper.quantity,
                'is_empty': self._paper.is_empty
            },
            'cartridges': [
                {
                    'color': c.color,
                    'level_percent': c.level_percent,
                    'level_ml': c.level,
                    'capacity_ml': c.capacity,
                    'is_empty': c.is_empty
                }
                for c in self._cartridges
            ],
            'maintenance_count': self._maintenance_count
        }

    def to_dict(self) -> dict:
        """Сериализация состояния принтера"""
        return {
            'model': self._model,
            'state': self._state.value,
            'paper': {
                'type': self._paper.type,
                'quantity': self._paper.quantity,
            },
            'cartridges': [
                {
                    'color': c.color,
                    'capacity': c.capacity,
                    'level': c.level
                }
                for c in self._cartridges
            ],
            'maintenance_count': self._maintenance_count
        }

    @classmethod
    def from_dict(cls, data: dict, driver: IDriver) -> 'Printer':
        """Десериализация состояния принтера"""
        printer = cls(data['model'], driver)

        # Восстановление состояния бумаги
        printer._paper = Paper(
            paper_type=data['paper']['type'],
            quantity=data['paper']['quantity'],
        )

        # Восстановление состояния картриджей
        printer._cartridges = [
            InkCartridge(
                color=c['color'],
                capacity_ml=c['capacity'],
                current_level=c['level']
            )
            for c in data['cartridges']
        ]

        # Восстановление счетчика обслуживания
        printer._maintenance_count = data.get('maintenance_count', 0)

        # Восстановление состояния (без включения питания)
        try:
            printer._state = PrinterState(data['state'])
        except ValueError:
            printer._state = PrinterState.OFF

        return printer