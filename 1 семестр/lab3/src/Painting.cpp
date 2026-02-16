#include "../include/Painting.h"
#include "../include/Artist.h"

Painting::Painting(const std::string& title, int year, Artist* artist)
    : Artwork(title, year, artist), isFramed(false) {
}

std::string Painting::getPaintType() const {
    return paintType;
}

void Painting::setPaintType(const std::string& type) {
    this->paintType = type;
}

std::string Painting::getCanvasType() const {
    return canvasType;
}

void Painting::setCanvasType(const std::string& type) {
    this->canvasType = type;
}

bool Painting::getIsFramed() const {
    return isFramed;
}

void Painting::setIsFramed(bool framed) {
    this->isFramed = framed;
}

