#include "../include/Stove.h"

Stove::Stove()
    : KitchenAppliance("", true, false), burnerCount(0){}
Stove::Stove(const string& name, bool isElectric, int burnerCount, bool isAvailable)
    : KitchenAppliance(name, isElectric, isAvailable), burnerCount(burnerCount) {}

int Stove::getBurnerCount() const {
    return burnerCount;
}

void Stove::setBurnerCount(int count) {
    burnerCount = count;
}
void Stove::fastFire(Eatable& eat){
    eat.setTime(eat.getTime() / 2);
}