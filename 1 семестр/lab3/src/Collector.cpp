#include "../include/Collector.h"
#include "../include/Collection.h"
#include "../include/Artwork.h"
#include <algorithm>

Collector::Collector(const std::string& firstName, const std::string& lastName)
    : firstName(firstName), lastName(lastName) {
}

std::string Collector::getFirstName() const {
    return firstName;
}

void Collector::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

std::string Collector::getLastName() const {
    return lastName;
}

void Collector::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

std::string Collector::getFullName() const {
    return firstName + " " + lastName;
}


void Collector::addCollection(Collection* collection) {
    collections.push_back(collection);
}

std::vector<Collection*> Collector::getCollections() const {
    return collections;
}
bool Collector::purchaseArtwork(Artwork* artwork, Collection* targetCollection,
                                double purchasePrice) {
    if (!artwork || !targetCollection || purchasePrice <= 0.0) {
        return false;
    }

    auto it = std::find(collections.begin(), collections.end(), targetCollection);
    if (it == collections.end()) {
        return false;
    }

    artwork->setEstimatedValue(purchasePrice);
    targetCollection->addArtwork(artwork);
    return true;
}

