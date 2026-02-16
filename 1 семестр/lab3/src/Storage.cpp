#include "../include/Storage.h"
#include "../include/Artwork.h"

Storage::Storage(const std::string& location, const std::string& storageType)
    : location(location), storageType(storageType), capacity(0) {
}

std::string Storage::getLocation() const {
    return location;
}

void Storage::setLocation(const std::string& location) {
    this->location = location;
}

std::string Storage::getStorageType() const {
    return storageType;
}

void Storage::setStorageType(const std::string& type) {
    this->storageType = type;
}

std::string Storage::getSecurityLevel() const {
    return securityLevel;
}

void Storage::setSecurityLevel(const std::string& level) {
    this->securityLevel = level;
}

int Storage::getCapacity() const {
    return capacity;
}

void Storage::setCapacity(int capacity) {
    this->capacity = capacity;
}

void Storage::addArtwork(Artwork* artwork) {
    artworks.push_back(artwork);
}

void Storage::removeArtwork(Artwork* artwork) {
    for (auto it = artworks.begin(); it != artworks.end(); ++it) {
        if (*it == artwork) {
            artworks.erase(it);
            break;
        }
    }
}

std::vector<Artwork*> Storage::getArtworks() const {
    return artworks;
}

bool Storage::isFull() const {
    if (capacity <= 0) return false;
    return artworks.size() >= static_cast<size_t>(capacity);
}

