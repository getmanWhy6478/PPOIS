#include "Dict.h"
#include <gtest/gtest.h>

TEST(DictTest, constructor) {
    Dict dict;
    EXPECT_EQ(dict.size(), 0);
    EXPECT_FALSE(dict.contains("test"));
}

// ���� ���������� ����
TEST(DictTest, add_words) {
    Dict dict;

    dict += make_pair("apple", "������");
    EXPECT_EQ(dict.size(), 1);
    EXPECT_TRUE(dict.contains("apple"));
    EXPECT_EQ(dict["apple"], "������");

    const char car[5] = "car";
    const char car1[10] = "������";
    dict += make_pair(car, car1);
    EXPECT_EQ(dict.size(), 2);
    EXPECT_TRUE(dict.contains("car"));
    EXPECT_EQ(dict["car"], "������");
}

TEST(DictTest, update_translation) {
    Dict dict;
    dict += make_pair("apple", "������");

    dict["apple"] = "�������";
    EXPECT_EQ(dict["apple"], "�������");

    dict += make_pair("apple", "������");
    EXPECT_EQ(dict["apple"], "������");
}

TEST(DictTest, remove_words) {
    Dict dict;
    dict += make_pair("apple", "������");
    dict += make_pair("car", "������");
    dict += make_pair("actor", "����");

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
    dict += make_pair("apple", "������");

    EXPECT_THROW(dict["nonexistent"], runtime_error);
    EXPECT_THROW(dict["NONEXISTENT"], runtime_error);
}

TEST(DictTest, change) {
    Dict dict;
    dict += make_pair("apple", "������");

    dict["apple"] = "�������";
    EXPECT_EQ(dict["apple"], "�������");
}

TEST(DictTest, copy_constructor) {
    Dict dict1, dict2;
    dict1 += make_pair("apple", "������");
    dict1 += make_pair("car", "������");

    // ����������� �������
    dict2 = dict1;

    EXPECT_EQ(dict1.size(), dict2.size());
    EXPECT_EQ(dict2["apple"], "������");
    EXPECT_EQ(dict2["car"], "������");

    dict1["apple"] = "�������";
    EXPECT_EQ(dict1["apple"], "�������");
    EXPECT_EQ(dict2["apple"], "������");
}

TEST(DictTest, addition) {
    Dict dict1;
    dict1 += make_pair("apple", "������");
    dict1 += make_pair("car", "������");

    Dict dict2;
    dict2 += make_pair("book", "�����");

    dict2 = dict1;

    EXPECT_EQ(dict1.size(), dict2.size());
    EXPECT_EQ(dict2["apple"], "������");
    EXPECT_EQ(dict2["car"], "������");
    EXPECT_FALSE(dict2.contains("book"));

    dict1["apple"] = "�������";
    EXPECT_EQ(dict1["apple"], "�������");
    EXPECT_EQ(dict2["apple"], "������");
}

TEST(DictTest, contains) {
    Dict dict;
    dict += make_pair("apple", "������");

    EXPECT_TRUE(dict.contains("apple"));
    EXPECT_TRUE(dict.contains("apple"));
    EXPECT_FALSE(dict.contains("car"));
    EXPECT_FALSE(dict.contains("car"));
}

TEST(DictTest, clear) {
    Dict dict;
    dict += make_pair("apple", "������");
    dict += make_pair("car", "������");

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
    file << "apple=������\n";
    file << "car:������\n";
    file << "book\t�����\n";
    file << "house = ���\n";
    file.close();

    dict.load_from_file(filename);

    EXPECT_EQ(dict.size(), 4);
    EXPECT_EQ(dict["apple"], "������");
    EXPECT_EQ(dict["car"], "������");
    EXPECT_EQ(dict["book"], "�����");
    EXPECT_EQ(dict["house"], "���");

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
    file << "apple=������\n";
    file << "invalid_line_without_delimiter\n";
    file << "=������_����\n"; // ������ ����
    file << "key=\n"; // ������ ��������
    file << "car:������\n";
    file.close();

    dict.load_from_file(filename);

    EXPECT_EQ(dict.size(), 2);
    EXPECT_EQ(dict["apple"], "������");
    EXPECT_EQ(dict["car"], "������");

    remove(filename.c_str());
}

TEST(DictTest, large_dictionary) {
    Dict dict;

    for (int i = 0; i < 100; ++i) {
        string eng = "word" + to_string(i);
        string rus = "�����" + to_string(i);
        dict += make_pair(eng, rus);
    }

    EXPECT_EQ(dict.size(), 100);

    EXPECT_EQ(dict["word0"], "�����0");
    EXPECT_EQ(dict["word50"], "�����50");
    EXPECT_EQ(dict["word99"], "�����99");
}

TEST(DictTest, case_sensitive) {
    Dict dict;
    dict += make_pair("Apple", "������");

    EXPECT_TRUE(dict.contains("Apple"));
    EXPECT_FALSE(dict.contains("apple"));
    EXPECT_FALSE(dict.contains("APPLE"));

    dict += make_pair("apple", "��������� ������");

    EXPECT_TRUE(dict.contains("Apple"));
    EXPECT_TRUE(dict.contains("apple"));
    EXPECT_EQ(dict["Apple"], "������");
    EXPECT_EQ(dict["apple"], "��������� ������");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}