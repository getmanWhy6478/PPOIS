#pragma once
#include "Vehicle.h"
using namespace std;
class Scooter : public Vehicle {
private:
    double batteryLevel;

public:
    Scooter();
    Scooter(const string& model, int capacity, double batteryLevel);

    double getBatteryLevel() const;
    void setBatteryLevel(double level);
};
