#pragma once

#include <string>
#include <vector>
#include "Artist.h"

class ArtMovement {
private:
    std::string name;
    std::string description;
    int startYear;
    int endYear;
    std::vector<Artist*> artists;

public:
    ArtMovement(const std::string& name, int startYear);
    ~ArtMovement() = default;
    
    std::string getName() const;
    void setName(const std::string& name);
    std::string getDescription() const;
    void setDescription(const std::string& description);
    int getStartYear() const;
    void setStartYear(int year);
    int getEndYear() const;
    void setEndYear(int year);
    void addArtist(Artist* artist);
    std::vector<Artist*> getArtists() const;
};

