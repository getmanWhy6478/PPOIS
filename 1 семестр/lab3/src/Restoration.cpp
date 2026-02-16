#include "../include/Restoration.h"
#include "../include/Artwork.h"
#include "../include/Restorer.h"

Restoration::Restoration(const std::string& restorationId, Artwork* artwork,
                         Restorer* restorer)
    : restorationId(restorationId), artwork(artwork), restorer(restorer),
      cost(0.0), status("planned"), startYear(0), completionYear(0) {
}

std::string Restoration::getRestorationId() const {
    return restorationId;
}

void Restoration::setRestorationId(const std::string& id) {
    this->restorationId = id;
}

Artwork* Restoration::getArtwork() const {
    return artwork;
}

void Restoration::setArtwork(Artwork* artwork) {
    this->artwork = artwork;
}

Restorer* Restoration::getRestorer() const {
    return restorer;
}

void Restoration::setRestorer(Restorer* restorer) {
    this->restorer = restorer;
}

int Restoration::getStartYear() const {
    return startYear;
}

void Restoration::setStartYear(int year) {
    this->startYear = year;
}

int Restoration::getCompletionYear() const {
    return completionYear;
}

void Restoration::setCompletionYear(int year) {
    this->completionYear = year;
}

std::string Restoration::getConditionBefore() const {
    return conditionBefore;
}

void Restoration::setConditionBefore(const std::string& condition) {
    this->conditionBefore = condition;
}

std::string Restoration::getConditionAfter() const {
    return conditionAfter;
}

void Restoration::setConditionAfter(const std::string& condition) {
    this->conditionAfter = condition;
}

void Restoration::addTechnique(const std::string& technique) {
    techniquesUsed.push_back(technique);
}

std::vector<std::string> Restoration::getTechniquesUsed() const {
    return techniquesUsed;
}

double Restoration::getCost() const {
    return cost;
}

void Restoration::setCost(double cost) {
    this->cost = cost;
}

std::string Restoration::getStatus() const {
    return status;
}

void Restoration::setStatus(const std::string& status) {
    this->status = status;
}

bool Restoration::isCompleted() const {
    return status == "completed";
}

