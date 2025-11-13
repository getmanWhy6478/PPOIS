#include "UnitTest++/UnitTest++.h"
#include <vector>
#include <string>
#include "HeapSort.cpp"
#include "StoogeSort.cpp"
#include "Person.h"
#include "Book.h"

TEST(HeapSort_Ints) {
    std::vector<int> data = {5, 2, 9, 1, 3};
    heapsort(data.begin(), data.end());
    std::vector<int> endData = {1, 2, 3, 5, 9};
    CHECK_ARRAY_EQUAL(endData, data, data.size());
}

TEST(StoogeSort_Strings) {
    std::vector<std::string> data = {"banana", "apple", "cherry", "date"};
    stoogeSort(data.begin(), data.end());
    std::vector<std::string> endData = {"apple", "banana", "cherry", "date"};
    CHECK_ARRAY_EQUAL(endData, data, data.size());
}

TEST(HeapSort_Persons_ByAge) {
    std::vector<Person> people = {
        {"Alice", 30}, {"Bob", 25}, {"Charlie", 35}, {"Dave", 20}
    };
    heapsort(people.begin(), people.end());
    CHECK_EQUAL("Dave", people[0].getName());
    CHECK_EQUAL(20, people[0].getAge());
    CHECK_EQUAL("Charlie", people[3].getName());
}

TEST(StoogeSort_Books_ByPages) {
    std::vector<Book> books = {
        {"Clean Code", 464}, {"1984", 328}, {"The Hobbit", 310}, {"War and Peace", 1225}
    };
    stoogeSort(books.begin(), books.end());
    CHECK_EQUAL("The Hobbit", books[0].getTitle());
    CHECK_EQUAL(310, books[0].getPages());
    CHECK_EQUAL("War and Peace", books[3].getTitle());
}

TEST(HeapSort_EmptyVector) {
    std::vector<int> empty;
    heapsort(empty.begin(), empty.end());
    CHECK_EQUAL(0, empty.size());
}

TEST(StoogeSort_SingleElement) {
    std::vector<int> one = {42};
    stoogeSort(one.begin(), one.end());
    CHECK_EQUAL(42, one[0]);
}