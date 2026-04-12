import xml.dom.minidom as minidom
import random


def generate_test_xml(filename="students_data.xml"):
    # Списки для формирования ФИО
    surnames = ["Иванов", "Петров", "Сидоров", "Кузнецов", "Смирнов", "Попов", "Васильев", "Соколов"]
    m_names = ["Иван", "Петр", "Алексей", "Сергей", "Дмитрий", "Андрей", "Михаил", "Николай"]
    w_names = ["Елена", "Ольга", "Наталья", "Татьяна", "Мария", "Ирина", "Светлана", "Анна"]
    patronymics_m = ["Иванович", "Петрович", "Алексеевич", "Сергеевич", "Дмитриевич", "Андреевич"]
    patronymics_w = ["Ивановна", "Петровна", "Алексеевна", "Сергеевна", "Дмитриевна", "Андреевна"]

    doc = minidom.Document()
    root = doc.createElement('students')
    doc.appendChild(root)

    for _ in range(50):
        # Выбираем базовую фамилию для студента и отца
        base_surname = random.choice(surnames)

        # ФИО студента (пусть будет мальчик для простоты генерации)
        student_fio = f"{base_surname} {random.choice(m_names)} {random.choice(patronymics_m)}"

        # ФИО отца (та же фамилия, что у студента)
        father_fio = f"{base_surname} {random.choice(m_names)} {random.choice(patronymics_m)}"

        # ФИО матери (фамилия может быть другая или девичья, добавим окончание 'а')
        mother_surname = random.choice(surnames)
        if not mother_surname.endswith('а'):
            mother_surname += 'а'
        mother_fio = f"{mother_surname} {random.choice(w_names)} {random.choice(patronymics_w)}"

        data = {
            "fio": student_fio,
            "father_fio": father_fio,
            "father_income": random.randint(40, 150) * 1000,
            "mother_fio": mother_fio,
            "mother_income": random.randint(35, 120) * 1000,
            "brothers": random.randint(0, 4),
            "sisters": random.randint(0, 4)
        }

        node = doc.createElement('student')
        for k, v in data.items():
            child = doc.createElement(k)
            child.appendChild(doc.createTextNode(str(v)))
            node.appendChild(child)
        root.appendChild(node)

    with open(filename, "w", encoding="utf-8") as f:
        f.write(doc.toprettyxml())

    print(f"Готово! Файл '{filename}' сгенерирован (50 разных семей).")


if __name__ == "__main__":
    generate_test_xml()