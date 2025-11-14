#include "../include/OrderPosition.h"

OrderPosition::OrderPosition()
    : eat(), amount(0), done(false) {}

OrderPosition::OrderPosition(Eatable& eatable, int amount)
    : eat(eatable), amount(amount), done(false) {}

Eatable OrderPosition::getEatable() {
    return eat;
}

void OrderPosition::setEatable(Eatable& eatable) {
    eat = eatable;
}

int OrderPosition::getAmount() const {
    return amount;
}

void OrderPosition::setAmount(int amount) {
    this->amount = amount;
}
bool OrderPosition::isDone() const {
    return done;
}
void OrderPosition::setDone(bool done){
    this->done = done;
}
