#include "../include/NotAuthorisedCustomer.h"

NotAuthorisedCustomer::NotAuthorisedCustomer()
    :order(), cash(0) {}

NotAuthorisedCustomer::NotAuthorisedCustomer(const Order& order, int cash)
    : order(order), cash(cash) {}

void NotAuthorisedCustomer::orderSomething(Restaurant& restaurant) {
    restaurant.orders.push_back(this->order);
}

void NotAuthorisedCustomer::addToOrder(OrderPosition orderPosition) {
    order.eatList.push_back(orderPosition); // добавить оплату
}


Order NotAuthorisedCustomer::getOrder() const {
    return order;
}

int NotAuthorisedCustomer::getCash() const {
    return cash;
}

void NotAuthorisedCustomer::setOrder(const Order& order) {
    this->order = order;
}

void NotAuthorisedCustomer::setCash(int amount) {
    cash = (amount >= 0) ? amount : 0;
}