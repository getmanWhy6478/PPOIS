#include "../include/Oven.h"
Oven::Oven()
    : KitchenAppliance("", true, false), maxTemperature(0){}
Oven::Oven(const string& name, bool isElectric, int maxTemperature, bool isAvailable)
    : KitchenAppliance(name, isElectric, isAvailable), maxTemperature(maxTemperature) {}

int Oven::getMaxTemperature() const {
    return maxTemperature;
}

void Oven::setMaxTemperature(int temp) {
    maxTemperature = temp;
}
