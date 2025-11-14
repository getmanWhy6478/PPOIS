#include "../include/Order.h"
Order::Order()
        : eatList{}, adress{}, done(false), delievered(false), id(0) {}

Order::Order(const vector<OrderPosition>& eatList, const string& adress, bool done,
          bool delievered, int id)
        : eatList(eatList),
          adress(adress),
          done(done),
          delievered(delievered),
          id(id) {}
double Order::getCost() const{
    double total = 0;
    for (const auto& item : eatList) {
        total += item.eat.getCost();
    }
    return total;
}

int Order::getTime() const{
    int total = 0;
    for (const auto& item : eatList) {
        total += item.eat.getTime();
    }
    return total;
}

int Order::getBonuses() const{
    return this->getTime() * 0.25;
}
int Order::getID() const{
    return id;
}
vector<OrderPosition> Order::getEatList() const{
    return eatList;
}

string Order::getAdress() const{
    return adress;
}

bool Order::isDone() const{
    return done;
}

bool Order::isDelievered() const{
    return delievered;
}

void Order::addEat(OrderPosition eat) {
    eatList.push_back(eat);
}

void Order::setAdress(const string& adress) {
    this->adress = adress;
}

void Order::setIsDone(bool done) {
    this->done = done;
}

void Order::setIsDelievered(bool delievered) {
    this->delievered = delievered;
}
void Order::setID(int id) {
    this->id = id;
}
