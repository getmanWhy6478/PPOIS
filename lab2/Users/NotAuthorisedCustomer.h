#pragma once
#include "User.h"
#include "Order.h"
#include "OrderPosition.h"
#include "Courier.h"
#include "Review.h"
class NotAuthorisedCustomer{
public:
    void orderSomething(Order order);
private:
    Order* orderList;
};