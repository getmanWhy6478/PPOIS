#pragma once
#include "User.h"
#include "Order.h"
#include "OrderPosition.h"
class Client : public User{
public:
    void orderSomething(Order order);
    void useBonus(int amount);
    void addToOrder(Order order, OrderPosition orderPosition);
private:
    Order* order_list;
    int bonuses_amount;
    int cash_amount;
};