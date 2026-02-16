#pragma once

#include <string>
#include <vector>
#include "Artwork.h"

class Room {
private:
    std::string name;
    std::string number;
    double area;
    double height;
    int maxCapacity;
    std::vector<Artwork*> artworks;

public:
    Room() = default;
    Room(const std::string& name, const std::string& number, double area);
    ~Room() = default;
    
    std::string getName() const;
    void setName(const std::string& name);
    std::string getNumber() const;
    void setNumber(const std::string& number);
    double getArea() const;
    void setArea(double area);
    double getHeight() const;
    void setHeight(double height);
    int getMaxCapacity() const;
    void setMaxCapacity(int capacity);
    void addArtwork(Artwork* artwork);
    void removeArtwork(Artwork* artwork);
    std::vector<Artwork*> getArtworks() const;
};

