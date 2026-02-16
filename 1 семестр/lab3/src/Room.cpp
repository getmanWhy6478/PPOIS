#include "../include/Room.h"
#include "../include/Artwork.h"

Room::Room(const std::string& name, const std::string& number, double area)
    : name(name), number(number), area(area), height(0.0), maxCapacity(0){
}

std::string Room::getName() const {
    return name;
}

void Room::setName(const std::string& name) {
    this->name = name;
}

std::string Room::getNumber() const {
    return number;
}

void Room::setNumber(const std::string& number) {
    this->number = number;
}

double Room::getArea() const {
    return area;
}

void Room::setArea(double area) {
    this->area = area;
}

double Room::getHeight() const {
    return height;
}

void Room::setHeight(double height) {
    this->height = height;
}

int Room::getMaxCapacity() const {
    return maxCapacity;
}

void Room::setMaxCapacity(int capacity) {
    this->maxCapacity = capacity;
}

void Room::addArtwork(Artwork* artwork) {
    artworks.push_back(artwork);
}

void Room::removeArtwork(Artwork* artwork) {
    for (auto it = artworks.begin(); it != artworks.end(); ++it) {
        if (*it == artwork) {
            artworks.erase(it);
            break;
        }
    }
}

std::vector<Artwork*> Room::getArtworks() const {
    return artworks;
}
