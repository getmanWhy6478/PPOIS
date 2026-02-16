#include "../include/Employee.h"
#include "../include/Gallery.h"
#include <ctime>

Employee::Employee(const std::string& firstName, const std::string& lastName,
                   const std::string& employeeId, Gallery* gallery)
    : firstName(firstName), lastName(lastName), employeeId(employeeId),
      gallery(gallery), salary(0.0), hireYear(0) {
}

std::string Employee::getFirstName() const {
    return firstName;
}

void Employee::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

std::string Employee::getLastName() const {
    return lastName;
}

void Employee::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

std::string Employee::getFullName() const {
    return firstName + " " + lastName;
}

std::string Employee::getEmployeeId() const {
    return employeeId;
}

void Employee::setEmployeeId(const std::string& id) {
    this->employeeId = id;
}

std::string Employee::getPhone() const {
    return phone;
}

void Employee::setPhone(const std::string& phone) {
    this->phone = phone;
}

int Employee::getHireYear() const {
    return hireYear;
}

void Employee::setHireYear(int year) {
    this->hireYear = year;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}

Gallery* Employee::getGallery() const {
    return gallery;
}

void Employee::setGallery(Gallery* gallery) {
    this->gallery = gallery;
}

int Employee::getYearsOfService() const {
    if (hireYear <= 0) return 0;
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    int currentYear = now->tm_year + 1900;
    return currentYear - hireYear;
}

