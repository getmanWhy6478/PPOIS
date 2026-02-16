#include "../include/ComboMeal.h"
#include <algorithm>
ComboMeal::ComboMeal()
    : name(""), includedItems(), price(0), available(true) {}
ComboMeal::ComboMeal(const string& name, const vector<Eatable>& items, double price)
    :name(name), includedItems(items), price(price), available(true) {}


const string& ComboMeal::getName() const {
    return name;
}

const vector<Eatable>& ComboMeal::getIncludedItems() const {
    return includedItems;
}

double ComboMeal::getPrice() const {
    return price;
}

bool ComboMeal::isAvailable() const {
    return available;
}

void ComboMeal::setName(const string& name) {
    this->name = name;
}

void ComboMeal::setPrice(double price) {
    this->price = price;
}

void ComboMeal::setAvailability(bool available) {
    this->available = available;
}

void ComboMeal::addItem(const Eatable& item) {
    includedItems.push_back(item);
}

void ComboMeal::removeItem(const Eatable& item) {
    auto it = remove(includedItems.begin(), includedItems.end(), item);
    if (it != includedItems.end()) {
        includedItems.erase(it, includedItems.end());
    }
}

void ComboMeal::clearItems() {
    includedItems.clear();
}
