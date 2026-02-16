#include "../include/Freezer.h"

Freezer::Freezer()
    : KitchenAppliance("", true, false), minTemperature(0){}

Freezer::Freezer(const string& name, bool isElectric, int minTemperature, bool isAvailable)
    : KitchenAppliance(name, isElectric, isAvailable), minTemperature(minTemperature) {}

int Freezer::getMinTemperature() const {
    return minTemperature;
}

void Freezer::setMinTemperature(int temp) {
    minTemperature = temp;
}
void Freezer::cold(Eatable& eat){
    eat.setExparationTime(eat.getExparationTime() * 2.5);
}
