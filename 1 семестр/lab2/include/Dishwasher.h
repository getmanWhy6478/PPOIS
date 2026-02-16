#pragma once
#include <string>
#include "KitchenAppliance.h"
using namespace std;
class Dishwasher : public KitchenAppliance {

public:
    Dishwasher();
    Dishwasher(const string& name, bool isElectric, int programCount, bool isAvailable = true);
    
    int getProgramCount() const;
    void setProgramCount(int count);
private:
    int programCount;
};
