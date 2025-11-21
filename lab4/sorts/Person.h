#include <iostream>
#include <vector>
#include <algorithm>

class Person {
private:
    std::string name;
    int age;    
public:
    Person(std::string name, int age) : name(name), age(age) {}

    int getAge() const { 
        return age; 
    }
    const std::string& getName() const { 
        return name; 
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        return os << p.name << " (" << p.age << ")";
    }

    bool operator<(const Person& other) const {
        return age < other.age;
    }
    bool operator>(const Person& other) const {
        return age > other.age;
    }
};