#pragma once
#include "Vehicle.h"
#include "Courier.h"
#include "Order.h"
#include "DeliveryRoute.h"
#include "DeliveryStatus.h"

class Delivery {
public:
    Delivery();
    Delivery(const Vehicle& vehicle, const Courier& courier);

    Vehicle getVehicle() const;
    void setVehicle(const Vehicle& vehicle);

    Courier getCourier() const;
    void setCourier(const Courier& courier);

    Order getOrder() const;
    void setOrder(const Order& order);
    
    DeliveryRoute getDeliveryRoute() const;
    void setDeliveryRoute(const DeliveryRoute& route);

    int getTime();
    void setTime(int time);

    void confirmDelivery();

private:
    Vehicle vehicle;
    Courier courier;
    Order order;
    DeliveryRoute route;
    DeliveryStatus status;
    int time;
};

