#include "../include/Photography.h"
#include "../include/Artist.h"

Photography::Photography(const std::string& title, int year, Artist* artist)
    : Artwork(title, year, artist), shootYear(0) {
}

std::string Photography::getCameraType() const {
    return cameraType;
}

void Photography::setCameraType(const std::string& type) {
    this->cameraType = type;
}

std::string Photography::getFilmType() const {
    return filmType;
}

void Photography::setFilmType(const std::string& type) {
    this->filmType = type;
}

int Photography::getShootYear() const {
    return shootYear;
}

void Photography::setShootYear(int year) {
    this->shootYear = year;
}

