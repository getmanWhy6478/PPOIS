#pragma once
#include <string>
#include "KitchenAppliance.h"
#include "Eatable.h"
using namespace std;
class Stove : public KitchenAppliance {
public:
    Stove();
    Stove(const string& name, bool isElectric, int burnerCount, bool isAvailable = true);

    int getBurnerCount() const;
    void setBurnerCount(int count);

    void fastFire(Eatable& eat);
private:
    int burnerCount;
};
