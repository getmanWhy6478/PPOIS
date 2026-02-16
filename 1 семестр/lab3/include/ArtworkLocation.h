#pragma once

#include <string>
#include "Artwork.h"
#include "Room.h"
#include "Storage.h"

class ArtworkLocation {
private:
    std::string locationId;
    Artwork* artwork;
    Room* currentRoom;
    Storage* currentStorage;

public:
    ArtworkLocation() = default;
    ArtworkLocation(const std::string& locationId, Artwork* artwork);
    ~ArtworkLocation() = default;
    
    std::string getLocationId() const;
    void setLocationId(const std::string& id);
    Artwork* getArtwork() const;
    void setArtwork(Artwork* artwork);
    Room* getCurrentRoom() const;
    void setCurrentRoom(Room* room);
    Storage* getCurrentStorage() const;
    void setCurrentStorage(Storage* storage);
};

