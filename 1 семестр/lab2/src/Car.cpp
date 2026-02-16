#include "../include/Car.h"

Car::Car() : Vehicle("", 0), seatCount(4) {}

Car::Car(const string& model, int capacity, int seatCount)
    : Vehicle(model, capacity), seatCount(seatCount) {}

int Car::getSeatCount() const {
    return seatCount;
}

void Car::setSeatCount(int count) {
    seatCount = count;
}
void Car::farAway(Delivery& delivery){
    if(delivery.getDeliveryRoute().getTotalDistance() > 150){
        delivery.setTime(delivery.getTime() / 2);
    }
}