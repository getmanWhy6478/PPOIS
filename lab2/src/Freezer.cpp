#include "../include/Freezer.h"
Freezer::Freezer(const string& name, bool isElectric, int minTemperature, bool isAvailable)
    : KitchenAppliance(name, isElectric, isAvailable), minTemperature(minTemperature) {}

int Freezer::getMinTemperature() const {
    return minTemperature;
}

void Freezer::setMinTemperature(int temp) {
    minTemperature = temp;
}

