#pragma once
#include <vector>
#include "Order.h"
#include "Restaurant.h"
using namespace std;

class NotAuthorisedCustomer {
public:
    NotAuthorisedCustomer();
    NotAuthorisedCustomer(const Order& order, int cash);

    void orderSomething(Restaurant& restaurant) ; 

    void addToOrder(OrderPosition orderPosition); 

    Order getOrder() const;
    void setOrder(const Order& order);

    int getCash() const;
    void setCash(int amount);
protected:
    Order order;
    int cash;
};
