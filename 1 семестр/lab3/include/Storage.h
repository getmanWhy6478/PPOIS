#pragma once

#include <string>
#include <vector>
#include "Artwork.h"

class Storage {
private:
    std::string location;
    std::string storageType;
    std::string securityLevel;
    int capacity;
    std::vector<Artwork*> artworks;


public:
    Storage() = default;
    Storage(const std::string& location, const std::string& storageType);
    ~Storage() = default;
    
    std::string getLocation() const;
    void setLocation(const std::string& location);
    std::string getStorageType() const;
    void setStorageType(const std::string& type);
    std::string getSecurityLevel() const;
    void setSecurityLevel(const std::string& level);
    int getCapacity() const;
    void setCapacity(int capacity);
    void addArtwork(Artwork* artwork);
    void removeArtwork(Artwork* artwork);
    std::vector<Artwork*> getArtworks() const;
    bool isFull() const;
};

