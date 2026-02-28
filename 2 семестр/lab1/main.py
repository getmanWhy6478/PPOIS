import sys
from typing import Optional

from document import Document
from driver import PrinterDriver
from exceptions import OutOfPaperError, LowInkError, HardwareError, PrinterException
from printer import Printer, PrinterState
from saver import PrinterStateStorage
from settings import PrintSettings

STATE_FILE = "printer_state.json"
CARTRIDGE_COLORS = ("C", "M", "Y", "K")
MAINTENANCE_OPS = ("clean", "calibrate", "init")


def input_int(prompt: str, default: Optional[int] = None, min_val: int = 1) -> int|None:
    while True:
        s = int(input(prompt))
        if default is not None and s == "":
            return default
        try:
            if s < min_val:
                print(f"  Минимум: {min_val}")
                continue
            return s
        except ValueError:
            print("  Введите число.")


def input_choice(prompt: str, choices: tuple[str, ...], default: Optional[str] = None) -> str:
    hint = " | ".join(choices)
    while True:
        s = input(f"{prompt} [{hint}]: ").strip()
        if default and s == "":
            return default
        for c in choices:
            if s.upper() == c.upper():
                return c
        print(f"  Выберите: {hint}")


def show_status(printer: Printer) -> None:
    st = printer.get_status()
    print(f"\nМодель: {st['model']} | Состояние: {st['state']}")
    print(f"Бумага: {st['paper']['quantity']} листов")
    print("Картриджи:", ", ".join(f"{c['color']}: {c['level_percent']}%" for c in st["cartridges"]))
    print(f"Обслуживаний: {st['maintenance_count']}\n")


def print_document(printer: Printer, settings: PrintSettings) -> None:
    if printer.state != PrinterState.IDLE:
        print(f"  Печать возможна только в состоянии 'ожидание'. Текущее: {printer.state.value}")
        return

    filename = input("  Файл: ").strip()
    if not filename:
        return

    fmt = input_choice("  Формат", tuple(Document.SUPPORTED_FORMATS), "PDF")
    pages = input_int("  Страниц: ", 1)

    try:
        doc = Document(filename, fmt, pages, 0.1)
        quality = input_choice("  Качество", ("draft", "normal", "high"), settings.quality)
        color = input_choice("  Цвет", ("color", "grayscale", "black_and_white"), settings.color_mode)
        copies = input_int("  Копий: ", settings.copies)

        print_settings = PrintSettings(quality=quality, color_mode=color, copies=copies)

        if printer.print_document(doc, print_settings):
            print(f"  '{filename}' напечатан.")
    except OutOfPaperError:
        print("  Нет бумаги.")
    except LowInkError:
        print("  Нет чернил.")
    except PrinterException as e:
        print(f"  Ошибка: {e}")


def manage_consumables(printer: Printer) -> None:
    print("\n1 — Загрузить бумагу | 2 — Заменить картридж | 0 — Назад")
    choice = input("  Выбор: ").strip()

    if choice == "1":
        if printer.state == PrinterState.OFF:
            print("  Включите принтер.")
            return
        qty = input_int("  Листов: ", 100)
        printer.load_paper(qty)
        print(f"  Загружено {qty} листов.")

    elif choice == "2":
        if printer.state == PrinterState.OFF:
            print("  Включите принтер.")
            return
        color = input_choice("  Цвет", CARTRIDGE_COLORS, "K")
        printer.replace_ink(color)
        print(f"  Картридж {color} заправлен.")


def power_control(printer: Printer) -> None:
    print("\n1 — Включить | 2 — Выключить | 0 — Назад")
    choice = input("  Выбор: ").strip()

    if choice == "1":
        if printer.state != PrinterState.OFF:
            print("  Уже включён.")
            return
        try:
            if printer.power_on():
                print("  Включён.")
                if printer.state == PrinterState.OUT_OF_PAPER:
                    print("  Нет бумаги.")
                elif printer.state == PrinterState.LOW_INK:
                    print("  Низкий уровень чернил.")
        except HardwareError as e:
            print(f"  Ошибка: {e}")

    elif choice == "2":
        if printer.state == PrinterState.OFF:
            print("  Уже выключен.")
            return
        printer.power_off()
        print("  Выключен.")


def maintenance(printer: Printer) -> None:
    if printer.state not in (PrinterState.IDLE, PrinterState.ERROR):
        print(f"  Обслуживание возможно только в состоянии 'ожидание' или 'ошибка'.")
        return

    op = input_choice("  Операция", MAINTENANCE_OPS, "clean")
    if printer.start_maintenance(op):
        print("  Успешно.")
    else:
        print("  Ошибка.")


def main_menu(printer: Printer, storage: PrinterStateStorage) -> None:
    settings = PrintSettings()

    while True:
        print("\n=== Меню ===")
        print("1 — Печать | 2 — Расходники | 3 — Вкл/Выкл | 4 — Статус | 5 — Обслуживание | 0 — Выход")

        choice = input("Выбор: ").strip()

        if choice == "0":
            break
        elif choice == "1":
            print_document(printer, settings)
        elif choice == "2":
            manage_consumables(printer)
        elif choice == "3":
            power_control(printer)
        elif choice == "4":
            show_status(printer)
        elif choice == "5":
            maintenance(printer)
        else:
            print("  Неверный выбор.")

        storage.save(printer)

    print("Сохранено. Пока!")


def main() -> int:
    storage = PrinterStateStorage(STATE_FILE)
    driver = PrinterDriver()
    driver.initialize()
    printer = storage.load(driver)
    if printer is None:
        printer = Printer("Printer", driver)
        print("Создан новый принтер.")
    else:
        print("Загружено состояние.")

    main_menu(printer, storage)
    return 0


if __name__ == "__main__":
    sys.exit(main())
