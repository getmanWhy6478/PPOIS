#include "Cook.h"
#include <iostream>

Cook::Cook()
    : Worker("", 0, nullptr), active(true) {}

Cook::Cook(const std::string& name, int salary, Restaurant* restaurant, bool active)
    : Worker(name, salary, restaurant), active(active) {}

bool Cook::getActive() const {
    return active;
}

void Cook::setActive(bool activeStatus) {
    active = activeStatus;
}

void Cook::takeProducts(const Product& product, int amount) {
    if (!restaurant) {
        throw std::runtime_error("Cook is not assigned to any restaurant.");
    }
    Restaurant res = *(this->getRestaurant());
    Warehouse ware = res.getWarehouse();
    for (auto i : ware.stored){
        if (i.getProduct() == product){
            i.setAmount(i.getAmount() - amount);
            break;
        }
    }
    else

}

void Cook::Cooking(OrderPosition& orderPosition) {
    if (!active) {
        throw std::runtime_error("Cook is inactive and cannot cook.");
    }
    orderPosition.setDone(true);
}
