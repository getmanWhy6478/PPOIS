#include "../include/Delivery.h"
#include "Errors.h"
Delivery::Delivery() = default;

Delivery::Delivery(const Vehicle& vehicle, const Courier& courier)
    : vehicle(vehicle), courier(courier) {}

Vehicle Delivery::getVehicle() const {
    return vehicle;
}

Courier Delivery::getCourier() const {
    return courier;
}
Order Delivery::getOrder() const{
    return order;
}
DeliveryRoute Delivery::getDeliveryRoute() const{
    return route;
}    

void Delivery::setVehicle(const Vehicle& vehicle) {
    this->vehicle = vehicle;
}

void Delivery::setCourier(const Courier& courier) {
    this->courier = courier;
}
void Delivery::setOrder(const Order& order) {
    this->order = order;
}
void Delivery::setDeliveryRoute(const DeliveryRoute& route) {
    this->route = route;
}
void Delivery:: confirmDelivery(){
    order.setIsDelievered(true);
}

int Delivery::getTime(){
    return time;
}
void Delivery::setTime(int time){
    if (time >0)
        this->time = time;
    else
        throw NegativeTimeError();
}