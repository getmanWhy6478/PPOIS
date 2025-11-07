#include "Eatable.h"

Eatable::Eatable() : name(""), cost(0) {}

Eatable::Eatable(const string& name, double cost, int cookingTime) : name(name), cost(cost), cookingTime(cookingTime) {}

Eatable::Eatable(const Eatable& other)
    : name(other.name), cost(other.cost) {}

double Eatable::getCost () const{
    return cost;
}

void Eatable::setCost(double cost) {
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

bool Eatable::operator==(const Eatable& other){
     return this->getName() == other.getName() &&
           this->getCost() == other.getCost() &&
           this->getTime() == other.getTime();
}
Eatable::~Eatable() {};
