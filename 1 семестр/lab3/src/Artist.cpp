#include "../include/Artist.h"
#include "../include/Artwork.h"
#include "../include/ArtMovement.h"
#include <ctime>

Artist::Artist(const std::string& firstName, const std::string& lastName,
               const std::string& nationality, int birthYear)
    : firstName(firstName), lastName(lastName), nationality(nationality),
      birthYear(birthYear), deathYear(0), isAlive(true) {
}

std::string Artist::getFirstName() const {
    return firstName;
}

void Artist::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

std::string Artist::getLastName() const {
    return lastName;
}

void Artist::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

std::string Artist::getFullName() const {
    return firstName + " " + lastName;
}

std::string Artist::getNationality() const {
    return nationality;
}

void Artist::setNationality(const std::string& nationality) {
    this->nationality = nationality;
}

int Artist::getBirthYear() const {
    return birthYear;
}

void Artist::setBirthYear(int year) {
    this->birthYear = year;
}

int Artist::getDeathYear() const {
    return deathYear;
}

void Artist::setDeathYear(int year) {
    this->deathYear = year;
    if (year > 0) {
        isAlive = false;
    }
}

std::string Artist::getBiography() const {
    return biography;
}

void Artist::setBiography(const std::string& biography) {
    this->biography = biography;
}

void Artist::addMovement(ArtMovement* movement) {
    movements.push_back(movement);
}

std::vector<ArtMovement*> Artist::getMovements() const {
    return movements;
}

void Artist::addArtwork(Artwork* artwork) {
    artworks.push_back(artwork);
}

std::vector<Artwork*> Artist::getArtworks() const {
    return artworks;
}

std::string Artist::getStyle() const {
    return style;
}

void Artist::setStyle(const std::string& style) {
    this->style = style;
}

bool Artist::getIsAlive() const {
    return isAlive;
}

void Artist::setIsAlive(bool alive) {
    this->isAlive = alive;
}
Artwork Artist::createMasterpiece(const std::string& title, int age){
    return Artwork(title, age, this);
}

int Artist::getAge() const {
    if (!isAlive && deathYear > 0) {
        return deathYear - birthYear;
    }
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    int currentYear = now->tm_year + 1900;
    return currentYear - birthYear;
}

