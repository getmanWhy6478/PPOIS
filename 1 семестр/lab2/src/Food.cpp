#include "../include/Food.h"

Food::Food() = default;

Food::Food(const string& name, int cost, vector<FoodPosition>  composition, int cookingTime, time_t exparationTime)
    : Eatable(name, cost, cookingTime, exparationTime), composition(composition), done(false) {}

vector<FoodPosition> Food::getComposition() const{
    return composition;
}

void Food::setComposition(vector<FoodPosition> composition) {
    this->composition = composition;
}

int Food::getCalories() {
    int total = 0;
    for (const auto& product : composition) {
        total += product.getProduct().getCalories() * product.getAmount();
    }
    return total;
}
bool Food::getDone() const{
    return done;
}
void Food::setDone(bool done){
    this->done = done;
}