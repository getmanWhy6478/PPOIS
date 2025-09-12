#include "Dict.h"
#include <gtest/gtest.h>

TEST(DictTest, constructor) {
    Dict dict;
    EXPECT_EQ(dict.size(), 0);
    EXPECT_FALSE(dict.contains("test"));
}

// “ест добавлени€ слов
TEST(DictTest, add_words) {
    Dict dict;

    dict += make_pair("apple", "€блоко");
    EXPECT_EQ(dict.size(), 1);
    EXPECT_TRUE(dict.contains("apple"));
    EXPECT_EQ(dict["apple"], "€блоко");

    const char car[5] = "car";
    const char car1[10] = "машина";
    dict += make_pair(car, car1);
    EXPECT_EQ(dict.size(), 2);
    EXPECT_TRUE(dict.contains("car"));
    EXPECT_EQ(dict["car"], "машина");
}

TEST(DictTest, update_translation) {
    Dict dict;
    dict += make_pair("apple", "€блоко");

    dict["apple"] = "€блочко";
    EXPECT_EQ(dict["apple"], "€блочко");

    dict += make_pair("apple", "€блоко");
    EXPECT_EQ(dict["apple"], "€блоко");
}

TEST(DictTest, remove_words) {
    Dict dict;
    dict += make_pair("apple", "€блоко");
    dict += make_pair("car", "машина");
    dict += make_pair("actor", "актЄр");

    EXPECT_EQ(dict.size(), 3);

    dict -= "actor";
    EXPECT_EQ(dict.size(), 2);
    EXPECT_FALSE(dict.contains("actor"));
    EXPECT_TRUE(dict.contains("car"));

    dict -= "car";
    EXPECT_EQ(dict.size(), 1);
    EXPECT_FALSE(dict.contains("car"));

    dict -= "non_existent";
    EXPECT_EQ(dict.size(), 1);
}

TEST(DictTest, not_exist) {
    Dict dict;
    dict += make_pair("apple", "€блоко");

    EXPECT_THROW(dict["nonexistent"], runtime_error);
    EXPECT_THROW(dict["NONEXISTENT"], runtime_error);
}

TEST(DictTest, change) {
    Dict dict;
    dict += make_pair("apple", "€блоко");

    dict["apple"] = "€блочко";
    EXPECT_EQ(dict["apple"], "€блочко");
}

TEST(DictTest, copy_constructor) {
    Dict dict1, dict2;
    dict1 += make_pair("apple", "€блоко");
    dict1 += make_pair("car", "машина");

    //  опирование словар€
    dict2 = dict1;

    EXPECT_EQ(dict1.size(), dict2.size());
    EXPECT_EQ(dict2["apple"], "€блоко");
    EXPECT_EQ(dict2["car"], "машина");

    dict1["apple"] = "€блочко";
    EXPECT_EQ(dict1["apple"], "€блочко");
    EXPECT_EQ(dict2["apple"], "€блоко");
}

TEST(DictTest, addition) {
    Dict dict1;
    dict1 += make_pair("apple", "€блоко");
    dict1 += make_pair("car", "машина");

    Dict dict2;
    dict2 += make_pair("book", "книга");

    dict2 = dict1;

    EXPECT_EQ(dict1.size(), dict2.size());
    EXPECT_EQ(dict2["apple"], "€блоко");
    EXPECT_EQ(dict2["car"], "машина");
    EXPECT_FALSE(dict2.contains("book"));

    dict1["apple"] = "€блочко";
    EXPECT_EQ(dict1["apple"], "€блочко");
    EXPECT_EQ(dict2["apple"], "€блоко");
}

TEST(DictTest, contains) {
    Dict dict;
    dict += make_pair("apple", "€блоко");

    EXPECT_TRUE(dict.contains("apple"));
    EXPECT_TRUE(dict.contains("apple"));
    EXPECT_FALSE(dict.contains("car"));
    EXPECT_FALSE(dict.contains("car"));
}

TEST(DictTest, clear) {
    Dict dict;
    dict += make_pair("apple", "€блоко");
    dict += make_pair("car", "машина");

    EXPECT_EQ(dict.size(), 2);

    dict.clear();

    EXPECT_EQ(dict.size(), 0);
    EXPECT_FALSE(dict.contains("apple"));
    EXPECT_FALSE(dict.contains("car"));
}

TEST(DictTest, load_from_file) {
    Dict dict;

    const string filename = "test_dict.txt";
    ofstream file(filename);
    file << "apple=€блоко\n";
    file << "car:машина\n";
    file << "book\tкнига\n";
    file << "house = дом\n";
    file.close();

    dict.load_from_file(filename);

    EXPECT_EQ(dict.size(), 4);
    EXPECT_EQ(dict["apple"], "€блоко");
    EXPECT_EQ(dict["car"], "машина");
    EXPECT_EQ(dict["book"], "книга");
    EXPECT_EQ(dict["house"], "дом");

    remove(filename.c_str());
}

TEST(DictTest, ghost_load) {
    Dict dict;

    EXPECT_THROW(dict.load_from_file("ghost.txt"), runtime_error);
}

TEST(DictTest, empty_load) {
    Dict dict;

    const string filename = "empty_test.txt";
    ofstream file(filename);
    file.close();

    dict.load_from_file(filename);

    EXPECT_EQ(dict.size(), 0);

    remove(filename.c_str());
}

TEST(DictTest, invalid_load) {
    Dict dict;

    const string filename = "invalid_test.txt";
    ofstream file(filename);
    file << "apple=€блоко\n";
    file << "invalid_line_without_delimiter\n";
    file << "=пустой_ключ\n"; // ѕустой ключ
    file << "key=\n"; // ѕустое значение
    file << "car:машина\n";
    file.close();

    dict.load_from_file(filename);

    EXPECT_EQ(dict.size(), 2);
    EXPECT_EQ(dict["apple"], "€блоко");
    EXPECT_EQ(dict["car"], "машина");

    remove(filename.c_str());
}

TEST(DictTest, large_dictionary) {
    Dict dict;

    for (int i = 0; i < 100; ++i) {
        string eng = "word" + to_string(i);
        string rus = "слово" + to_string(i);
        dict += make_pair(eng, rus);
    }

    EXPECT_EQ(dict.size(), 100);

    EXPECT_EQ(dict["word0"], "слово0");
    EXPECT_EQ(dict["word50"], "слово50");
    EXPECT_EQ(dict["word99"], "слово99");
}

TEST(DictTest, case_sensitive) {
    Dict dict;
    dict += make_pair("Apple", "€блоко");

    EXPECT_TRUE(dict.contains("Apple"));
    EXPECT_FALSE(dict.contains("apple"));
    EXPECT_FALSE(dict.contains("APPLE"));

    dict += make_pair("apple", "маленькое €блоко");

    EXPECT_TRUE(dict.contains("Apple"));
    EXPECT_TRUE(dict.contains("apple"));
    EXPECT_EQ(dict["Apple"], "€блоко");
    EXPECT_EQ(dict["apple"], "маленькое €блоко");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}