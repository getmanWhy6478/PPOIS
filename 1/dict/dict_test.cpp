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
    dict += make_pair("apple", "яблоко");

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("яблоко", dict["apple"]);
}

TEST(Dict_add_char_pair) {
    Dict dict;
    char eng[] = "car";
    char rus[] = "машина";
    dict += make_pair(eng, rus);

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("машина", dict["car"]);
}

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

TEST(Dict_remove_string) {
    Dict dict;
    dict += make_pair("apple", "яблоко");
    dict += make_pair("car", "машина");

    dict -= "apple";

    CHECK_EQUAL(1, dict.size());
    CHECK_THROW(dict["apple"], runtime_error);
    CHECK_EQUAL("машина", dict["car"]);
}

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

TEST(Dict_remove_ghost) {
    Dict dict;
    dict += make_pair("apple", "яблоко");

    dict -= "banana";

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("яблоко", dict["apple"]);
}

TEST(Dict_access) {
    Dict dict;
    dict += make_pair("apple", "яблоко");

    CHECK_EQUAL("яблоко", dict["apple"]);
}

TEST(Dict_access_ghost) {
    Dict dict;

    CHECK_THROW(dict["apple"], runtime_error);
}

TEST(Dict_change_translation) {
    Dict dict;
    dict += make_pair("car", "машина");

    dict["car"] = "автомобиль";

    CHECK_EQUAL("автомобиль", dict["car"]);
}

TEST(Dict_copy_constructor) {
    Dict original;
    original += make_pair("apple", "яблоко");
    original += make_pair("car", "машина");

    Dict copy(original);

    CHECK_EQUAL(2, copy.size());
    CHECK_EQUAL("яблоко", copy["apple"]);
    CHECK_EQUAL("машина", copy["car"]);

    copy += make_pair("book", "книга");
    CHECK_EQUAL(3, copy.size());
    CHECK_EQUAL(2, original.size());
}

TEST(Dict_assignment) {
    Dict original;
    original += make_pair("apple", "яблоко");
    original += make_pair("car", "машина");

    Dict assigned;
    assigned = original;

    CHECK_EQUAL(2, assigned.size());
    CHECK_EQUAL("яблоко", assigned["apple"]);
    CHECK_EQUAL("машина", assigned["car"]);

    assigned += make_pair("book", "книга");
    CHECK_EQUAL(3, assigned.size());
    CHECK_EQUAL(2, original.size());
}

TEST(Dict_contains) {
    Dict dict;
    dict += make_pair("apple", "яблоко");

    CHECK(dict.contains("apple"));
}

TEST(Dict_contains_ghost) {
    Dict dict;
    dict += make_pair("apple", "яблоко");

    CHECK(!dict.contains("banana"));
}

TEST(Dict_contains_char) {
    Dict dict;
    dict += make_pair("apple", "яблоко");

    char word[] = "apple";
    CHECK(dict.contains(word));
}

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

TEST(Dict_load_ghost) {
    Dict dict;

    CHECK_THROW(dict.load_from_file("non_existent_file.txt"), runtime_error);
}

TEST(Dict_load_invalid) {
    create_test_file("test_dict.txt", "appleяблоко\ncar:машина\nbook книга");

    Dict dict;
    dict.load_from_file("test_dict.txt");

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("машина", dict["car"]);

    remove("test_dict.txt");
}

TEST(Dict_clear) {
    Dict dict;
    dict += make_pair("apple", "яблоко");
    dict += make_pair("car", "машина");

    dict.clear();

    CHECK_EQUAL(0, dict.size());
    CHECK_THROW(dict["apple"], runtime_error);
    CHECK_THROW(dict["car"], runtime_error);
}

TEST(Dict_change) {
    Dict dict;
    dict += make_pair("apple", "яблоко");
    dict += make_pair("apple", "яблочко");

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("яблочко", dict["apple"]);
}

TEST(Dict_remove_two_child) {
    Dict dict;
    dict += make_pair("mango", "манго");
    dict += make_pair("apple", "яблоко");
    dict += make_pair("zebra", "зебра");

    dict -= "mango"; 

    CHECK_EQUAL(2, dict.size());
    CHECK_EQUAL("яблоко", dict["apple"]);
    CHECK_EQUAL("зебра", dict["zebra"]);
    CHECK_THROW(dict["mango"], runtime_error);
}

TEST(Dict_remove_one_child) {
    Dict dict;
    dict += make_pair("mango", "манго");
    dict += make_pair("apple", "яблоко");

    dict -= "mango";

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("яблоко", dict["apple"]);
    CHECK_THROW(dict["mango"], runtime_error);
}

TEST(Dict_remove_zero_child) {
    Dict dict;
    dict += make_pair("mango", "манго");
    dict += make_pair("apple", "яблоко");

    dict -= "apple"; // Удаляем лист

    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("манго", dict["mango"]);
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

TEST(Dict_сopy_modify) {
    Dict original;
    original += make_pair("apple", "яблоко");
    original += make_pair("car", "машина");

    Dict copy = original;

    CHECK_EQUAL(2, copy.size());
    CHECK_EQUAL("яблоко", copy["apple"]);
    CHECK_EQUAL("машина", copy["car"]);

    copy += make_pair("book", "книга");
    copy["car"] = "автомобиль";

    CHECK_EQUAL(2, original.size());
    CHECK_EQUAL("машина", original["car"]);
    CHECK_THROW(original["book"], runtime_error);

    CHECK_EQUAL(3, copy.size());
    CHECK_EQUAL("автомобиль", copy["car"]);
    CHECK_EQUAL("книга", copy["book"]);
}

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

    dict += make_pair("new", "новое");
    CHECK_EQUAL(1, dict.size());
    CHECK_EQUAL("новое", dict["new"]);
}
TEST(Dict_key) {
    Dict dict;

    CHECK_THROW(dict["nonexistent"], runtime_error);

    dict += make_pair("test", "тест");
    CHECK_EQUAL("тест", dict["test"]);

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