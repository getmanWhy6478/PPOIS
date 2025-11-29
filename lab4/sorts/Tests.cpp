#include "UnitTest++/UnitTest++.h"
#include <vector>
#include <string>
#include "HeapSort.cpp"
#include "StoogeSort.cpp"
#include "Person.h"
#include "Book.h"

TEST(HeapSort_IntArray) {
    int arr[] = {5, 1, 4, 2, 3};
    HeapSort::sort(arr, arr + 5);
    int end[] = {1, 2, 3, 4, 5};
    CHECK_ARRAY_EQUAL(end, arr, 5);
}

TEST(StoogeSort_StringVector) {
    std::vector<std::string> data = {"pear", "apple", "banana"};
    StoogeSort::sort(data.begin(), data.end());
    std::vector<std::string> end = {"apple", "banana", "pear"};
    CHECK_ARRAY_EQUAL(end, data, 3);
}

TEST(HeapSort_Books_ByPages) {
    std::vector<Book> books = {
        {"Clean Code", 464},
        {"1984", 328},
        {"The Hobbit", 310},
        {"War and Peace", 1225}
    };
    HeapSort::sort(books.begin(), books.end());
    CHECK_EQUAL("The Hobbit", books[0].getTitle());
    CHECK_EQUAL(310, books[0].getPages());
    CHECK_EQUAL("War and Peace", books[3].getTitle());
}

TEST(StoogeSort_Books_Array) {
    Book books[] = {
        {"Clean Code", 464},
        {"1984", 328},
        {"The Hobbit", 310},
        {"War and Peace", 1225}
    };
    StoogeSort::sort(books, books + 4);
    CHECK_EQUAL("The Hobbit", books[0].getTitle());
    CHECK_EQUAL(310, books[0].getPages());
    CHECK_EQUAL("War and Peace", books[3].getTitle());
}

TEST(HeapSort_Persons_ByAge) {
    std::vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35},
        {"Dave", 20}
    };
    HeapSort::sort(people.begin(), people.end());
    CHECK_EQUAL("Dave", people[0].getName());
    CHECK_EQUAL(20, people[0].getAge());
    CHECK_EQUAL("Charlie", people[3].getName());
}

TEST(StoogeSort_Persons_Array) {
    Person people[] = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35},
        {"Dave", 20}
    };
    StoogeSort::sort(people, people + 4);
    CHECK_EQUAL("Dave", people[0].getName());
    CHECK_EQUAL(20, people[0].getAge());
    CHECK_EQUAL("Charlie", people[3].getName());
}


TEST(HeapSort_EmptyVector) {
    std::vector<int> empty;
    HeapSort::sort(empty.begin(), empty.end());
    CHECK_EQUAL(0, empty.size());
}

TEST(StoogeSort_SingleElement) {
    int arr[] = {42};
    StoogeSort::sort(arr, arr + 1);
    CHECK_EQUAL(42, arr[0]);
}
int main(){
    return UnitTest::RunAllTests();
}