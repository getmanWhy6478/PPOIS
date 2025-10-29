#pragma once
#include "User.h"
#include "Order.h"
#include "OrderPosition.h"
#include "Courier.h"
#include "Rating.h"
#include "Complaint.h"
class Customer : public User{
public:
    void orderSomething(Order order);
    void useBonus(int amount);
    void addToOrder(Order order, OrderPosition orderPosition);
    void leaveReview(Courier* courier, Rating rating);
    void leaveComplaint(Restaurant* restaurant, Complaint complaint);
private:
    Order* orderList;
    int bonusesAmount;
};