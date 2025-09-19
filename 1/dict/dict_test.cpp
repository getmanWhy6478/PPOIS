#include "Dict.h"
#include <UnitTest++/UnitTest++.h>
#include <fstream>
#include <cstring>

using namespace std;

// Вспомогательная функция для создания временного файла
void create_test_file(const string& filename, const string& content) {
    ofstream file(filename);
    file << content;
    file.close();
}

// Тест конструктора по умолчанию
TEST(Dict_default_constructor) {
    Dict dict;
    CHECK_EQUAL(0, dict.size());
}

// Тест добавления слова с помощью pair<string, string>
TEST(Dict_add_pair) {
    Dict dict;
    dict += make_pair("apple", "яблоко");

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("яблоко", dict["apple"]);
}

// Тест добавления слова с помощью pair<char*, char*>
TEST(Dict_add_char_pair) {
    Dict dict;
    char eng[] = "car";
    char rus[] = "машина";
    dict += make_pair(eng, rus);

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("машина", dict["car"]);
}

// Тест добавления нескольких слов
TEST(Dict_add_words) {
    Dict dict;
    dict += make_pair("apple", "яблоко");
    dict += make_pair("car", "машина");
    dict += make_pair("book", "книга");

    CHECK_EQUAL(3, dict.size());
    CHECK_EQUAL("яблоко", dict["apple"]);
    CHECK_EQUAL("машина", dict["car"]);
    CHECK_EQUAL("книга", dict["book"]);
}

// Тест удаления слова с помощью string
TEST(Dict_remove_string) {
    Dict dict;
    dict += make_pair("apple", "яблоко");
    dict += make_pair("car", "машина");

    dict -= "apple";

    CHECK_EQUAL(1, dict.size());
    CHECK_THROW(dict["apple"], runtime_error);
    CHECK_EQUAL("машина", dict["car"]);
}

// Тест удаления слова с помощью char*
TEST(Dict_remove_char) {
    Dict dict;
    dict += make_pair("apple", "яблоко");
    dict += make_pair("car", "машина");

    char word[] = "apple";
    dict -= word;

    CHECK_EQUAL(1, dict.size());
    CHECK_THROW(dict["apple"], runtime_error);
    CHECK_EQUAL("машина", dict["car"]);
}

// Тест удаления несуществующего слова
TEST(Dict_remove_ghost) {
    Dict dict;
    dict += make_pair("apple", "яблоко");

    dict -= "banana";

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("яблоко", dict["apple"]);
}

// Тест доступа к существующему слову
TEST(Dict_access) {
    Dict dict;
    dict += make_pair("apple", "яблоко");

    CHECK_EQUAL("яблоко", dict["apple"]);
}

// Тест доступа к несуществующему слову
TEST(Dict_access_ghost) {
    Dict dict;

    CHECK_THROW(dict["apple"], runtime_error);
}

// Тест изменения перевода через оператор []
TEST(Dict_change_translation) {
    Dict dict;
    dict += make_pair("car", "машина");

    dict["car"] = "автомобиль";

    CHECK_EQUAL("автомобиль", dict["car"]);
}

// Тест конструктора копирования
TEST(Dict_copy_constructor) {
    Dict original;
    original += make_pair("apple", "яблоко");
    original += make_pair("car", "машина");

    Dict copy(original);

    CHECK_EQUAL(2, copy.size());
    CHECK_EQUAL("яблоко", copy["apple"]);
    CHECK_EQUAL("машина", copy["car"]);

    // Проверяем, что копия независима от оригинала
    copy += make_pair("book", "книга");
    CHECK_EQUAL(3, copy.size());
    CHECK_EQUAL(2, original.size());
}

