#include "../include/DinningRoomRequirement.h"

DinningRoomRequirement::DinningRoomRequirement()
    : PlaceRequirement(), minTablesCount(0), mustBeOpen(false) {}

DinningRoomRequirement::DinningRoomRequirement(int minArea, bool requiresElectricity, bool mustBeAccessible,
                                       int minTablesCount, bool mustBeOpen)
    : PlaceRequirement(minArea, requiresElectricity, mustBeAccessible),
      minTablesCount(minTablesCount), mustBeOpen(mustBeOpen) {}

int DinningRoomRequirement::getMinTablesCount() const {
    return minTablesCount;
}

bool DinningRoomRequirement::getMustBeOpen() const {
    return mustBeOpen;
}

void DinningRoomRequirement::setMinTablesCount(int minTablesCount) {
    this->minTablesCount = minTablesCount;
}

void DinningRoomRequirement::setMustBeOpen(bool mustBeOpen) {
    this->mustBeOpen = mustBeOpen;
}

bool DinningRoomRequirement::isDinningRoomSatisfiedBy(int actualArea, bool hasElectricity, bool isAccessible,
                                       int minTablesCount, bool open) const {
    return this->isSatisfiedBy(actualArea, hasElectricity, isAccessible) &&
          this->minTablesCount >= minTablesCount &&
           (!mustBeOpen || open);
}