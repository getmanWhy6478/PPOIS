#include "../include/Cook.h"
#include <iostream>
#include "../include/Errors.h"
#include "../include/Restaurant.h"
Cook::Cook()
    : Worker("", 0), active(true) {}

Cook::Cook(const string& name, int salary, bool active)
    : Worker(name, salary), active(active) {}

bool Cook::getActive() const {
    return active;
}

void Cook::setActive(bool activeStatus) {
    active = activeStatus;
}

void Cook::takeProducts(const Product& product, int amount, Restaurant restaurant) {
    if (!(restaurant.findCook(*this))) {
        throw UnempolymentError();
    };
    for (auto i : restaurant.getWarehouse().stored){
        if (i.getProduct() == product){
            i.setAmount(i.getAmount() - amount);
            break;
        }
    }
}

void Cook::Cooking(OrderPosition& orderPosition) {
    if (!active) {
        throw CookBusyError();
    }
    orderPosition.setDone(true);
}
