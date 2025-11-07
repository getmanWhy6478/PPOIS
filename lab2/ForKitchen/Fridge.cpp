#include "Fridge.h"

Fridge::Fridge(const string& name, bool isElectric, int capacityLiters, bool isAvailable)
    : KitchenAppliance(name, isElectric, isAvailable), capacityLiters(capacityLiters) {}

int Fridge::getCapacityLiters() const {
    return capacityLiters;
}

void Fridge::setCapacityLiters(int capacity) {
    capacityLiters = capacity;
}
