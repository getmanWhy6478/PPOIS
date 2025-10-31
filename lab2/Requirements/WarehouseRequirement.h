#pragma once
#include "PlaceRequirement.h"

class WarehouseRequirement : public PlaceRequirement {
public:
    WarehouseRequirement();
    WarehouseRequirement(int minArea, bool requiresElectricity, bool mustBeAccessible,
                         double minCapacity, bool requiresCooling);

    double getMinCapacity() const;
    bool getRequiresCooling() const;

    void setMinCapacity(int requiredCapacity);
    void setRequiresCooling(bool cooling);

    bool isWarehouseSatisfiedBy(int actualArea, bool hasElectricity, bool isAccessible,
                       double actualVolume, bool hasCooling) const;

private:
    int minCapacity;
    bool requiresCooling;
};
