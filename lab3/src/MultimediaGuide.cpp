#include "../include/MultimediaGuide.h"
#include "../include/Artwork.h"
#include "../include/Exhibition.h"

MultimediaGuide::MultimediaGuide(const std::string& guideId, const std::string& guideName,
                                  const std::string& language)
    : guideId(guideId), guideName(guideName), language(language),
      durationMinutes(0), isAvailable(true),
      totalRentals(0), averageRating(0.0), exhibition(nullptr) {
}

std::string MultimediaGuide::getGuideId() const {
    return guideId;
}

void MultimediaGuide::setGuideId(const std::string& id) {
    this->guideId = id;
}

std::string MultimediaGuide::getGuideName() const {
    return guideName;
}

void MultimediaGuide::setGuideName(const std::string& name) {
    this->guideName = name;
}

std::string MultimediaGuide::getLanguage() const {
    return language;
}

void MultimediaGuide::setLanguage(const std::string& language) {
    this->language = language;
}

void MultimediaGuide::addCoveredArtwork(Artwork* artwork) {
    coveredArtworks.push_back(artwork);
}

std::vector<Artwork*> MultimediaGuide::getCoveredArtworks() const {
    return coveredArtworks;
}

Exhibition* MultimediaGuide::getExhibition() const {
    return exhibition;
}

void MultimediaGuide::setExhibition(Exhibition* exhibition) {
    this->exhibition = exhibition;
}

int MultimediaGuide::getDurationMinutes() const {
    return durationMinutes;
}

void MultimediaGuide::setDurationMinutes(int minutes) {
    this->durationMinutes = minutes;
}
bool MultimediaGuide::getIsAvailable() const {
    return isAvailable;
}

void MultimediaGuide::setIsAvailable(bool available) {
    this->isAvailable = available;
}

int MultimediaGuide::getTotalRentals() const {
    return totalRentals;
}

void MultimediaGuide::incrementTotalRentals() {
    totalRentals++;
}

double MultimediaGuide::getAverageRating() const {
    return averageRating;
}

void MultimediaGuide::setAverageRating(double rating) {
    this->averageRating = rating;
}

