#include "../include/AirGrill.h"
AirGrill::AirGrill(const string& name, bool isElectric, int volumeLiters, bool isAvailable)
    : KitchenAppliance(name, isElectric, isAvailable), volumeLiters(volumeLiters) {}

int AirGrill::getVolumeLiters() const {
    return volumeLiters;
}

void AirGrill::setVolumeLiters(int volume) {
    volumeLiters = volume;
}
