#include "../include/Exhibition.h"
#include "../include/Artwork.h"
#include "../include/Curator.h"
#include <ctime>

Exhibition::Exhibition(const std::string& title, Gallery* gallery,
                       int startYear, int endYear)
    : title(title), gallery(gallery), admissionPrice(0.0), visitorCount(0), curator(nullptr) {
}

std::string Exhibition::getTitle() const {
    return title;
}

void Exhibition::setTitle(const std::string& title) {
    this->title = title;
}

std::string Exhibition::getDescription() const {
    return description;
}

void Exhibition::setDescription(const std::string& description) {
    this->description = description;
}

Gallery* Exhibition::getGallery() const {
    return gallery;
}

void Exhibition::setGallery(Gallery* gallery) {
    this->gallery = gallery;
}

void Exhibition::addArtwork(Artwork* artwork) {
    artworks.push_back(artwork);
}

std::vector<Artwork*> Exhibition::getArtworks() const {
    return artworks;
}

Curator* Exhibition::getCurator() const {
    return curator;
}

void Exhibition::setCurator(Curator* curator) {
    this->curator = curator;
}

std::string Exhibition::getTheme() const {
    return theme;
}

void Exhibition::setTheme(const std::string& theme) {
    this->theme = theme;
}

double Exhibition::getAdmissionPrice() const {
    return admissionPrice;
}

void Exhibition::setAdmissionPrice(double price) {
    this->admissionPrice = price;
}

int Exhibition::getVisitorCount() const {
    return visitorCount;
}

void Exhibition::setVisitorCount(int count) {
    this->visitorCount = count;
}

void Exhibition::incrementVisitorCount() {
    visitorCount++;
}

