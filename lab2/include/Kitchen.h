#pragma once
#include <string>
#include <vector>
#include "Place.h"
#include "KitchenRequirement.h"
#include "KitchenAppliance.h"

class Kitchen : public Place {
public:
    Kitchen();
    Kitchen(int area, int cooksNeeded, bool hasNeededAppliance = false, bool isActive = true);

    KitchenRequirement getRequierement() const;
    void setRequierement(KitchenRequirement requirement);

    int getCooksAmount() const;
    void setCooksAmount(int amount);


    vector <KitchenAppliance> getAppliance() const;
    void setAppliance (vector <KitchenAppliance> applience);


private:
    int cooksAmount;
    KitchenRequirement requirement;
    vector <KitchenAppliance> applience;
};

