#include "../include/Kitchen.h"

Kitchen::Kitchen()
    : Place(), cooksAmount(0), requirement() {}

Kitchen::Kitchen(int area, int cooksNeeded, bool hasNeededAppliance, bool isActive)
    : Place(area), cooksAmount(cooksNeeded), requirement(area, true, isActive, cooksNeeded, hasNeededAppliance) {}

KitchenRequirement Kitchen::getRequierement() const {
    return requirement;
}

void Kitchen::setRequierement(KitchenRequirement requirement) {
    this->requirement = requirement;
}

int Kitchen::getCooksAmount() const {
    return cooksAmount;
}

void Kitchen::setCooksAmount(int amount) {
    this->cooksAmount = amount;
}

vector <KitchenAppliance> Kitchen::getAppliance() const{
    return applience;
}
void Kitchen::setAppliance (vector <KitchenAppliance> applience){
        this->applience = applience;
}