#include "../include/Guide.h"
#include "../include/Tour.h"
#include <algorithm>

Guide::Guide(const std::string& firstName, const std::string& lastName,
             const std::string& employeeId, Gallery* gallery)
    : Employee(firstName, lastName, employeeId, gallery),
      totalToursConducted(0), averageRating(0.0) {
}

std::string Guide::getPosition() const {
    return "Guide";
}

void Guide::addLanguage(const std::string& language) {
    languages.push_back(language);
}

std::vector<std::string> Guide::getLanguages() const {
    return languages;
}

void Guide::addTour(Tour* tour) {
    tours.push_back(tour);
}

std::vector<Tour*> Guide::getTours() const {
    return tours;
}

int Guide::getTotalToursConducted() const {
    return totalToursConducted;
}

void Guide::incrementToursConducted() {
    totalToursConducted++;
}

double Guide::getAverageRating() const {
    return averageRating;
}

void Guide::setAverageRating(double rating) {
    this->averageRating = rating;
}

void Guide::updateAverageRating(double newRating) {
    if (totalToursConducted > 0) {
        averageRating = (averageRating * (totalToursConducted - 1) + newRating) / totalToursConducted;
    } else {
        averageRating = newRating;
    }
}

bool Guide::conductTour(Tour* tour, const std::string& languageUsed) {
    if (!tour) {
        return false;
    }

    if (!languageUsed.empty()) {
        auto languageIt = std::find(languages.begin(), languages.end(), languageUsed);
        if (languageIt == languages.end()) {
            return false;
        }
    }

    tour->setGuide(this);

    if (std::find(tours.begin(), tours.end(), tour) == tours.end()) {
        tours.push_back(tour);
    }

    incrementToursConducted();
    return true;
}

