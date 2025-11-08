#pragma once
#include <string>
#include "KitchenAppliance.h"
using namespace std;
class Fridge: public KitchenAppliance {
private:
    int capacityLiters;

public:
    Fridge(const string& name, bool isElectric, int capacityLiters, bool isAvailable = true);

    int getCapacityLiters() const;
    void setCapacityLiters(int capacity);
};
