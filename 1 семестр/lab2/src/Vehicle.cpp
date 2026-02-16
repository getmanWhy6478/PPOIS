#include "../include/Vehicle.h"

Vehicle::Vehicle()
    : model(""), capacity(0) {}

Vehicle::Vehicle(const string& model, int capacity)
    : model(model), capacity(capacity) {}

string Vehicle::getModel() const {
    return model;
}


int Vehicle::getCapacity() const {
    return capacity;
}

void Vehicle::setModel(const string& model) {
    this->model = model;
}


void Vehicle::setCapacity(int capacity) {
    this->capacity = (capacity >= 0) ? capacity : 0;
}
bool Vehicle::operator==(const Vehicle& other) const {
        return model == other.model && capacity == other.capacity;
}
ostream& operator<<(ostream& os, const Vehicle& vehicle) {
    os << "Vehicle: "
       << "Model = " << vehicle.model
       << ", Capacity = " << vehicle.capacity;
    return os;
}