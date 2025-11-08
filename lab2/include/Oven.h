#pragma once
#include <string>
#include "KitchenAppliance.h"
using namespace std;
class Oven : public KitchenAppliance {
private:
    int maxTemperature;

public:
    Oven(const string& name, bool isElectric, int maxTemperature, bool isAvailable = true);

    int getMaxTemperature() const;
    void setMaxTemperature(int temp);
};
