#pragma once

#include "Artwork.h"
#include <string>

class Textile : public Artwork {
private:
    std::string textileType;
    bool isHandmade;

public:
    Textile() = default;
    Textile(const std::string& title, int year, Artist* artist);
    ~Textile() = default;
    
    std::string getTextileType() const;
    void setTextileType(const std::string& type);
    bool getIsHandmade() const;
    void setIsHandmade(bool handmade);
};

