import tkinter as tk
from tkinter import ttk


class BaseCriteriaDialog(tk.Toplevel):
    def __init__(self, parent, title, on_action):
        super().__init__(parent)
        self.title(title)
        self.on_action = on_action

        ttk.Label(self, text="Фамилия:").pack()
        self.e_last = ttk.Entry(self)
        self.e_last.pack()
        ttk.Label(self, text="Имя:").pack()
        self.e_first = ttk.Entry(self)
        self.e_first.pack()
        ttk.Label(self, text="Отчество:").pack()
        self.e_mid = ttk.Entry(self)
        self.e_mid.pack()

        ttk.Label(self, text="Тип родственника:").pack()
        self.rel_type = ttk.Combobox(self, values=["brothers", "sisters"], state="readonly")
        self.rel_type.set("brothers")
        self.rel_type.pack()

        ttk.Label(self, text="Количество ").pack()
        self.e_count = ttk.Entry(self)  # Используем Entry вместо Spinbox для пустоты
        self.e_count.pack()

        ttk.Label(self, text="Доход родителя (от - до):").pack()
        f_inc = ttk.Frame(self)
        f_inc.pack()
        self.e_min = ttk.Entry(f_inc, width=8)
        self.e_min.insert(0, "0")
        self.e_min.pack(side="left")
        self.e_max = ttk.Entry(f_inc, width=8)
        self.e_max.insert(0, "999999")
        self.e_max.pack(side="left")

    def get_data(self):
        # Если поле пустое, передаем None, иначе — число
        raw_count = self.e_count.get().strip()
        rel_count = int(raw_count) if raw_count.isdigit() else None

        return (self.e_last.get(), self.e_first.get(), self.e_mid.get(),
                self.rel_type.get(), rel_count,
                int(self.e_min.get()), int(self.e_max.get()))


class SearchDialog(BaseCriteriaDialog):
    def __init__(self, parent, on_search):
        super().__init__(parent, "Поиск студентов", on_search)
        ttk.Button(self, text="Найти", command=lambda: self.on_action(*self.get_data())).pack(pady=10)
        self.tree = ttk.Treeview(self, columns=("fio",), show="headings", height=5)
        self.tree.heading("fio", text="Найденные студенты")
        self.tree.pack(fill="both")


class DeleteDialog(BaseCriteriaDialog):
    def __init__(self, parent, on_delete):
        super().__init__(parent, "Удаление студентов", on_delete)
        ttk.Button(self, text="Удалить подходящие",
                   command=lambda: [self.on_action(*self.get_data()), self.destroy()]).pack(pady=10)


class AddStudentDialog(tk.Toplevel):
    def __init__(self, parent, on_save):
        super().__init__(parent)
        self.title("Новый студент")
        fields = [("fio", "ФИО (Фамилия Имя Отчество)"), ("father_fio", "ФИО отца"), ("father_income", "Доход отца"),
                  ("mother_fio", "ФИО матери"), ("mother_income", "Доход матери"), ("brothers", "Братьев"),
                  ("sisters", "Сестер")]
        self.vars = {f[0]: tk.StringVar() for f in fields}
        for i, (key, label) in enumerate(fields):
            ttk.Label(self, text=label).grid(row=i, column=0, sticky="w", padx=5)
            ttk.Entry(self, textvariable=self.vars[key]).grid(row=i, column=1, padx=5)
        ttk.Button(self, text="Добавить",
                   command=lambda: [on_save({k: v.get() for k, v in self.vars.items()}), self.destroy()]).grid(row=8,
                                                                                                               columnspan=2,
                                                                                                               pady=10)


class MainView:
    def __init__(self, root):
        self.root = root
        self.root.title("Учет студентов")
        self.root.geometry("1100x600")

        self.menu_bar = tk.Menu(root)
        root.config(menu=self.menu_bar)
        self.file_menu = tk.Menu(self.menu_bar, tearoff=0)
        self.menu_bar.add_cascade(label="Файл", menu=self.file_menu)
        self.action_menu = tk.Menu(self.menu_bar, tearoff=0)
        self.menu_bar.add_cascade(label="Действия", menu=self.action_menu)

        self.toolbar = ttk.Frame(root, padding=2)
        self.toolbar.pack(side="top", fill="x")
        self.tree = ttk.Treeview(root, columns=("fio", "f_fio", "f_inc", "m_fio", "m_inc", "b", "s"), show="headings")
        # Настроим ширину первой колонки для текста дерева
        self.tree.column("#0", width=650, stretch=tk.NO)
        for c, h in zip(self.tree["columns"],
                        ["ФИО Студента", "ФИО Отца", "Доход О", "ФИО Матери", "Доход М", "Братья", "Сестры"]):
            self.tree.heading(c, text=h)
            self.tree.column(c, width=120)
        for c, h in zip(self.tree["columns"],
                        ["ФИО Студента", "ФИО Отца", "Доход О", "ФИО Матери", "Доход М", "Братья", "Сестры"]):
            self.tree.heading(c, text=h)
        self.tree.pack(fill="both", expand=True)

        self.pag = ttk.Frame(root)
        self.pag.pack(side="bottom", fill="x", pady=5)
        self.btn_prev = ttk.Button(self.pag, text="<")
        self.btn_prev.pack(side="left", padx=5)
        self.lbl_page = ttk.Label(self.pag, text="Стр 1")
        self.lbl_page.pack(side="left")
        self.btn_next = ttk.Button(self.pag, text=">")
        self.btn_next.pack(side="left", padx=5)
        self.size_var = tk.IntVar(value=10)
        ttk.Entry(self.pag, textvariable=self.size_var, width=5).pack(side="right", padx=5)
        self.tree_mode = tk.BooleanVar()
        ttk.Checkbutton(self.toolbar, text="Режим дерева", variable=self.tree_mode).pack(side="right")