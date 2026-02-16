import json
import os
from pathlib import Path
from typing import Optional
from printer import Printer
from interfaces import IDriver


class PrinterStateStorage:

    def __init__(self, storage_path: str = "printer_state.json"):

        self._storage_path = Path(storage_path)

    def save(self, printer: Printer) -> bool:

        try:
            data = printer.to_dict()
            with open(self._storage_path, 'w', encoding='utf-8') as f:
                json.dump(data, f, ensure_ascii=False, indent=2)
            return True
        except (OSError, json.JSONDecodeError):
            return False

    def load(self, driver: IDriver) -> Optional[Printer]:

        if not self._storage_path.exists():
            return None

        try:
            with open(self._storage_path, 'r', encoding='utf-8') as f:
                data = json.load(f)
            return Printer.from_dict(data, driver)
        except (json.JSONDecodeError, KeyError, OSError):
            return None

    def exists(self) -> bool:
        """Проверяет, существует ли файл с сохранённым состоянием."""
        return self._storage_path.exists()

    def delete(self) -> bool:
        """Удаляет файл с состоянием."""
        try:
            if self.exists():
                os.remove(self._storage_path)
            return True
        except OSError:
            return False

    def get_path(self) -> str:
        return str(self._storage_path)