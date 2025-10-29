#include "Eatable.h"

Eatable::Eatable() : name(""), cost(0) {}

Eatable::Eatable(const string& name, int cost, int cookingTime) : name(name), cost(cost), cookingTime(cookingTime) {}

Eatable::Eatable(const Eatable& other)
    : name(other.name), cost(other.cost) {}

int Eatable::getCost () const{
    return cost;
}

void Eatable::setCost(int cost) {
    this->cost = cost;
}

string Eatable::getName() const {
    return name;
}

void Eatable::setName(const string& name) {
    this->name = name;
}
int Eatable::getTime() const{
    return cookingTime;
}

void Eatable::setTime(int cookingTime) {
    this->cookingTime = cookingTime;
}