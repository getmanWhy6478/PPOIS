#include "../include/Period.h"
#include "../include/Artwork.h"

Period::Period(const std::string& name, int startYear, int endYear)
    : name(name), startYear(startYear), endYear(endYear) {
}

std::string Period::getName() const {
    return name;
}

void Period::setName(const std::string& name) {
    this->name = name;
}

std::string Period::getDescription() const {
    return description;
}

void Period::setDescription(const std::string& description) {
    this->description = description;
}

int Period::getStartYear() const {
    return startYear;
}

void Period::setStartYear(int year) {
    this->startYear = year;
}

int Period::getEndYear() const {
    return endYear;
}

void Period::setEndYear(int year) {
    this->endYear = year;
}

void Period::addArtwork(Artwork* artwork) {
    artworks.push_back(artwork);
}

std::vector<Artwork*> Period::getArtworks() const {
    return artworks;
}

void Period::addKeyEvent(const std::string& event) {
    keyEvents.push_back(event);
}

std::vector<std::string> Period::getKeyEvents() const {
    return keyEvents;
}

int Period::getDuration() const {
    if (endYear > startYear) {
        return endYear - startYear;
    }
    return 0;
}


