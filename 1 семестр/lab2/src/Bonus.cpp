#include "../include/Bonus.h"
#include "../include/Errors.h"
#include <ctime>

Bonus::Bonus()
    : name(""), discount(0.0), expirationTime(time(nullptr)) {}

Bonus::Bonus(const string& name, double discount, time_t expirationTime, bool isActive)
    : name(name), expirationTime(expirationTime) {
    setDiscount(discount);
}

string Bonus::getName() const {
    return name;
}

double Bonus::getDiscount() const {
    return discount;
}

time_t Bonus::getExpirationTime() const {
    return expirationTime;
}

void Bonus::setName(const string& name) {
    this->name = name;
}

void Bonus::setDiscount(double discount) {
    this->discount = discount;
}

void Bonus::setExpirationTime(time_t time) {
    expirationTime = time;
}

bool Bonus::isExpired() const {
    return time(nullptr) > expirationTime;
}

bool Bonus::operator==(const Bonus& other) const {
        return this->name == other.name &&
               this->discount == other.discount &&
               this->expirationTime == other.expirationTime;
}
    
