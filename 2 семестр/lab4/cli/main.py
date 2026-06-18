import sys
from typing import Optional
from core.document import Document
from core.driver import PrinterDriver
from core.exceptions import (
    HardwareError,
    InvalidDocumentError,
    LowInkError,
    OutOfPaperError,
    PrinterException,
)
from core.printer import Printer, PrinterState
from core.saver import PrinterStateStorage
from core.settings import PrintSettings

DEFAULT_STATE_PATH = "printer_state.json"

SUPPORTED_FORMATS = sorted(Document.SUPPORTED_FORMATS)

CARTRIDGE_COLORS = ("C", "M", "Y", "K")

MAINTENANCE_OPS = ("clean", "calibrate", "init")


def input_int(prompt: str, default: Optional[int] = None, min_val: Optional[int] = None) -> int:
    while True:
        s = input(prompt).strip()
        if default is not None and s == "":
            return default
        try:
            v = int(s)
            if min_val is not None and v < min_val:
                print(f"  Введите число >= {min_val}")
            return v
        except ValueError:
            print("  Введите целое число.")


def input_float(prompt: str, default: Optional[float] = None, min_val: Optional[float] = None) -> float:
    while True:
        s = input(prompt).strip()
        if default is not None and s == "":
            return default
        try:
            v = float(s)
            if min_val is not None and v < min_val:
                print(f"  Введите число >= {min_val}")
            return v
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
        print(f"  Выберите один из: {hint}")


def show_status(printer: Printer) -> None:
    st = printer.get_status()
    print("\nСтатус принтера")
    print(f"  Модель: {st['model']}")
    print(f"  Состояние: {st['state']}")
    print(f"  Бумага: {st['paper']['type']}, {st['paper']['quantity']} листов, пусто: {st['paper']['is_empty']}")
    print("  Картриджи:")
    for c in st["cartridges"]:
        print(f"    {c['color']}: {c['level_percent']}%, пусто: {c['is_empty']}")
    print(f"  Счётчик обслуживаний: {st['maintenance_count']}")
    print()


def menu_print_document(printer: Printer, default_settings: PrintSettings) -> None:
    if printer.state != PrinterState.IDLE:
        print(f"  Печать возможна только в состоянии 'ожидание'. Текущее состояние: {printer.state.value}.")
        return
    print("\nПечать документа")
    filename = input("  Имя файла: ").strip()
    if not filename:
        print("  Отменено.")
        return
    fmt = input_choice("  Формат", tuple(SUPPORTED_FORMATS), "PDF")
    pages = input_int("  Количество страниц", default=1, min_val=1)
    size_mb = input_float("  Размер (МБ)", default=0.1, min_val=0.01)
    try:
        doc = Document(filename, fmt, pages, size_mb)
    except InvalidDocumentError as e:
        print(f"  Ошибка: {e}")
        return
    print("  Параметры печати (Enter — по умолчанию):")
    quality = input_choice("    Качество", ("draft", "normal", "high"), default_settings.quality)
    color_mode = input_choice(
        "    Режим цвета",
        ("color", "grayscale", "black_and_white"),
        default_settings.color_mode,
    )
    copies = input_int("    Копий", default=default_settings.copies, min_val=1)
    try:
        settings = PrintSettings(quality=quality,color_mode=color_mode,copies=copies,)
        ok = printer.print_document(doc, settings)
        if ok:
            print(f"  Документ '{filename}' успешно напечатан.")
        else:
            print("  Печать завершилась с ошибкой.")
    except OutOfPaperError:
        print("  Ошибка: недостаточно бумаги.")
    except LowInkError:
        print("  Ошибка: недостаточно чернил.")
    except (HardwareError, PrinterException) as e:
        print(f"  Ошибка: {e}")
    print()


def menu_consumables(printer: Printer) -> None:
    print("\nЗамена расходных материалов")
    print("  1 — Загрузить бумагу")
    print("  2 — Заменить картридж (заправить чернила)")
    print("  0 — Назад")
    choice = input("  Выбор: ").strip()
    if choice == "0":
        return
    if choice == "1":
        if printer.state == PrinterState.OFF:
            print("  Сначала включите принтер.")
            return
        qty = input_int("  Количество листов для загрузки", default=100, min_val=1)
        try:
            printer.load_paper(qty)
            print(f"  Загружено {qty} листов. Сейчас в лотке: {printer.paper.quantity}.")
        except PrinterException as e:
            print(f"  Ошибка: {e}")
    elif choice == "2":
        if printer.state == PrinterState.OFF:
            print("  Сначала включите принтер.")
            return
        color = input_choice("  Цвет картриджа", CARTRIDGE_COLORS, "K")
        try:
            printer.replace_ink(color)
            print(f"  Картридж {color} заправлен.")
        except ValueError as e:
            print(f"  Ошибка: {e}")
        except PrinterException as e:
            print(f"  Ошибка: {e}")
    else:
        print("  Неверный пункт.")
    print()


