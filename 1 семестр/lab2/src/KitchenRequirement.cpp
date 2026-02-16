#include "../include/KitchenRequirement.h"

KitchenRequirement::KitchenRequirement()
    : PlaceRequirement(), minCooksNeeded(0), needsAppliance(false) {}

KitchenRequirement::KitchenRequirement(int minArea, bool requiresElectricity, bool mustBeAccessible,
                                       int minCooksNeeded, bool needsAppliance)
    : PlaceRequirement(minArea, requiresElectricity, mustBeAccessible),
      minCooksNeeded(minCooksNeeded), needsAppliance(needsAppliance) {}


int KitchenRequirement::getMinCooksNeeded() const {
    return minCooksNeeded;
}

bool KitchenRequirement::getNeedsAppliance() const {
    return needsAppliance;
}

void KitchenRequirement::setMinCooksNeeded(int cooks) {
    minCooksNeeded = cooks;
}

void KitchenRequirement::setNeedsAppliance(bool needs) {
    needsAppliance = needs;
}

bool KitchenRequirement::isKitchenSatisfiedBy(int actualArea, bool hasElectricity, bool isAccessible,
                                       int actualCooks, bool hasAppliance) const {
    return this->isSatisfiedBy(actualArea, hasElectricity, isAccessible) &&
           actualCooks >= minCooksNeeded &&
           (!needsAppliance || hasAppliance);
}
