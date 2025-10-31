#pragma once
#include <string>
#include "Place.h"
#include "KitchenRequirement.h"

class Kitchen : public Place {
public:
    Kitchen();
    Kitchen(int area, int cooksNeeded, bool hasNeededAppliance = false, bool isActive = true);

    KitchenRequirement getRequierement() const;
    void setRequierement(KitchenRequirement requirement);

    int getCooksAmount() const;
    void setCooksAmount(int amount);

    bool getHaveAppliance() const;
    void setHaveAppliance(bool haveAppliance);

private:
    int cooksAmount;
    KitchenRequirement requirement;
    bool haveAppliance;
};

