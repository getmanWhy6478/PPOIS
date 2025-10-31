#include "OrderPosition.h"

OrderPosition::OrderPosition()
    : eat(nullptr), amount(0) {}

// Конструктор с параметрами
OrderPosition::OrderPosition(Eatable* eatable, int amount)
    : eat(eatable), amount(amount) {}

Eatable OrderPosition::getEatable() {
    return *eat;
}

void OrderPosition::setEatable(Eatable& eatable) {
    eat = &eatable;
}

int OrderPosition::getAmount() const {
    return amount;
}

void OrderPosition::setAmount(int amount) {
    this->amount = amount;
}

