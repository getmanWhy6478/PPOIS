#pragma once

#include "Artwork.h"
#include <string>

class Photography : public Artwork {
private:
    std::string cameraType;
    std::string filmType;
    int shootYear;

public:
    Photography() = default;
    Photography(const std::string& title, int year, Artist* artist);
    ~Photography() = default;
    
    std::string getCameraType() const;
    void setCameraType(const std::string& type);
    std::string getFilmType() const;
    void setFilmType(const std::string& type);
    int getShootYear() const;
    void setShootYear(int year);
};

