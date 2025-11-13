#include "../include/Courier.h"
#include "../include/Errors.h"
#include <iostream>
Courier::Courier()
    : Worker("", 0), phoneNumber("+0000000000") {}

Courier::Courier(const string& name, int salary, const string& phoneNumber)
    : Worker(name, salary), phoneNumber(phoneNumber) {}

string Courier::getPhoneNumber() const {
    return phoneNumber;
}

void Courier::setPhoneNumber(const string& phoneNumber) {
    if(phoneNumber[0] == '+')
        this->phoneNumber = phoneNumber;
    else{
        throw InvalidNumberError();
    }
}

void Courier::textUser(const string& text) {
    cout << "[SMS from " << phoneNumber << "] " << text << endl;
}
bool Courier::operator==(const Courier& other) const {
    return this->name == other.name && this->salary == other.salary && this->phoneNumber == other.phoneNumber;
}
ostream& operator<<(ostream& os, const Courier& courier) {
    os << "Courier: " << courier.name << ", Salary = " << courier.salary << ", Phone:" << courier.phoneNumber;
    return os;
}