// Тест оператора присваивания
TEST(Dict_assignment) {
    Dict original;
    original += make_pair("apple", "яблоко");
    original += make_pair("car", "машина");

    Dict assigned;
    assigned = original;

    CHECK_EQUAL(2, assigned.size());
    CHECK_EQUAL("яблоко", assigned["apple"]);
    CHECK_EQUAL("машина", assigned["car"]);

    // Проверяем, что присвоенный объект независим от оригинала
    assigned += make_pair("book", "книга");
    CHECK_EQUAL(3, assigned.size());
    CHECK_EQUAL(2, original.size());
}

// Тест метода contains с существующим словом
TEST(Dict_contains) {
    Dict dict;
    dict += make_pair("apple", "яблоко");

    CHECK(dict.contains("apple"));
}

// Тест метода contains с несуществующим словом
TEST(Dict_contains_ghost) {
    Dict dict;
    dict += make_pair("apple", "яблоко");

    CHECK(!dict.contains("banana"));
}

// Тест метода contains с char*
TEST(Dict_contains_char) {
    Dict dict;
    dict += make_pair("apple", "яблоко");

    char word[] = "apple";
    CHECK(dict.contains(word));
}

// Тест загрузки из файла с разделителем '='
TEST(Dict_load_equal) {
    create_test_file("test_dict.txt", "apple=яблоко\ncar=машина\nbook=книга");

    Dict dict;
    dict.load_from_file("test_dict.txt");

    CHECK_EQUAL(3, dict.size());
    CHECK_EQUAL("яблоко", dict["apple"]);
    CHECK_EQUAL("машина", dict["car"]);
    CHECK_EQUAL("книга", dict["book"]);

    remove("test_dict.txt");
}

// Тест загрузки из файла с разделителем ':'
TEST(Dict_load_dots) {
    create_test_file("test_dict.txt", "apple:яблоко\ncar:машина\nbook:книга");

    Dict dict;
    dict.load_from_file("test_dict.txt");

    CHECK_EQUAL(3, dict.size());
    CHECK_EQUAL("яблоко", dict["apple"]);
    CHECK_EQUAL("машина", dict["car"]);
    CHECK_EQUAL("книга", dict["book"]);

    remove("test_dict.txt");
}

// Тест загрузки из файла с табуляцией в качестве разделителя
TEST(Dict_load_tab) {
    create_test_file("test_dict.txt", "apple\tяблоко\ncar\tмашина\nbook\tкнига");

    Dict dict;
    dict.load_from_file("test_dict.txt");

    CHECK_EQUAL(3, dict.size());
    CHECK_EQUAL("яблоко", dict["apple"]);
    CHECK_EQUAL("машина", dict["car"]);
    CHECK_EQUAL("книга", dict["book"]);

    remove("test_dict.txt");
}

// Тест загрузки из несуществующего файла
TEST(Dict_load_ghost) {
    Dict dict;

    CHECK_THROW(dict.load_from_file("non_existent_file.txt"), runtime_error);
}

// Тест загрузки из файла с некорректным форматом
TEST(Dict_load_invalid) {
    create_test_file("test_dict.txt", "appleяблоко\ncar:машина\nbook книга");

    Dict dict;
    // Должен проигнорировать строки без разделителей
    dict.load_from_file("test_dict.txt");

    CHECK_EQUAL(1, dict.size()); // Только вторая строка должна быть обработана
    CHECK_EQUAL("машина", dict["car"]);

    remove("test_dict.txt");
}

// Тест очистки словаря
TEST(Dict_clear) {
    Dict dict;
    dict += make_pair("apple", "яблоко");
    dict += make_pair("car", "машина");

    dict.clear();

    CHECK_EQUAL(0, dict.size());
    CHECK_THROW(dict["apple"], runtime_error);
    CHECK_THROW(dict["car"], runtime_error);
}

// Тест добавления дубликатов (должен перезаписывать значение)
TEST(Dict_change) {
    Dict dict;
    dict += make_pair("apple", "яблоко");
    dict += make_pair("apple", "яблочко"); // Дубликат

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("яблочко", dict["apple"]);
}

