#include "Customer.h"

Customer::Customer()
    : User(), order(), bonusesAmount(0), cash(0) {}

Customer::Customer(const std::string& name, int age, const std::string& email, int cash, int bonusesAmount)
    : User(name, age, email), order(), bonusesAmount(bonusesAmount), cash(cash) {}

void Customer::orderSomething(Restaurant& restaurant) {
    restaurant.orders.push_back(this->order);
}

void Customer::useBonus(int amount) {
    if (amount <= bonusesAmount) {
        bonusesAmount -= amount;
        cash += amount*0.5;
    }
}

void Customer::addToOrder(OrderPosition orderPosition) {
    order.eatList.push_back(orderPosition); // добавить оплату
}

void Customer::leaveRating(Courier* courier, Rating rating) {
    if (courier) {
        courier->ratings.push_back(rating);
    }
}

void Customer::leaveComplaint(ComplaintBook* complaintBook, Complaint complaint) {
    if (complaintBook) {
        complaintBook->complaints.push_back(complaint);
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
