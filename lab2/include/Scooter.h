#pragma once
#include "Vehicle.h"
using namespace std;
class Scooter : public Vehicle {

public:
    Scooter();
    Scooter(const string& model, int capacity, double batteryLevel);

    double getBatteryLevel() const;
    void setBatteryLevel(double level);
private:
    double batteryLevel;
};
