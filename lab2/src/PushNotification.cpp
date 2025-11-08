#include "../include/PushNotification.h"

PushNotification::PushNotification()
    : words(""), bonuses(0), promo(0) {}

PushNotification::PushNotification(const std::string& words, int bonuses, int promo)
    : words(words), bonuses(bonuses), promo(promo) {}

std::string PushNotification::getWords() const {
    return words;
}

void PushNotification::setWords(const std::string& words) {
    this->words = words;
}

int PushNotification::getBonuses() const {
    return bonuses;
}

void PushNotification::setBonuses(int bonuses) {
    this->bonuses = bonuses;
}

int PushNotification::getPromo() const {
    return promo;
}

void PushNotification::setPromo(int promo) {
    this->promo = promo;
}

