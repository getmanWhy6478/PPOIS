#include "../include/Rating.h"

Rating::Rating()
    : stars(0), words("") {}


Rating::Rating(int stars, const string& words)
    : stars(stars), words(words) {}

int Rating::getStars() const {
    return stars;
}

void Rating::setStars(int stars) {
    this->stars = stars;
}

string Rating::getWords() const {
    return words;
}

void Rating::setWords(const string& words) {
    this->words = words;
}
bool Rating::operator==(const Rating& other) const {
        return stars == other.stars && words == other.words;
}