#include "../include/Provenance.h"
#include "../include/Artwork.h"
#include "../include/Collector.h"

Provenance::Provenance(Artwork* artwork)
    : artwork(artwork), acquisitionYear(0), acquisitionPrice(0.0) {
}

Artwork* Provenance::getArtwork() const {
    return artwork;
}

void Provenance::setArtwork(Artwork* artwork) {
    this->artwork = artwork;
}

void Provenance::addPreviousOwner(Collector* owner, int year) {
    previousOwners.push_back(owner);
    ownershipYears.push_back(year);
}

std::vector<Collector*> Provenance::getPreviousOwners() const {
    return previousOwners;
}

std::vector<int> Provenance::getOwnershipYears() const {
    return ownershipYears;
}

int Provenance::getAcquisitionYear() const {
    return acquisitionYear;
}

void Provenance::setAcquisitionYear(int year) {
    this->acquisitionYear = year;
}

double Provenance::getAcquisitionPrice() const {
    return acquisitionPrice;
}

void Provenance::setAcquisitionPrice(double price) {
    this->acquisitionPrice = price;
}

std::string Provenance::getCurrentOwner() const {
    return currentOwner;
}

void Provenance::setCurrentOwner(const std::string& owner) {
    this->currentOwner = owner;
}


