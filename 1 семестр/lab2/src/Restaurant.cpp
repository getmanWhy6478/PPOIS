#include "../include/Restaurant.h"
#include <algorithm>
Restaurant::Restaurant() = default;

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
Menu Restaurant::getMenu() const {
    return menu;
}
vector<Rating> Restaurant::getRatings() const {
    return ratings;
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

void Restaurant::addCook(Cook cook) {
    cooks.push_back(cook);
}

void Restaurant::addCourier(Courier courier) {
    couriers.push_back(courier);
}
void Restaurant::addOrder(Order order) {
    orders.push_back(order);
}

void Restaurant::addRating(Rating rating) {
    ratings.push_back(rating);
}
void Restaurant::setMenu(const Menu& menu) {
    this->menu = menu;
}
bool Restaurant::findCook(Cook cook) const {
    return find(cooks.begin(), cooks.end(), cook) != cooks.end();
}
bool Restaurant::findCourier(Courier courier) const {
    return find(couriers.begin(), couriers.end(), courier) != couriers.end();
}
