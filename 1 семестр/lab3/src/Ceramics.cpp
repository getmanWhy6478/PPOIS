#include "../include/Ceramics.h"
#include "../include/Artist.h"

Ceramics::Ceramics(const std::string& title, int year, Artist* artist)
    : Artwork(title, year, artist) {
}

std::string Ceramics::getClayType() const {
    return clayType;
}

void Ceramics::setClayType(const std::string& type) {
    this->clayType = type;
}

std::string Ceramics::getFiringTechnique() const {
    return firingTechnique;
}

void Ceramics::setFiringTechnique(const std::string& technique) {
    this->firingTechnique = technique;
}

std::string Ceramics::getGlazeType() const {
    return glazeType;
}

void Ceramics::setGlazeType(const std::string& type) {
    this->glazeType = type;
}


