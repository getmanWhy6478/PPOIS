#pragma once
#include <string>
#include "KitchenAppliance.h"
using namespace std;
class Freezer : public KitchenAppliance {
public:
    Freezer(const string& name, bool isElectric, int minTemperature, bool isAvailable = true);

    int getMinTemperature() const;
    void setMinTemperature(int temp);
private:
    int minTemperature;

};
