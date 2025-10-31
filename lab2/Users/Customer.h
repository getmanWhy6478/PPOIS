#pragma once
#include "User.h"
#include "Order.h"
#include "OrderPosition.h"
#include "Courier.h"
#include "Rating.h"
#include "Complaint.h"
#include "Restaurant.h"
#include "ComplaintBook.h"

class Customer : public User {
public:
    Customer();
    Customer(const string& name, int age, const string& email, int cash, int bonusesAmount = 0);
    
    void orderSomething(Restaurant& restaurant);
    void useBonus(int amount);
    void addToOrder(OrderPosition orderPosition);
    void leaveRating(Courier* courier, Rating rating);
    void leaveComplaint(ComplaintBook* complaintBook, Complaint complaint);

    Order getOrder() const;
    int getBonusesAmount() const;
    int getCash() const;

    void setOrder(const Order& order);
    void setBonusesAmount(int amount);
    void setCash(int amount);

private:
    Order order;
    int bonusesAmount;
    int cash;
};
