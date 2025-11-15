#pragma once
#include <string>
#include "KitchenAppliance.h"
#include "Eatable.h"
using namespace std;
class Fridge: public KitchenAppliance {
public:
    Fridge();
    Fridge(const string& name, bool isElectric, int capacityLiters, bool isAvailable = true);

    int getCapacityLiters() const;
    void setCapacityLiters(int capacity);

    void cold (Eatable& eat);
private:
    int capacityLiters;
};
