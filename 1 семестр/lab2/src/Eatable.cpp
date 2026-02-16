#include "../include/Eatable.h"

Eatable::Eatable() : name(""), cost(0), cookingTime(0), exparationTime(time(0) + 7200) {}

Eatable::Eatable(const string& name, double cost, int cookingTime, time_t exparationTime) : name(name), cost(cost), 
cookingTime(cookingTime), exparationTime(exparationTime) {}

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

time_t Eatable::getExparationTime() const{
    return exparationTime;
}
void Eatable::setExparationTime(time_t exparationTime){
    this->exparationTime = exparationTime;
}

bool Eatable::operator==(const Eatable& other){
     return this->getName() == other.getName() &&
           this->getCost() == other.getCost() &&
           this->getTime() == other.getTime();
}
