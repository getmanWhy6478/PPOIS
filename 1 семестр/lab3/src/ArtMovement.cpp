#include "../include/ArtMovement.h"
#include "../include/Artist.h"

ArtMovement::ArtMovement(const std::string& name, int startYear)
    : name(name), startYear(startYear), endYear(0) {
}

std::string ArtMovement::getName() const {
    return name;
}

void ArtMovement::setName(const std::string& name) {
    this->name = name;
}

std::string ArtMovement::getDescription() const {
    return description;
}

void ArtMovement::setDescription(const std::string& description) {
    this->description = description;
}

int ArtMovement::getStartYear() const {
    return startYear;
}

void ArtMovement::setStartYear(int year) {
    this->startYear = year;
}

int ArtMovement::getEndYear() const {
    return endYear;
}

void ArtMovement::setEndYear(int year) {
    this->endYear = year;
}

void ArtMovement::addArtist(Artist* artist) {
    artists.push_back(artist);
}

std::vector<Artist*> ArtMovement::getArtists() const {
    return artists;
}





