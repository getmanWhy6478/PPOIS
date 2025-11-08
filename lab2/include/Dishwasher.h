#pragma once
#include <string>
#include "KitchenAppliance.h"
using namespace std;
class Dishwasher : public KitchenAppliance {
private:
    int programCount;

public:
    Dishwasher(const string& name, bool isElectric, int programCount, bool isAvailable = true);

    int getProgramCount() const;
    void setProgramCount(int count);
};
