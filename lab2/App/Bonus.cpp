#include "Bonus.h"
#include <stdexcept>
#include <ctime>

Bonus::Bonus()
    : name(""), discountPercent(0.0), isActive(false), expirationTime(time(nullptr)) {}

Bonus::Bonus(const string& name, double discountPercent, time_t expirationTime, bool isActive)
    : name(name), isActive(isActive), expirationTime(expirationTime) {
    setDiscountPercent(discountPercent);
}

// Геттеры
string Bonus::getName() const {
    return name;
}

double Bonus::getDiscountPercent() const {
    return discountPercent;
}

bool Bonus::getIsActive() const {
    return isActive;
}

time_t Bonus::getExpirationTime() const {
    return expirationTime;
}

void Bonus::setName(const string& name) {
    this->name = name;
}

void Bonus::setDiscountPercent(double percent) {
    if (percent < 0.0 || percent > 100.0) {
        throw invalid_argument("Скидка должна быть от 0 до 100%");
    }
    discountPercent = percent;
}

void Bonus::setIsActive(bool active) {
    isActive = active;
}

void Bonus::setExpirationTime(time_t time) {
    expirationTime = time;
}

// Проверка на истечение срока действия
bool Bonus::isExpired() const {
    return time(nullptr) > expirationTime;
}

// Применение бонуса к цене
double Bonus::applyTo(double originalPrice) const {
    if (!isActive || isExpired()) return originalPrice;
    return originalPrice * (1.0 - discountPercent / 100.0);
}

