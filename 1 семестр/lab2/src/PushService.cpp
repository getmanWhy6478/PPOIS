#include "../include/PushService.h"

PushService::PushService()
    : language("ru") {}

PushService::PushService(const std::string& lang)
    : language(lang) {}

std::string PushService::getLanguage() const {
    return language;
}

void PushService::setLanguage(const string& language) {
    this->language = language;
}

PushNotification PushService::createPushNotification(const string& words, int bonuses, int promo) {
    return PushNotification(words, bonuses, promo);
}
