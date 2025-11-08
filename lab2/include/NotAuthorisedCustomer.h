#pragma once
#include <vector>
#include "Order.h"
#include "Restaurant.h"
using namespace std;

class NotAuthorisedCustomer {
public:
    NotAuthorisedCustomer();
    NotAuthorisedCustomer(const Order& order, int cash);

    void orderSomething(Restaurant& restaurant);
    void addToOrder(OrderPosition orderPosition);

    Order getOrder() const;
    void setOrder(const Order& orders);

    int getCash() const;
    void setCash(int cash);

private:
    Order order;
    int cash;
};
