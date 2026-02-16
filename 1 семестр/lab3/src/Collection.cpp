#include "../include/Collection.h"
#include "../include/Artwork.h"
#include "../include/Collector.h"
#include <ctime>

Collection::Collection(const std::string& name, Collector* collector)
    : name(name), collector(collector), totalArtworks(0), totalValue(0.0) {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
}

std::string Collection::getName() const {
    return name;
}

void Collection::setName(const std::string& name) {
    this->name = name;
}

std::string Collection::getDescription() const {
    return description;
}

void Collection::setDescription(const std::string& description) {
    this->description = description;
}

Collector* Collection::getCollector() const {
    return collector;
}

void Collection::setCollector(Collector* collector) {
    this->collector = collector;
}

void Collection::addArtwork(Artwork* artwork) {
    artworks.push_back(artwork);
    updateStatistics();
}

void Collection::removeArtwork(Artwork* artwork) {
    for (auto it = artworks.begin(); it != artworks.end(); ++it) {
        if (*it == artwork) {
            artworks.erase(it);
            updateStatistics();
            break;
        }
    }
}

std::vector<Artwork*> Collection::getArtworks() const {
    return artworks;
}

int Collection::getTotalArtworks() const {
    return totalArtworks;
}

double Collection::getTotalValue() const {
    return totalValue;
}

void Collection::updateStatistics() {
    totalArtworks = artworks.size();
    totalValue = 0.0;
    for (auto* artwork : artworks) {
        if (artwork) {
            totalValue += artwork->getEstimatedValue();
        }
    }
}

bool Collection::operator==(const Collection& other) const {
    if (name != other.name) 
        return false;
    if (description != other.description) 
        return false;
    if (collector != other.collector) 
        return false;

    if (totalArtworks != other.totalArtworks) 
        return false;
    if (totalValue != other.totalValue) 
        return false;

    if (artworks.size() != other.artworks.size()) 
        return false;
    for (size_t i = 0; i < artworks.size(); ++i) {
        if (artworks[i] != other.artworks[i]) 
        return false;
    }

    return true;
}