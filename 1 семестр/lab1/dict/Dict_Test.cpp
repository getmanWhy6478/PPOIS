#include "Dict.h"
#include <UnitTest++/UnitTest++.h>
#include <fstream>
#include <cstring>

using namespace std;

void create_test_file(const string& filename, const string& content) {
    ofstream file(filename);
    file << content;
    file.close();
}

TEST(Dict_default_constructor) {
    Dict dict;
    CHECK_EQUAL(0, dict.size());
}

TEST(Dict_add_pair) {
    Dict dict;
    dict += make_pair("apple", "������");

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("������", dict["apple"]);
}

TEST(Dict_add_char_pair) {
    Dict dict;
    char eng[] = "car";
    char rus[] = "������";
    dict += make_pair(eng, rus);

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("������", dict["car"]);
}

TEST(Dict_add_words) {
    Dict dict;
    dict += make_pair("apple", "������");
    dict += make_pair("car", "������");
    dict += make_pair("book", "�����");

    CHECK_EQUAL(3, dict.size());
    CHECK_EQUAL("������", dict["apple"]);
    CHECK_EQUAL("������", dict["car"]);
    CHECK_EQUAL("�����", dict["book"]);
}

TEST(Dict_remove_string) {
    Dict dict;
    dict += make_pair("apple", "������");
    dict += make_pair("car", "������");

    dict -= "apple";

    CHECK_EQUAL(1, dict.size());
    CHECK_THROW(dict["apple"], runtime_error);
    CHECK_EQUAL("������", dict["car"]);
}

TEST(Dict_remove_char) {
    Dict dict;
    dict += make_pair("apple", "������");
    dict += make_pair("car", "������");

    char word[] = "apple";
    dict -= word;

    CHECK_EQUAL(1, dict.size());
    CHECK_THROW(dict["apple"], runtime_error);
    CHECK_EQUAL("������", dict["car"]);
}

TEST(Dict_remove_ghost) {
    Dict dict;
    dict += make_pair("apple", "������");

    dict -= "banana";

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("������", dict["apple"]);
}

TEST(Dict_access) {
    Dict dict;
    dict += make_pair("apple", "������");

    CHECK_EQUAL("������", dict["apple"]);
}

TEST(Dict_access_ghost) {
    Dict dict;

    CHECK_THROW(dict["apple"], runtime_error);
}

TEST(Dict_change_translation) {
    Dict dict;
    dict += make_pair("car", "������");

    dict["car"] = "����������";

    CHECK_EQUAL("����������", dict["car"]);
}

TEST(Dict_copy_constructor) {
    Dict original;
    original += make_pair("apple", "������");
    original += make_pair("car", "������");

    Dict copy(original);

    CHECK_EQUAL(2, copy.size());
    CHECK_EQUAL("������", copy["apple"]);
    CHECK_EQUAL("������", copy["car"]);

    copy += make_pair("book", "�����");
    CHECK_EQUAL(3, copy.size());
    CHECK_EQUAL(2, original.size());
}

TEST(Dict_assignment) {
    Dict original;
    original += make_pair("apple", "������");
    original += make_pair("car", "������");

    Dict assigned;
    assigned = original;

    CHECK_EQUAL(2, assigned.size());
    CHECK_EQUAL("������", assigned["apple"]);
    CHECK_EQUAL("������", assigned["car"]);

    assigned += make_pair("book", "�����");
    CHECK_EQUAL(3, assigned.size());
    CHECK_EQUAL(2, original.size());
}

TEST(Dict_contains) {
    Dict dict;
    dict += make_pair("apple", "������");

    CHECK(dict.contains("apple"));
}

TEST(Dict_contains_ghost) {
    Dict dict;
    dict += make_pair("apple", "������");

    CHECK(!dict.contains("banana"));
}

TEST(Dict_contains_char) {
    Dict dict;
    dict += make_pair("apple", "������");

    char word[] = "apple";
    CHECK(dict.contains(word));
}

TEST(Dict_load_equal) {
    create_test_file("test_dict.txt", "apple=������\ncar=������\nbook=�����");

    Dict dict;
    dict.load_from_file("test_dict.txt");

    CHECK_EQUAL(3, dict.size());
    CHECK_EQUAL("������", dict["apple"]);
    CHECK_EQUAL("������", dict["car"]);
    CHECK_EQUAL("�����", dict["book"]);

    remove("test_dict.txt");
}

TEST(Dict_load_dots) {
    create_test_file("test_dict.txt", "apple:������\ncar:������\nbook:�����");

    Dict dict;
    dict.load_from_file("test_dict.txt");

    CHECK_EQUAL(3, dict.size());
    CHECK_EQUAL("������", dict["apple"]);
    CHECK_EQUAL("������", dict["car"]);
    CHECK_EQUAL("�����", dict["book"]);

    remove("test_dict.txt");
}

