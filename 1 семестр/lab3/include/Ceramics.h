#pragma once

#include "Artwork.h"
#include <string>

class Ceramics : public Artwork {
private:
    std::string clayType;
    std::string firingTechnique;
    std::string glazeType;

public:
    Ceramics() = default;
    Ceramics(const std::string& title, int year, Artist* artist);
    ~Ceramics() = default;
    
    std::string getClayType() const;
    void setClayType(const std::string& type);
    std::string getFiringTechnique() const;
    void setFiringTechnique(const std::string& technique);
    std::string getGlazeType() const;
    void setGlazeType(const std::string& type);
};

