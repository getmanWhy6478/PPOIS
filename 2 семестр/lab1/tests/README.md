# Unit-тесты

## Запуск на Windows

1. Откройте **командную строку** (cmd) или **PowerShell**.
2. Перейдите в папку проекта (где лежат `printer.py`, `document.py`, `driver.py` и т.д.):

   **CMD:**
   ```cmd
   cd d:\!ппоис\лаба1
   ```

   **PowerShell:** та же команда или, если путь с пробелами:
   ```powershell
   cd "d:\!ппоис\лаба1"
   ```

3. Запустите все тесты:

   ```cmd
   python -m unittest discover -s tests -v
   ```

   Если установлено несколько версий Python, можно явно указать:
   ```cmd
   py -3 -m unittest discover -s tests -v
   ```

### Один файл с тестами

```cmd
python -m unittest tests.test_document -v
```

### Запуск с отчётом покрытия (coverage)

Сначала установите: `pip install coverage`, затем:

```cmd
coverage run -m unittest discover -s tests
coverage report
```
