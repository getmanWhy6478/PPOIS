#include "../include/Scooter.h"
Scooter::Scooter() : Vehicle("", 0), batteryLevel(100.0) {}

Scooter::Scooter(const string& model, int capacity, double batteryLevel)
    : Vehicle( model, capacity), batteryLevel(batteryLevel) {}

double Scooter::getBatteryLevel() const {
    return batteryLevel;
}

void Scooter::setBatteryLevel(double level) {
    batteryLevel = level;
}

void Scooter::shortDistance(DeliveryRoute& deliveryRoute){
    deliveryRoute.setTotalDistance(deliveryRoute.getTotalDistance() / 2);
}