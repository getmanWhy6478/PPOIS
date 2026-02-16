#include "../include/Bike.h"

Bike::Bike() : Vehicle("", 0), isElectric(false) {}

Bike::Bike(const string& model, int capacity, bool isElectric)
    : Vehicle(model, capacity), isElectric(isElectric) {}

bool Bike::getIsElectric() const {
    return isElectric;
}

void Bike::setIsElectric(bool value) {
    isElectric = value;
}
void Bike::speedUp(Delivery& delivery){
    delivery.setTime(delivery.getTime() / 2);
}