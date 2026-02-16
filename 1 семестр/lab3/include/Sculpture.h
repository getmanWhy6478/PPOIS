#pragma once

#include "Artwork.h"
#include <string>

class Sculpture : public Artwork {
private:
    std::string material;
    double baseWidth;
    double baseHeight;
    double baseDepth;

public: 
    Sculpture() = default;
    Sculpture(const std::string& title, int year, Artist* artist);
    ~Sculpture() = default;
    
    std::string getMaterial() const;
    void setMaterial(const std::string& material);
    double getBaseWidth() const;
    void setBaseWidth(double width);
    double getBaseHeight() const;
    void setBaseHeight(double height);
    double getBaseDepth() const;
    void setBaseDepth(double depth);
};

