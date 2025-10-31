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

    Order getOrder() const;
    void setOrder(const Order orders);

    int getCash();
    void setCash(int cash);

private:
    Order order;
    int cash;
};
