#pragma once
#include "PlaceRequirement.h"

class DinningRoomRequirement : public PlaceRequirement {
public:
    DinningRoomRequirement();
    DinningRoomRequirement(int minArea, bool requiresElectricity, bool mustBeAccessible,
                       int minCooksNeeded, bool needsAppliance);

    int getMinTablesCount() const;
    void setMinTablesCount(int minTablesCount);
    
    bool getMustBeOpen() const;
    void setMustBeOpen(bool mustBeOpen);

    bool isDinningRoomSatisfiedBy(int actualArea, bool hasElectricity, bool isAccessible,
                       int minTablesCount, bool mustBeOpen) const;

private:
    int minTablesCount;
    bool mustBeOpen;
};