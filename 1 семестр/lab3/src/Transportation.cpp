#include "../include/Transportation.h"
#include "../include/Artwork.h"

Transportation::Transportation(const std::string& shipmentNumber, const std::string& origin,
                   const std::string& destination)
    : shipmentNumber(shipmentNumber), origin(origin), destination(destination),
      cost(0.0), status("scheduled") {
}

std::string Transportation::getShipmentNumber() const {
    return shipmentNumber;
}

void Transportation::setShipmentNumber(const std::string& number) {
    this->shipmentNumber = number;
}

void Transportation::addArtwork(Artwork* artwork) {
    artworks.push_back(artwork);
}

std::vector<Artwork*> Transportation::getArtworks() const {
    return artworks;
}

std::string Transportation::getOrigin() const {
    return origin;
}

void Transportation::setOrigin(const std::string& origin) {
    this->origin = origin;
}

std::string Transportation::getDestination() const {
    return destination;
}

void Transportation::setDestination(const std::string& destination) {
    this->destination = destination;
}

double Transportation::getCost() const {
    return cost;
}

void Transportation::setCost(double cost) {
    this->cost = cost;
}

std::string Transportation::getStatus() const {
    return status;
}

void Transportation::setStatus(const std::string& status) {
    this->status = status;
}

