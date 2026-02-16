#include "../include/Tour.h"
#include "../include/Guide.h"
#include "../include/Visitor.h"
#include "../include/Exhibition.h"

Tour::Tour(const std::string& tourId, Guide* guide, Exhibition* exhibition)
    : tourId(tourId), guide(guide), exhibition(exhibition), maxParticipants(0),
      price(0.0), averageRating(0.0) {
}

std::string Tour::getTourId() const {
    return tourId;
}

void Tour::setTourId(const std::string& id) {
    this->tourId = id;
}

Guide* Tour::getGuide() const {
    return guide;
}

void Tour::setGuide(Guide* guide) {
    this->guide = guide;
}

void Tour::addVisitor(Visitor* visitor) {
    visitors.push_back(visitor);
}

std::vector<Visitor*> Tour::getVisitors() const {
    return visitors;
}

Exhibition* Tour::getExhibition() const {
    return exhibition;
}

void Tour::setExhibition(Exhibition* exhibition) {
    this->exhibition = exhibition;
}

int Tour::getMaxParticipants() const {
    return maxParticipants;
}

void Tour::setMaxParticipants(int max) {
    this->maxParticipants = max;
}

bool Tour::isFull() const {
    if (maxParticipants <= 0) return false;
    return visitors.size() >= static_cast<size_t>(maxParticipants);
}

double Tour::getPrice() const {
    return price;
}

void Tour::setPrice(double price) {
    this->price = price;
}

std::string Tour::getTheme() const {
    return theme;
}

void Tour::setTheme(const std::string& theme) {
    this->theme = theme;
}

double Tour::getAverageRating() const {
    return averageRating;
}

void Tour::setAverageRating(double rating) {
    this->averageRating = rating;
}

