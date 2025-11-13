#include "../include/Food.h"

Food::Food() = default;

Food::Food(const string& name, int cost, vector<FoodPosition>  composition, int cookingTime)
    : Eatable(name, cost, cookingTime), composition(composition), done(false) {}

vector<FoodPosition> Food::getComposition() const{
    return composition;
}

void Food::setComposition(vector<FoodPosition> composition) {
    this->composition = composition;
}

int Food::getCalories() {
    int total = 0;
    for (const auto& product : composition) {
        total += product.product.getCalories() * product.amount;
    }
    return total;
}
bool Food::getDone() const{
    return done;
}
void Food::setDone(bool done){
    this->done = done;
}