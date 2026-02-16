#include "../include/Drawing.h"
#include "../include/Artist.h"

Drawing::Drawing(const std::string& title, int year, Artist* artist)
    : Artwork(title, year, artist), isSigned(false), isDated(false) {
}

std::string Drawing::getDrawingMedium() const {
    return drawingMedium;
}

void Drawing::setDrawingMedium(const std::string& medium) {
    this->drawingMedium = medium;
}

std::string Drawing::getPaperSize() const {
    return paperSize;
}

void Drawing::setPaperSize(const std::string& size) {
    this->paperSize = size;
}

bool Drawing::getIsSigned() const {
    return isSigned;
}

void Drawing::setIsSigned(bool issigned) {
    this->isSigned = issigned;
}

bool Drawing::getIsDated() const {
    return isDated;
}

void Drawing::setIsDated(bool dated) {
    this->isDated = dated;
}

