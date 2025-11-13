#include "../include/Dishwasher.h"

Dishwasher::Dishwasher()
    : KitchenAppliance("", true, false), programCount(0) {}

Dishwasher::Dishwasher(const string& name, bool isElectric, int programCount, bool isAvailable)
    : KitchenAppliance(name, isElectric, isAvailable), programCount(programCount) {}

int Dishwasher::getProgramCount() const {
    return programCount;
}

void Dishwasher::setProgramCount(int count) {
    programCount = count;
}
