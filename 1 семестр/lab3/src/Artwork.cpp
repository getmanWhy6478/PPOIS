#include "../include/Artwork.h"
#include "../include/Artist.h"

Artwork::Artwork(const std::string& title, int year, Artist* artist)
    : title(title), year(year), artist(artist), width(0.0), height(0.0),
      depth(0.0), weight(0.0), estimatedValue(0.0) {
}

std::string Artwork::getTitle() const {
    return title;
}

void Artwork::setTitle(const std::string& title) {
    this->title = title;
}

std::string Artwork::getDescription() const {
    return description;
}

void Artwork::setDescription(const std::string& description) {
    this->description = description;
}

int Artwork::getYear() const {
    return year;
}

void Artwork::setYear(int year) {
    this->year = year;
}

double Artwork::getWidth() const {
    return width;
}

void Artwork::setWidth(double width) {
    this->width = width;
}

double Artwork::getHeight() const {
    return height;
}

void Artwork::setHeight(double height) {
    this->height = height;
}

double Artwork::getDepth() const {
    return depth;
}

void Artwork::setDepth(double depth) {
    this->depth = depth;
}

double Artwork::getWeight() const {
    return weight;
}

void Artwork::setWeight(double weight) {
    this->weight = weight;
}

std::string Artwork::getCondition() const {
    return condition;
}

void Artwork::setCondition(const std::string& condition) {
    this->condition = condition;
}

double Artwork::getEstimatedValue() const {
    return estimatedValue;
}

void Artwork::setEstimatedValue(double value) {
    this->estimatedValue = value;
}

Artist* Artwork::getArtist() const {
    return artist;
}

void Artwork::setArtist(Artist* artist) {
    this->artist = artist;
}

std::string Artwork::getMedium() const {
    return medium;
}

void Artwork::setMedium(const std::string& medium) {
    this->medium = medium;
}

std::string Artwork::getTechnique() const {
    return technique;
}

void Artwork::setTechnique(const std::string& technique) {
    this->technique = technique;
}
