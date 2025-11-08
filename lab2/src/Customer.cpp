#include "../include/Customer.h"
#include "../include/Errors.h"
#include "../include/Payment.h"
Customer::Customer()
    : User(), order(), bonusesAmount(0), cash(0) {}

Customer::Customer(const std::string& name, int age, const std::string& email, int cash)
    : User(name, age, email), order(), bonusesAmount(0), cash(cash) {}

void Customer::orderSomething(Restaurant& restaurant) {
    if (!banned){
        Payment payment(order.getCost(), "byCArd", "BYN");
        if (cash < payment.getAmount()){
            restaurant.orders.push_back(this->order);
            cash -= payment.getAmount();
            payment.confirm();
        }
        else{
            throw InsufficientFundsError();
        }    
    }
    else{
        throw BannedUserError();
    }
}

void Customer::useBonus(int amount) {
    if (!banned)
        if (amount <= bonusesAmount) {
        bonusesAmount -= amount;
        cash += amount*0.5;
        }
    else{
        throw BannedUserError();
    }
}

void Customer::addToOrder(OrderPosition orderPosition) {
    if (!banned)
        order.eatList.push_back(orderPosition); // добавить оплату
    else{
        throw BannedUserError();
    }
}

void Customer::leaveRating(Restaurant& restaurant, Rating rating) {
    if (!banned)
        restaurant.ratings.push_back(rating);
    else{
        throw BannedUserError();
    }
}

void Customer::leaveComplaint(ComplaintBook& complaintBook, Complaint complaint) {
    if (!banned)
            complaintBook.complaints.push_back(complaint);
    else{
        throw BannedUserError();
    }
}

Order Customer::getOrder() const {
    return order;
}

int Customer::getBonusesAmount() const {
    return bonusesAmount;
}

int Customer::getCash() const {
    return cash;
}

void Customer::setOrder(const Order& order) {
    this->order = order;
}

void Customer::setBonusesAmount(int amount) {
    bonusesAmount = (amount >= 0) ? amount : 0;
}

void Customer::setCash(int amount) {
    cash = (amount >= 0) ? amount : 0;
}
