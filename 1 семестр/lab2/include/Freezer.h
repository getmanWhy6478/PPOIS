#pragma once
#include <string>
#include "KitchenAppliance.h"
#include "Eatable.h"
using namespace std;
class Freezer : public KitchenAppliance {
public:
    Freezer();
    Freezer(const string& name, bool isElectric, int minTemperature, bool isAvailable = true);

    int getMinTemperature() const;
    void setMinTemperature(int temp);

    void cold(Eatable& eat);
private:
    int minTemperature;

};
