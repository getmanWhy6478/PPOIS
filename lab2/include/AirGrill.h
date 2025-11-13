#pragma once
#include <string>
#include "KitchenAppliance.h"
using namespace std;
class AirGrill : public KitchenAppliance {
public:
    AirGrill();
    AirGrill(const string& name, bool isElectric, int volumeLiters, bool isAvailable = true);

    int getVolumeLiters() const;
    void setVolumeLiters(int volume);
private:
    int volumeLiters;
};
