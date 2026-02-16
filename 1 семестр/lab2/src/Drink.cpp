#include "../include/Drink.h"

Drink::Drink() : Eatable(), eighteenPlus(false) {}

Drink::Drink(const string& name, int cost, int calories)
    : Eatable(name, cost, 0, time(0) + 999999999), calories(calories), eighteenPlus(false) {}

bool Drink::isEighteenPlus() const{
    return eighteenPlus;
}
int Drink::getCalories() const{
    return calories;
}

void Drink::setCalories(int calories) {
    this->calories = calories;
}
void Drink::setIsEighteenPlus(bool eighteenPlus) {
    this->eighteenPlus = eighteenPlus;
}
