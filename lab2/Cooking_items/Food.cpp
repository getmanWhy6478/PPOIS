#include "Food.h"

Food::Food(const string& name, int cost, vector<pair<Product, int>>  composition, int cookingTime)
    : Eatable(name, cost, cookingTime), composition(composition), done(false) {}


Food::Food(Food& other)
    : Eatable(other), composition(other.composition),
      done(other.done) {}
vector<pair<Product, int>> Food::getComposition() const{
    return composition;
}

void Food::setComposition(vector<pair<Product, int>> composition) {
    this->composition = composition;
}

int Food::getCalories() {
    int total = 0;
    for (const auto& product : composition) {
        total += product.first.getCalories() * product.second;
    }
    return total;
}
