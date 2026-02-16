#include "../include/Textile.h"
#include "../include/Artist.h"

Textile::Textile(const std::string& title, int year, Artist* artist)
    : Artwork(title, year, artist), isHandmade(false) {
}

std::string Textile::getTextileType() const {
    return textileType;
}

void Textile::setTextileType(const std::string& type) {
    this->textileType = type;
}

bool Textile::getIsHandmade() const {
    return isHandmade;
}

void Textile::setIsHandmade(bool handmade) {
    this->isHandmade = handmade;
}