TEST(Dict_load_tab) {
    create_test_file("test_dict.txt", "apple\t������\ncar\t������\nbook\t�����");

    Dict dict;
    dict.load_from_file("test_dict.txt");

    CHECK_EQUAL(3, dict.size());
    CHECK_EQUAL("������", dict["apple"]);
    CHECK_EQUAL("������", dict["car"]);
    CHECK_EQUAL("�����", dict["book"]);

    remove("test_dict.txt");
}

TEST(Dict_load_ghost) {
    Dict dict;

    CHECK_THROW(dict.load_from_file("non_existent_file.txt"), runtime_error);
}

TEST(Dict_load_invalid) {
    create_test_file("test_dict.txt", "apple������\ncar:������\nbook �����");

    Dict dict;
    dict.load_from_file("test_dict.txt");

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("������", dict["car"]);

    remove("test_dict.txt");
}

TEST(Dict_clear) {
    Dict dict;
    dict += make_pair("apple", "������");
    dict += make_pair("car", "������");

    dict.clear();

    CHECK_EQUAL(0, dict.size());
    CHECK_THROW(dict["apple"], runtime_error);
    CHECK_THROW(dict["car"], runtime_error);
}

TEST(Dict_change) {
    Dict dict;
    dict += make_pair("apple", "������");
    dict += make_pair("apple", "�������");

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("�������", dict["apple"]);
}

TEST(Dict_remove_two_child) {
    Dict dict;
    dict += make_pair("mango", "�����");
    dict += make_pair("apple", "������");
    dict += make_pair("zebra", "�����");

    dict -= "mango"; 

    CHECK_EQUAL(2, dict.size());
    CHECK_EQUAL("������", dict["apple"]);
    CHECK_EQUAL("�����", dict["zebra"]);
    CHECK_THROW(dict["mango"], runtime_error);
}

TEST(Dict_remove_one_child) {
    Dict dict;
    dict += make_pair("mango", "�����");
    dict += make_pair("apple", "������");

    dict -= "mango";

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("������", dict["apple"]);
    CHECK_THROW(dict["mango"], runtime_error);
}

TEST(Dict_remove_zero_child) {
    Dict dict;
    dict += make_pair("mango", "�����");
    dict += make_pair("apple", "������");

    dict -= "apple"; // ������� ����

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("�����", dict["mango"]);
    CHECK_THROW(dict["apple"], runtime_error);
}

TEST(Dict_rempty) {
    Dict dict;

    CHECK_EQUAL(0, dict.size());
    CHECK_THROW(dict["apple"], runtime_error);
    CHECK(!dict.contains("apple"));

    dict -= "apple";
    CHECK_EQUAL(0, dict.size());
}

TEST(Dict_�opy_modify) {
    Dict original;
    original += make_pair("apple", "������");
    original += make_pair("car", "������");

    Dict copy = original;

    CHECK_EQUAL(2, copy.size());
    CHECK_EQUAL("������", copy["apple"]);
    CHECK_EQUAL("������", copy["car"]);

    copy += make_pair("book", "�����");
    copy["car"] = "����������";

    CHECK_EQUAL(2, original.size());
    CHECK_EQUAL("������", original["car"]);
    CHECK_THROW(original["book"], runtime_error);

    CHECK_EQUAL(3, copy.size());
    CHECK_EQUAL("����������", copy["car"]);
    CHECK_EQUAL("�����", copy["book"]);
}

TEST(Dict_clear_full) {
    Dict dict;
    dict += make_pair("apple", "������");
    dict += make_pair("car", "������");
    dict += make_pair("book", "�����");

    CHECK_EQUAL(3, dict.size());

    dict.clear();

    CHECK_EQUAL(0, dict.size());
    CHECK_THROW(dict["apple"], runtime_error);
    CHECK_THROW(dict["car"], runtime_error);
    CHECK_THROW(dict["book"], runtime_error);

    dict += make_pair("new", "�����");
    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("�����", dict["new"]);
}
TEST(Dict_key) {
    Dict dict;

    CHECK_THROW(dict["nonexistent"], runtime_error);

    dict += make_pair("test", "����");
    CHECK_EQUAL("����", dict["test"]);

    dict["test"] = "����� ����";
    CHECK_EQUAL("����� ����", dict["test"]);
}
TEST(Dict_long_words) {
    Dict dict;
    string long_english(1000, 'a');
    string long_russian(1000, '�');

    dict += make_pair(long_english, long_russian);

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL(long_russian, dict[long_english]);
}
