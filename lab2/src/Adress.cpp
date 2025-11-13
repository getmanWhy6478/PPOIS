#include "../include/Adress.h"

Adress::Adress() : city(""), street(""), house(0) {}

Adress::Adress(const string& city, const string& street, int house)
    : city(city), street(street), house(house) {}

string Adress::getCity() {
    return city;
}

void Adress::setCity(const string& city) {
    this->city = city;
}

string Adress::getStreet() {
    return street;
}

void Adress::setStreet(const string& street) {
    this->street = street;
}

int Adress::getHouse() {
    return house;
}

void Adress::setHouse(int house) {
    this->house = house;
}
