#include "../include/Genre.h"
#include "../include/Artwork.h"

Genre::Genre(const std::string& name)
    : name(name) {
}

std::string Genre::getName() const {
    return name;
}

void Genre::setName(const std::string& name) {
    this->name = name;
}

std::string Genre::getDescription() const {
    return description;
}

void Genre::setDescription(const std::string& description) {
    this->description = description;
}

void Genre::addArtwork(Artwork* artwork) {
    artworks.push_back(artwork);
}

std::vector<Artwork*> Genre::getArtworks() const {
    return artworks;
}

std::string Genre::getCharacteristics() const {
    return characteristics;
}

void Genre::setCharacteristics(const std::string& characteristics) {
    this->characteristics = characteristics;
}