def menu_driver_control(printer: Printer) -> None:
    print("\nУправление через драйвер")
    print("  1 — Включить принтер")
    print("  2 — Выключить принтер")
    print("  0 — Назад")
    choice = input("  Выбор: ").strip()
    if choice == "0":
        return
    if choice == "1":
        if printer.state != PrinterState.OFF:
            print("  Принтер уже включён.")
            return
        try:
            ok = printer.power_on()
            if ok:
                print("  Принтер включён.")
                if printer.state == PrinterState.OUT_OF_PAPER:
                    print("  Внимание: в лотке нет бумаги. Загрузите бумагу.")
                elif printer.state == PrinterState.LOW_INK:
                    print("  Внимание: низкий уровень чернил. Замените картриджи.")
            else:
                print("  Не удалось включить принтер.")
        except HardwareError as e:
            print(f"  Ошибка включения: {e}")
    elif choice == "2":
        if printer.state == PrinterState.OFF:
            print("  Принтер уже выключен.")
            return
        ok = printer.power_off()
        if ok:
            print("  Принтер выключен.")
        else:
            print("  Не удалось выключить принтер.")
    else:
        print("  Неверный пункт.")
    print()


def menu_print_settings(default_settings: PrintSettings) -> PrintSettings:
    print("\nНастройка параметров печати...")
    print("  Текущие значения по умолчанию:")
    print(f"    Качество: {default_settings.quality}, режим: {default_settings.color_mode}, копий: {default_settings.copies}")
    quality = input_choice("  Качество по умолчанию", ("draft", "normal", "high"), default_settings.quality)
    color_mode = input_choice(
        "  Режим цвета по умолчанию",
        ("color", "grayscale", "black_and_white"),
        default_settings.color_mode,
    )
    copies = input_int("  Копий по умолчанию", default=default_settings.copies, min_val=1)
    new_settings = PrintSettings(quality=quality, color_mode=color_mode, copies=copies)
    print("  Параметры по умолчанию сохранены.")
    print()
    return new_settings


def menu_maintenance(printer: Printer) -> None:
    print("\n--- Обслуживание и ремонт ---")
    if printer.state not in (PrinterState.IDLE, PrinterState.ERROR):
        print(f"  Обслуживание возможно только в состоянии 'ожидание' или 'ошибка'. Текущее: {printer.state.value}.")
        print()
        return
    print("  Операции: clean (очистка), calibrate (калибровка), init (инициализация)")
    op = input_choice("  Выберите операцию", MAINTENANCE_OPS, "clean")
    try:
        success = printer.start_maintenance(op)
        if success:
            print("  Обслуживание выполнено успешно.")
        else:
            print("  Обслуживание завершилось с ошибкой. Принтер переведён в состояние 'ошибка'.")
    except (PrinterException, HardwareError) as e:
        print(f"  Ошибка: {e}")
    print()


def run_menu(
    printer: Printer,
    storage: PrinterStateStorage,
    driver: PrinterDriver,
    state_path: str = DEFAULT_STATE_PATH,
) -> None:
    default_settings = PrintSettings()
    while True:
        print("\nМеню системы печати")
        print("  1 — Печать документа")
        print("  2 — Замена расходных материалов (бумага / чернила)")
        print("  3 — Управление через драйвер (вкл/выкл принтера)")
        print("  4 — Настройка параметров печати")
        print("  5 — Обслуживание и ремонт")
        print("  6 — Показать статус принтера")
        print("  0 — Выход (сохранить состояние)")
        choice = input("  Выбор: ").strip()
        if choice == "0":
            break
        if choice == "1":
            menu_print_document(printer, default_settings)
        elif choice == "2":
            menu_consumables(printer)
        elif choice == "3":
            menu_driver_control(printer)
        elif choice == "4":
            default_settings = menu_print_settings(default_settings)
        elif choice == "5":
            menu_maintenance(printer)
        elif choice == "6":
            show_status(printer)
        else:
            print("  Неверный пункт.")
        storage.save(printer)
    print("  Состояние сохранено. До свидания.")


def main() -> int:
    state_path = DEFAULT_STATE_PATH
    if len(sys.argv) > 1:
        state_path = sys.argv[1]
    storage = PrinterStateStorage(state_path)
    driver = PrinterDriver()
    printer: Optional[Printer] = storage.load(driver)
    if printer is None:
        printer = Printer("Printer", driver)
        print("  Создан новый принтер. Сначала включите его (п. 3).")
    else:
        print("  Загружено сохранённое состояние принтера.")
    run_menu(printer, storage, driver, state_path)
    return 0


if __name__ == "__main__":
    sys.exit(main())