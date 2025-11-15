#pragma once
#include "NotAuthorisedCustomer.h"
#include "User.h"
#include "Order.h"
#include "OrderPosition.h"
#include "Courier.h"
#include "Rating.h"
#include "Complaint.h"
#include "Restaurant.h"
#include "ComplaintBook.h"
#include "Bonus.h"
#include "LoyaltyProgram.h"
class Restaurant;
class Customer : public User, public NotAuthorisedCustomer {
public:
    Customer();
    Customer(const string& name, int age, const string& email, int cash, Order order);
    void useBonus(Bonus bonus);
    void leaveRating(Restaurant& restaurant, Rating rating);
    void leaveComplaint(ComplaintBook& complaintBook, Complaint complaint);
    bool findBonus(Bonus bonus);
    void useLoyaltyProgram(LoyaltyProgram& program);


    vector<Bonus> getBonuses() const;
    void addBonus(Bonus bonus);
    void clearBonuses();
    
private:
    vector<Bonus> bonuses;
    int loyaltypoints;
};
