#include "Rating.h"

Rating::Rating()
    : stars(0), words("") {}

// Конструктор с параметрами
Rating::Rating(int stars, const std::string& words)
    : stars(stars), words(words) {}

int Rating::getStars() const {
    return stars;
}

void Rating::setStars(int stars) {
    this->stars = stars;
}

std::string Rating::getWords() const {
    return words;
}

void Rating::setWords(const std::string& words) {
    this->words = words;
}
