#include "Eatable.h"

Eatable::Eatable() : name(""), cost(0), calories(0) {}

Eatable::Eatable(const string& name, int cost, int calories) : name(name), cost(cost), calories(0) {}

Eatable::Eatable(const Eatable& other)
    : name(other.name), cost(other.cost), calories(other.calories) {}

int Eatable::getCost() {
    return cost;
}

void Eatable::setCost(int cost) {
    this->cost = cost;
}

string Eatable::getName() {
    return name;
}

void Eatable::setName(const string& name) {
    this->name = name;
}

int Eatable::getCalories() {
    return calories;
}

void Eatable::setCalories(int calories) {
    this->calories = calories;
}