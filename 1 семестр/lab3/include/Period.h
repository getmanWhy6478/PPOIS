#pragma once

#include <string>
#include <vector>
#include "Artwork.h"

class Period {
private:
    std::string name;
    std::string description;
    int startYear;
    int endYear;
    std::vector<Artwork*> artworks;
    std::vector<std::string> keyEvents;

public:
    Period() = default;
    Period(const std::string& name, int startYear, int endYear);
    ~Period() = default;
    
    std::string getName() const;
    void setName(const std::string& name);
    std::string getDescription() const;
    void setDescription(const std::string& description);
    int getStartYear() const;
    void setStartYear(int year);
    int getEndYear() const;
    void setEndYear(int year);
    void addArtwork(Artwork* artwork);
    std::vector<Artwork*> getArtworks() const;
    void addKeyEvent(const std::string& event);
    std::vector<std::string> getKeyEvents() const;
    int getDuration() const;
};

