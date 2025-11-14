#pragma once
#include "Vehicle.h"
#include "DeliveryRoute.h"
using namespace std;
class Scooter : public Vehicle {

public:
    Scooter();
    Scooter(const string& model, int capacity, double batteryLevel);

    double getBatteryLevel() const;
    void setBatteryLevel(double level);

    void shortDistance(DeliveryRoute& deliveryRoute);
private:
    double batteryLevel;
};
