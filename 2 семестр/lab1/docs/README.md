# Диаграммы проекта (UML 2.x)

## Файлы

- **`class_diagram.puml`** — диаграмма классов: сущности (принтер, документ, бумага, чернила, драйвер, настройки, хранилище), интерфейсы и исключения.
- **`state_diagram.puml`** — диаграмма состояний принтера: состояния (OFF, IDLE, PRINTING, OUT_OF_PAPER, LOW_INK, ERROR, MAINTENANCE) и переходы между ними.

## Как просмотреть

1. **Онлайн:** скопируйте содержимое `.puml` на [plantuml.com/plantuml](https://www.plantuml.com/plantuml/uml) и нажмите Submit.
2. **VS Code:** установите расширение "PlantUML" (jebbs.plantuml), откройте файл и нажмите `Alt+D` для предпросмотра.
3. **Командная строка:** при установленном [PlantUML](https://plantuml.com/ru/command-line):
   ```bash
   java -jar plantuml.jar docs/class_diagram.puml docs/state_diagram.puml
   ```
   В той же папке появятся PNG (или SVG при указании `-tsvg`).
