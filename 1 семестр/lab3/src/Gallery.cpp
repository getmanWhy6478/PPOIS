#include "../include/Gallery.h"
#include "../include/Room.h"
#include "../include/Exhibition.h"
#include "../include/Collection.h"
#include "../include/Employee.h"
#include <algorithm>

Gallery::Gallery(const std::string& name, const std::string& address,
                 const std::string& city, const std::string& country)
    : name(name), address(address), city(city), country(country),
      admissionPrice(0.0), maxCapacity(0) {
}

std::string Gallery::getName() const {
    return name;
}

void Gallery::setName(const std::string& name) {
    this->name = name;
}

std::string Gallery::getAddress() const {
    return address;
}

void Gallery::setAddress(const std::string& address) {
    this->address = address;
}

std::string Gallery::getCity() const {
    return city;
}

void Gallery::setCity(const std::string& city) {
    this->city = city;
}

std::string Gallery::getCountry() const {
    return country;
}

void Gallery::setCountry(const std::string& country) {
    this->country = country;
}

void Gallery::addRoom(Room* room) {
    rooms.push_back(room);
}

std::vector<Room*> Gallery::getRooms() const {
    return rooms;
}

void Gallery::addExhibition(Exhibition* exhibition) {
    exhibitions.push_back(exhibition);
}

std::vector<Exhibition*> Gallery::getExhibitions() const {
    return exhibitions;
}

void Gallery::addCollection(Collection* collection) {
    collections.push_back(collection);
}

std::vector<Collection*> Gallery::getCollections() const {
    return collections;
}

void Gallery::addEmployee(Employee* employee) {
    employees.push_back(employee);
}

std::vector<Employee*> Gallery::getEmployees() const {
    return employees;
}

double Gallery::getAdmissionPrice() const {
    return admissionPrice;
}

void Gallery::setAdmissionPrice(double price) {
    this->admissionPrice = price;
}

int Gallery::getMaxCapacity() const {
    return maxCapacity;
}

void Gallery::setMaxCapacity(int capacity) {
    this->maxCapacity = capacity;
}

bool Gallery::borrow(Collection& collection, Gallery& other) {
    for (size_t i = 0; i < other.collections.size(); ++i) {
        if (*(other.collections[i]) == collection) {
            collections.push_back(other.collections[i]); 
            other.collections.erase(other.collections.begin() + i);
            return true;
        }
    }
    return false;
}