#include "Vehicle.h"

Vehicle::Vehicle()
    : type(""), model(""), licensePlate(""), capacity(0) {}

Vehicle::Vehicle(const string& type, const string& model,
                 const string& licensePlate, int capacity)
    : type(type), model(model), licensePlate(licensePlate), capacity(capacity) {}

string Vehicle::getType() const {
    return type;
}

string Vehicle::getModel() const {
    return model;
}

string Vehicle::getLicensePlate() const {
    return licensePlate;
}

int Vehicle::getCapacity() const {
    return capacity;
}

void Vehicle::setType(const string& type) {
    this->type = type;
}

void Vehicle::setModel(const string& model) {
    this->model = model;
}

void Vehicle::setLicensePlate(const string& licensePlate) {
    this->licensePlate = licensePlate;
}

void Vehicle::setCapacity(int capacity) {
    this->capacity = (capacity >= 0) ? capacity : 0;
}