// Тест удаления корневого узла с двумя потомками
TEST(Dict_remove_two_child) {
    Dict dict;
    dict += make_pair("mango", "манго");
    dict += make_pair("apple", "яблоко");
    dict += make_pair("zebra", "зебра");

    dict -= "mango"; // Удаляем корень с двумя потомками

    CHECK_EQUAL(2, dict.size());
    CHECK_EQUAL("яблоко", dict["apple"]);
    CHECK_EQUAL("зебра", dict["zebra"]);
    CHECK_THROW(dict["mango"], runtime_error);
}

// Тест удаления узла с одним потомком
TEST(Dict_remove_one_child) {
    Dict dict;
    dict += make_pair("mango", "манго");
    dict += make_pair("apple", "яблоко");

    dict -= "mango"; // Удаляем узел с одним потомком

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("яблоко", dict["apple"]);
    CHECK_THROW(dict["mango"], runtime_error);
}

// Тест удаления листового узла
TEST(Dict_remove_zero_child) {
    Dict dict;
    dict += make_pair("mango", "манго");
    dict += make_pair("apple", "яблоко");

    dict -= "apple"; // Удаляем лист

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("манго", dict["mango"]);
    CHECK_THROW(dict["apple"], runtime_error);
}

// Тест работы с пустым словарем
TEST(Dict_rempty) {
    Dict dict;

    CHECK_EQUAL(0, dict.size());
    CHECK_THROW(dict["apple"], runtime_error);
    CHECK(!dict.contains("apple"));

    // Удаление из пустого словаря не должно вызывать ошибок
    dict -= "apple";
    CHECK_EQUAL(0, dict.size());
}

TEST(Dict_сopy_modify) {
    Dict original;
    original += make_pair("apple", "яблоко");
    original += make_pair("car", "машина");

    // Создаем копию
    Dict copy = original;

    // Проверяем, что копия идентична оригиналу
    CHECK_EQUAL(2, copy.size());
    CHECK_EQUAL("яблоко", copy["apple"]);
    CHECK_EQUAL("машина", copy["car"]);

    // Изменяем копию
    copy += make_pair("book", "книга");
    copy["car"] = "автомобиль";

    // Проверяем, что оригинал не изменился
    CHECK_EQUAL(2, original.size());
    CHECK_EQUAL("машина", original["car"]);
    CHECK_THROW(original["book"], runtime_error);

    // Проверяем изменения в копии
    CHECK_EQUAL(3, copy.size());
    CHECK_EQUAL("автомобиль", copy["car"]);
    CHECK_EQUAL("книга", copy["book"]);
}

// Тест на очистку непустого словаря
TEST(Dict_clear_full) {
    Dict dict;
    dict += make_pair("apple", "яблоко");
    dict += make_pair("car", "машина");
    dict += make_pair("book", "книга");

    CHECK_EQUAL(3, dict.size());

    dict.clear();

    CHECK_EQUAL(0, dict.size());
    CHECK_THROW(dict["apple"], runtime_error);
    CHECK_THROW(dict["car"], runtime_error);
    CHECK_THROW(dict["book"], runtime_error);

    // Проверяем, что после очистки можно снова добавлять слова
    dict += make_pair("new", "новое");
    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("новое", dict["new"]);
}
// Тест на обработку исключений при неверном использовании оператора []
TEST(Dict_key) {
    Dict dict;

    // Попытка доступа к несуществующему слову должна вызывать исключение
    CHECK_THROW(dict["nonexistent"], runtime_error);

    // Но после добавления слова доступ должен работать
    dict += make_pair("test", "тест");
    CHECK_EQUAL("тест", dict["test"]);

    // Проверяем, что можно изменить значение через оператор []
    dict["test"] = "новый тест";
    CHECK_EQUAL("новый тест", dict["test"]);
}
TEST(Dict_long_words) {
    Dict dict;
    string long_english(1000, 'a');
    string long_russian(1000, 'б');

    dict += make_pair(long_english, long_russian);

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL(long_russian, dict[long_english]);
}