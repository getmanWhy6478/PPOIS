#include "../include/Conservation.h"
#include "../include/Artwork.h"
#include "../include/Restorer.h"

Conservation::Conservation(const std::string& conservationId, Artwork* artwork,
                           Restorer* conservator)
    : conservationId(conservationId), artwork(artwork), conservator(conservator),
      cost(0.0), status("planned"), startYear(0), completionYear(0) {
}

std::string Conservation::getConservationId() const {
    return conservationId;
}

void Conservation::setConservationId(const std::string& id) {
    this->conservationId = id;
}

Artwork* Conservation::getArtwork() const {
    return artwork;
}

void Conservation::setArtwork(Artwork* artwork) {
    this->artwork = artwork;
}

Restorer* Conservation::getConservator() const {
    return conservator;
}

void Conservation::setConservator(Restorer* conservator) {
    this->conservator = conservator;
}

int Conservation::getStartYear() const {
    return startYear;
}

void Conservation::setStartYear(int year) {
    this->startYear = year;
}

int Conservation::getCompletionYear() const {
    return completionYear;
}

void Conservation::setCompletionYear(int year) {
    this->completionYear = year;
}

double Conservation::getCost() const {
    return cost;
}

void Conservation::setCost(double cost) {
    this->cost = cost;
}

std::string Conservation::getStatus() const {
    return status;
}

void Conservation::setStatus(const std::string& status) {
    this->status = status;
}

bool Conservation::isCompleted() const {
    return status == "completed";
}


