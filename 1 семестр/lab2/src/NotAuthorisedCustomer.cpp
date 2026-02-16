#include "../include/NotAuthorisedCustomer.h"
#include "Payment.h"
#include "Errors.h"

NotAuthorisedCustomer::NotAuthorisedCustomer()
    :order(), cash(0) {}

NotAuthorisedCustomer::NotAuthorisedCustomer(const Order& order, int cash)
    : order(order), cash(cash) {}

void NotAuthorisedCustomer::orderSomething(Restaurant& restaurant) {
    Payment payment(order.getCost(), "byCArd", "BYN");
        if (cash > payment.getAmount()){
            restaurant.addOrder(this->order);
            cash -= payment.getAmount();
            payment.confirm();
        }
        else{
            throw InsufficientFundsError();
        } 
}

void NotAuthorisedCustomer::addToOrder(OrderPosition orderPosition) {
    order.addEat(orderPosition);
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