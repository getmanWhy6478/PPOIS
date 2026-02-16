#include "UnitTest++/UnitTest++.h"
#include <vector>
#include <string>
#include "HeapSort.cpp"
#include "StoogeSort.cpp"
#include "Person.h"
#include "Book.h"

TEST(HeapSort_IntArray) {
    HeapSort hsort;
    int arr[] = {5, 1, 4, 2, 3};
    hsort.sort(arr, arr + 5);
    int end[] = {1, 2, 3, 4, 5};
    CHECK_ARRAY_EQUAL(end, arr, 5);
}

TEST(StoogeSort_StringVector) {
    StoogeSort ssort;
    std::vector<std::string> data = {"pear", "apple", "banana"};
    ssort.sort(data.begin(), data.end());
    std::vector<std::string> end = {"apple", "banana", "pear"};
    CHECK_ARRAY_EQUAL(end, data, 3);
}

TEST(HeapSort_Books_ByPages) {
    HeapSort hsort;
    std::vector<Book> books = {
        {"Clean Code", 464},
        {"1984", 328},
        {"The Hobbit", 310},
        {"War and Peace", 1225}
    };
    hsort.sort(books.begin(), books.end());
    CHECK_EQUAL("The Hobbit", books[0].getTitle());
    CHECK_EQUAL(310, books[0].getPages());
    CHECK_EQUAL("War and Peace", books[3].getTitle());
}

TEST(StoogeSort_Books_Array) {
    StoogeSort ssort;
    Book books[] = {
        {"Clean Code", 464},
        {"1984", 328},
        {"The Hobbit", 310},
        {"War and Peace", 1225}
    };
    ssort.sort(books, books + 4);
    CHECK_EQUAL("The Hobbit", books[0].getTitle());
    CHECK_EQUAL(310, books[0].getPages());
    CHECK_EQUAL("War and Peace", books[3].getTitle());
}

TEST(HeapSort_Persons_ByAge) {
    HeapSort hsort;
    std::vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35},
        {"Dave", 20}
    };
    hsort.sort(people.begin(), people.end());
    CHECK_EQUAL("Dave", people[0].getName());
    CHECK_EQUAL(20, people[0].getAge());
    CHECK_EQUAL("Charlie", people[3].getName());
}

TEST(StoogeSort_Persons_Array) {
    StoogeSort ssort;
    Person people[] = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35},
        {"Dave", 20}
    };
    ssort.sort(people, people + 4);
    CHECK_EQUAL("Dave", people[0].getName());
    CHECK_EQUAL(20, people[0].getAge());
    CHECK_EQUAL("Charlie", people[3].getName());
}


TEST(HeapSort_EmptyVector) {
    HeapSort hsort;
    std::vector<int> empty;
    hsort.sort(empty.begin(), empty.end());
    CHECK_EQUAL(0, empty.size());
}

TEST(StoogeSort_SingleElement) {
    StoogeSort ssort;
    int arr[] = {42};
    ssort.sort(arr, arr + 1);
    CHECK_EQUAL(42, arr[0]);
}
int main(){
    return UnitTest::RunAllTests();
}