#include "../include/Courier.h"
#include "../include/Errors.h"
#include <iostream>
Courier::Courier()
    : Worker("", 0), phoneNumber("+0000000000") {}

Courier::Courier(const string& name, int age, const string& phoneNumber)
    : Worker(name, age), phoneNumber(phoneNumber) {}

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
