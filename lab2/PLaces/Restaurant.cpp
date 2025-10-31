#include "Restaurant.h"

Restaurant::Restaurant()
    : adress(), manager(), dinningRoom(), warehouse(), kitchen(), cooks(), couriers() {}

Restaurant::Restaurant(const Adress& adress, const Manager& manager,
                       const DinningRoom& dinningRoom, const Warehouse& warehouse, const Kitchen& kitchen)
    : adress(adress), manager(manager), dinningRoom(dinningRoom),
      warehouse(warehouse), kitchen(kitchen), cooks(), couriers() {}

Adress Restaurant::getAdress() const {
    return adress;
}

Manager Restaurant::getManager() const {
    return manager;
}

DinningRoom Restaurant::getDinningRoom() const {
    return dinningRoom;
}

Warehouse Restaurant::getWarehouse() const {
    return warehouse;
}

Kitchen Restaurant::getKitchen() const {
    return kitchen;
}

vector<Cook> Restaurant::getCooks() const {
    return cooks;
}

vector<Courier> Restaurant::getCouriers() const {
    return couriers;
}

vector<Order> Restaurant::getOrders() const {
    return orders;
}

void Restaurant::setAdress(const Adress& adress) {
    this->adress = adress;
}

void Restaurant::setManager(const Manager& manager) {
    this->manager = manager;
}

void Restaurant::setDinningRoom(const DinningRoom& dinningRoom) {
    this->dinningRoom = dinningRoom;
}

void Restaurant::setWarehouse(const Warehouse& warehouse) {
    this->warehouse = warehouse;
}

void Restaurant::setKitchen(const Kitchen& kitchen) {
    this->kitchen = kitchen;
}

void Restaurant::setCooks(const vector<Cook>& cooks) {
    this->cooks = cooks;
}

void Restaurant::setCouriers(const vector<Courier>& couriers) {
    this->couriers = couriers;
}
void Restaurant::setOrders(const vector<Order>& orders) {
    this->orders = orders;
}
