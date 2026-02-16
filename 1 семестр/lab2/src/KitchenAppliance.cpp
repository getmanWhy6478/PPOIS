#include "../include/KitchenAppliance.h"

KitchenAppliance::KitchenAppliance()
    : name(""), isElectric(false), isAvailable(true) {}

KitchenAppliance::KitchenAppliance(const std::string& name, bool isElectric, bool isAvailable)
    : name(name), isElectric(isElectric), isAvailable(isAvailable) {}

std::string KitchenAppliance::getName() const {
    return name;
}

bool KitchenAppliance::getIsElectric() const {
    return isElectric;
}

bool KitchenAppliance::getIsAvailable() const {
    return isAvailable;
}

void KitchenAppliance::setName(const std::string& name) {
    this->name = name;
}

void KitchenAppliance::setIsElectric(bool isElectric) {
    this->isElectric = isElectric;
}

void KitchenAppliance::setIsAvailable(bool isAvailable) {
    this->isAvailable = isAvailable;
}
