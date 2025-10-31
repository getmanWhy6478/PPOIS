#pragma once
#include "PlaceRequirement.h"

class KitchenRequirement : public PlaceRequirement {
public:
    KitchenRequirement();
    KitchenRequirement(int minArea, bool requiresElectricity, bool mustBeAccessible,
                       int minCooksNeeded, bool needsAppliance);

    int getMinCooksNeeded() const;
    bool getNeedsAppliance() const;

    void setMinCooksNeeded(int cooks);
    void setNeedsAppliance(bool needs);

    bool isKitchenSatisfiedBy(int actualArea, bool hasElectricity, bool isAccessible,
                       int actualCooks, bool hasAppliance) const;

private:
    int minCooksNeeded;
    bool needsAppliance;
};
