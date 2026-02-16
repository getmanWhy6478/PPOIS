#include <string>
#include <iostream>

class Book {
private:
    std::string title;
    int pages;
public:
    Book(std::string title, int pages) : title(title), pages(pages) {}

    const std::string& getTitle() const { 
        return title; 
    }
    int getPages() const { 
        return pages; 
    }

    bool operator>(const Book& other) const {
        return pages > other.pages;
    }
    bool operator<(const Book& other) const {
        return pages < other.pages;
    }
    friend std::ostream& operator<<(std::ostream& os, const Book& b) {
        return os << b.title << "(" << b.pages << " стр.)";
    }
};