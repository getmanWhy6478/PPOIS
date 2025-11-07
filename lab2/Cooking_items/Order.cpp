#include "Order.h"
#include <typeinfo>
int Order::getCost() {
    int total = 0;
    for (const auto& item : eatList) {
        total += item.eat->getCost();
    }
    return total;
}

int Order::getTime() {
    int total = 0;
    for (const auto& item : eatList) {
        total += item.eat->getTime();
    }
    return total;
}

int Order::getBonuses() {
    return this->getTime() * 0.25;
}
int Order::getID() {
    return id;
}
vector<OrderPosition> Order::getEatList() {
    return eatList;
}

string Order::getAdress() {
    return adress;
}

bool Order::isDone() {
    return done;
}

bool Order::isDelievered() {
    return delievered;
}

void Order::setEatList(vector<OrderPosition> eatList) {
    this->eatList = eatList;
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
