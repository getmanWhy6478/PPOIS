#include "../include/PlaceRequirement.h"

PlaceRequirement::PlaceRequirement()
    : minArea(0), requiresElectricity(false), mustBeAccessible(false) {}

PlaceRequirement::PlaceRequirement(int minArea, bool requiresElectricity, bool mustBeAccessible)
    : minArea(minArea), requiresElectricity(requiresElectricity), mustBeAccessible(mustBeAccessible) {}

int PlaceRequirement::getMinArea() const {
    return minArea;
}
bool PlaceRequirement::getRequiresElectricity() const {
    return requiresElectricity;
}
bool PlaceRequirement::getMustBeAccessible() const {
    return mustBeAccessible;
}

void PlaceRequirement::setMinArea(int area) {
    minArea = area;
}
void PlaceRequirement::setRequiresElectricity(bool requiresElectricity) {
    this->requiresElectricity = requiresElectricity;
}
void PlaceRequirement::setMustBeAccessible(bool mustBeAccessible) {
    this->mustBeAccessible = mustBeAccessible;
}
bool PlaceRequirement::isSatisfiedBy(int actualArea, bool hasElectricity, bool isAccessible) const {
    return actualArea >= minArea;
}
