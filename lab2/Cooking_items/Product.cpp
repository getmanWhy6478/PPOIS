#include "Product.h"

Product::Product() : name(""), calories(0) {}

Product::Product(string name, int calories, int amount)
    : name(name), calories(calories) {}

Product::Product(const Product& other) : name(other.name), calories(other.calories){}

int Product::getCalories() {
    return calories;
}

void Product::setCalories(int calories) {
    this->calories = calories;
}

string Product::getName() {
    return name;
}

void Product::setName(const string& name) {
    this->name = name;
}
