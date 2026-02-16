#include "../include/Sculpture.h"
#include "../include/Artist.h"

Sculpture::Sculpture(const std::string& title, int year, Artist* artist)
    : Artwork(title, year, artist),
      baseWidth(0.0), baseHeight(0.0), baseDepth(0.0) {
}

std::string Sculpture::getMaterial() const {
    return material;
}

void Sculpture::setMaterial(const std::string& material) {
    this->material = material;
}

double Sculpture::getBaseWidth() const {
    return baseWidth;
}

void Sculpture::setBaseWidth(double width) {
    this->baseWidth = width;
}

double Sculpture::getBaseHeight() const {
    return baseHeight;
}

void Sculpture::setBaseHeight(double height) {
    this->baseHeight = height;
}

double Sculpture::getBaseDepth() const {
    return baseDepth;
}

void Sculpture::setBaseDepth(double depth) {
    this->baseDepth = depth;
}

