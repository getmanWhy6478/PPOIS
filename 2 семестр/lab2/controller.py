from tkinter import messagebox, filedialog
import xml.sax
from model import StudentSAXHandler
from view import AddStudentDialog, DeleteDialog, SearchDialog


class AppController:
    def __init__(self, model, view):
        self.model, self.view = model, view
        self.page = 1
        self._setup()
        self.refresh(1)

    def _setup(self):
        self.view.file_menu.add_command(label="Загрузить XML", command=self.load_xml)
        self.view.file_menu.add_command(label="Сохранить XML", command=self.save_xml)
        self.view.action_menu.add_command(label="Добавить", command=lambda: AddStudentDialog(self.view.root, self.add))
        self.view.action_menu.add_command(label="Поиск", command=lambda: SearchDialog(self.view.root, self.search))
        self.view.action_menu.add_command(label="Удалить", command=lambda: DeleteDialog(self.view.root, self.delete))
        self.view.btn_prev.config(command=lambda: self.refresh(self.page - 1))
        self.view.btn_next.config(command=lambda: self.refresh(self.page + 1))

    def add(self, data):
        self.model.add_student(data)
        self.refresh(1)

    def delete(self, ln, fn, mn, rt, c, mi, ma):
        count = self.model.delete_by_criteria(ln, fn, mn, rt, c, mi, ma)
        messagebox.showinfo("Готово", f"Удалено записей: {count}")
        self.refresh(1)

    def search(self, ln, fn, mn, rt, c, mi, ma):
        results = self.model.search(ln, fn, mn, rt, c, mi, ma)
        for w in self.view.root.winfo_children():
            if isinstance(w, SearchDialog):
                w.tree.delete(*w.tree.get_children())
                for s in results: w.tree.insert("", "end", values=(s.full_fio,))

    def load_xml(self):
        path = filedialog.askopenfilename()
        if path:
            h = StudentSAXHandler()
            xml.sax.parse(path, h)
            for s in h.students: self.model.add_student(s)
            self.refresh(1)

    def save_xml(self):
        path = filedialog.asksaveasfilename(defaultextension=".xml")
        if path: self.model.save_xml(path)

    def refresh(self, page):
        if page < 1:
            page = 1
        self.page = page
        size = self.view.size_var.get()
        data = self.model.get_paged(page, size)
        total = self.model.get_total()

        self.view.tree.delete(*self.view.tree.get_children())

        if self.view.tree_mode.get():
            # РЕЖИМ ДЕРЕВА
            self.view.tree["show"] = "tree"  # Показываем только иерархию
            for s in data:
                # Главный узел - Студент
                node = self.view.tree.insert("", "end", text=f"{s.full_fio}", open=False)
                # Вложенные узлы с подробностями
                self.view.tree.insert(node, "end", text=f"Отец: {s.father_fio} (₽{s.father_income})")
                self.view.tree.insert(node, "end", text=f"Мать: {s.mother_fio} (₽{s.mother_income})")
                self.view.tree.insert(node, "end", text=f"Родственники: Б-{s.brothers}, С-{s.sisters}")
        else:
            # РЕЖИМ ТАБЛИЦЫ
            self.view.tree["show"] = "headings"  # Показываем заголовки колонок
            for s in data:
                self.view.tree.insert("", "end", values=(
                    s.full_fio, s.father_fio, s.father_income,
                    s.mother_fio, s.mother_income, s.brothers, s.sisters
                ))

        tp = (total + size - 1) // size if total else 1
        self.view.lbl_page.config(text=f"Стр {page} / {tp} (Всего: {total})")