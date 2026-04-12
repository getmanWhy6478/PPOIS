import sqlite3
import xml.dom.minidom as minidom
import xml.sax as sax

class Student:
    def __init__(self, id=None, last_name="", first_name="", middle_name="",
                 father_fio="", father_income=0, mother_fio="", mother_income=0,
                 brothers=0, sisters=0):
        self.id = id
        self.last_name = last_name
        self.first_name = first_name
        self.middle_name = middle_name
        self.father_fio = father_fio
        self.father_income = int(father_income)
        self.mother_fio = mother_fio
        self.mother_income = int(mother_income)
        self.brothers = int(brothers)
        self.sisters = int(sisters)

    @property
    def full_fio(self):
        """Склеивает ФИО для вывода в таблицу."""
        return f"{self.last_name} {self.first_name} {self.middle_name}".strip()

class StudentSAXHandler(sax.ContentHandler):
    def __init__(self):
        self.students = []
        self.current_data = ""
        self.temp_student = {}

    def startElement(self, tag, attrs):
        self.current_tag = tag
    def characters(self, content):
        self.current_data += content.strip()
    def endElement(self, tag):
        if tag == "student":
            self.students.append(self.temp_student)
            self.temp_student = {}
        elif tag != "students":
            self.temp_student[tag] = self.current_data
        self.current_data = ""

class DataModel:
    def __init__(self):
        self.db = sqlite3.connect(":memory:")
        self.cursor = self.db.cursor()
        self.cursor.execute('''CREATE TABLE students (
            id INTEGER PRIMARY KEY, 
            last_name TEXT, first_name TEXT, middle_name TEXT,
            father_fio TEXT, father_income INTEGER,
            mother_fio TEXT, mother_income INTEGER, 
            brothers INTEGER, sisters INTEGER)''')

    def add_student(self, data):
        # Если ФИО пришло одной строкой, разбиваем его
        fio_parts = data.get('fio', "").split()
        ln = fio_parts[0] if len(fio_parts) > 0 else ""
        fn = fio_parts[1] if len(fio_parts) > 1 else ""
        mn = fio_parts[2] if len(fio_parts) > 2 else ""

        self.cursor.execute("INSERT INTO students VALUES (NULL,?,?,?,?,?,?,?,?,?)",
            (ln, fn, mn, data['father_fio'], int(data['father_income']),
             data['mother_fio'], int(data['mother_income']), int(data['brothers']), int(data['sisters'])))
        self.db.commit()

    def get_paged(self, page, size):
        offset = (page - 1) * size
        self.cursor.execute("SELECT * FROM students LIMIT ? OFFSET ?", (size, offset))
        return [Student(*row) for row in self.cursor.fetchall()]

    def get_total(self):
        self.cursor.execute("SELECT COUNT(*) FROM students")
        return self.cursor.fetchone()[0]

    def _build_query(self, command, last, first, mid, rel_type, rel_count, mi, ma):
        # Базовая часть запроса
        query = f"{command} FROM students WHERE last_name LIKE ? AND first_name LIKE ? AND middle_name LIKE ?"
        params = [f"%{last}%", f"%{first}%", f"%{mid}%"]

        # Если количество родственников указано (не None), добавляем фильтр
        if rel_count is not None:
            query += f" AND {rel_type} = ?"
            params.append(rel_count)

        # Добавляем фильтр по доходу
        query += " AND ((father_income BETWEEN ? AND ?) OR (mother_income BETWEEN ? AND ?))"
        params.extend([mi, ma, mi, ma])

        return query, params

    def search(self, *args):
        q, p = self._build_query("SELECT *", *args)
        self.cursor.execute(q, p)
        return [Student(*row) for row in self.cursor.fetchall()]

    def delete_by_criteria(self, *args):
        q, p = self._build_query("DELETE", *args)
        self.cursor.execute(q, p)
        count = self.cursor.rowcount
        self.db.commit()
        return count

    def save_xml(self, path):
        doc = minidom.Document()
        root = doc.createElement('students')
        doc.appendChild(root)
        self.cursor.execute("SELECT * FROM students")
        for row in self.cursor.fetchall():
            s = Student(*row)
            node = doc.createElement('student')
            # Сохраняем ФИО как одну строку для совместимости
            data_map = {
                "fio": s.full_fio, "father_fio": s.father_fio, "father_income": s.father_income,
                "mother_fio": s.mother_fio, "mother_income": s.mother_income,
                "brothers": s.brothers, "sisters": s.sisters
            }
            for k, v in data_map.items():
                child = doc.createElement(k)
                child.appendChild(doc.createTextNode(str(v)))
                node.appendChild(child)
            root.appendChild(node)
        with open(path, "w", encoding="utf-8") as f: f.write(doc.toprettyxml())