#include "../include/Warehouse.h"

Warehouse::Warehouse()
    :Place(), requirement(), capacity(0) {}

Warehouse::Warehouse(int capacity, int area, const WarehouseRequirement& requirement, const vector<FoodPosition>& stored)
    : capacity(capacity), Place(area), requirement(requirement), stored(stored) {}

WarehouseRequirement Warehouse::getRequirement() const {
    return requirement;
}

void Warehouse::setRequirement(const WarehouseRequirement& requirement) {
    this->requirement = requirement;
}

std::vector<FoodPosition> Warehouse::getStored() const {
    return stored;
}

void Warehouse::setStored(FoodPosition& foodPosition) {
    for (auto& entry : stored) {
        if (entry.product == foodPosition.product) {
            entry.amount += foodPosition.amount;
            return;
        }
    }

    stored.push_back(foodPosition);
}

int Warehouse::getCapacity() const {
    return capacity;
}

void Warehouse::setCapacity(int capacity) {
    this->capacity = capacity;
}

bool Warehouse::isFull() const {
    int total = 0;
    for (const auto& entry : stored) {
        total += entry.amount;
    }
    return total >= capacity;
}
