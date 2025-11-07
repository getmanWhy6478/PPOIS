#pragma once
#include "Vehicle.h"
#include "Courier.h"
#include "Order.h"
#include "DeliveryRoute.h"

class Delivery {
public:
    Delivery(const Vehicle& vehicle, const Courier& courier);

    Vehicle getVehicle() const;
    Courier getCourier() const;
    Order getOrder() const;
    DeliveryRoute getDeliveryRoute() const;

    void setVehicle(const Vehicle& vehicle);
    void setCourier(const Courier& courier);
    void setOrder(const Order& order);
    void setDeliveryRoute(const DeliveryRoute& route);

    void confirmDelivery();

private:
    Vehicle vehicle;
    Courier courier;
    Order order;
    DeliveryRoute route;
};

