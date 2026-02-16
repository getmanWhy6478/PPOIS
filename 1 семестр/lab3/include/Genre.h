#pragma once

#include <string>
#include <vector>
#include "Artwork.h"

class Genre {
private:
    std::string name;
    std::string description;
    std::vector<Artwork*> artworks;
    std::string characteristics;

public:
    Genre() = default;
    Genre(const std::string& name);
    ~Genre() = default;
    
    std::string getName() const;
    void setName(const std::string& name);
    std::string getDescription() const;
    void setDescription(const std::string& description);
    void addArtwork(Artwork* artwork);
    std::vector<Artwork*> getArtworks() const;
    std::string getCharacteristics() const;
    void setCharacteristics(const std::string& characteristics);
};

