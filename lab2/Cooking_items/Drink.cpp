#include "Drink.h"

Drink::Drink() : Eatable(), eighteenPlus(false) {}

Drink::Drink(const string& name, int cost, int calories)
    : Eatable(name, cost, calories), eighteenPlus(false) {}

Drink::Drink(const Drink& other)
    : Eatable(other), eighteenPlus(other.eighteenPlus) {}

bool Drink::isEighteenPlus() {
    return eighteenPlus;
}

void Drink::setIsEighteenPlus(bool eighteenPlus) {
    this->eighteenPlus = eighteenPlus;
}
