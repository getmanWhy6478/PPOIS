#include "PlaceRequirement.h"

PlaceRequirement::PlaceRequirement()
    : minArea(0) {}

PlaceRequirement::PlaceRequirement(int minArea, bool requiresElectricity, bool mustBeAccessible)
    : minArea(minArea) {}

int PlaceRequirement::getMinArea() const {
    return minArea;
}

void PlaceRequirement::setMinArea(int area) {
    minArea = area;
}

bool PlaceRequirement::isSatisfiedBy(int actualArea, bool hasElectricity, bool isAccessible) const {
    return actualArea >= minArea;
}
