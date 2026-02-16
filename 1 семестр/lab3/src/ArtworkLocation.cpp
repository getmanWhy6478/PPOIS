#include "../include/ArtworkLocation.h"
#include "../include/Artwork.h"
#include "../include/Room.h"
#include "../include/Storage.h"
#include <ctime>

ArtworkLocation::ArtworkLocation(const std::string& locationId, Artwork* artwork)
    : locationId(locationId), artwork(artwork), currentRoom(nullptr),
      currentStorage(nullptr) {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
}

std::string ArtworkLocation::getLocationId() const {
    return locationId;
}

void ArtworkLocation::setLocationId(const std::string& id) {
    this->locationId = id;
}

Artwork* ArtworkLocation::getArtwork() const {
    return artwork;
}

void ArtworkLocation::setArtwork(Artwork* artwork) {
    this->artwork = artwork;
}

Room* ArtworkLocation::getCurrentRoom() const {
    return currentRoom;
}

void ArtworkLocation::setCurrentRoom(Room* room) {
    this->currentRoom = room;
}

Storage* ArtworkLocation::getCurrentStorage() const {
    return currentStorage;
}

void ArtworkLocation::setCurrentStorage(Storage* storage) {
    this->currentStorage = storage;
}


