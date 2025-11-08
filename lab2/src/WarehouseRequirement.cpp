#include "../include/WarehouseRequirement.h"

WarehouseRequirement::WarehouseRequirement()
    : PlaceRequirement(),minCapacity(0), requiresCooling(false) {}

WarehouseRequirement::WarehouseRequirement(int minArea, bool requiresElectricity, bool mustBeAccessible,
                                           double minCapacity, bool requiresCooling)
    : PlaceRequirement(minArea, requiresElectricity, mustBeAccessible),
      minCapacity(minCapacity), requiresCooling(requiresCooling) {}

double WarehouseRequirement::getMinCapacity() const {
    return minCapacity;
}

bool WarehouseRequirement::getRequiresCooling() const {
    return requiresCooling;
}

void WarehouseRequirement::setMinCapacity(int capacity) {
    this->minCapacity = capacity;
}

void WarehouseRequirement::setRequiresCooling(bool cooling) {
    this->requiresCooling = cooling;
}


bool WarehouseRequirement::isWarehouseSatisfiedBy(int actualArea, bool hasElectricity, bool isAccessible,
                                         double actualVolume, bool hasCooling) const {
    return this->isSatisfiedBy(actualArea, hasElectricity, isAccessible) &&
           actualVolume >= minCapacity &&
           (!requiresCooling || hasCooling);
}
