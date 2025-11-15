#pragma once
#include "Product.h"
#include "Eatable.h"
#include "FoodPosition.h"
#include <vector>
using namespace std;
class Food : public Eatable{
public:
    Food();
    Food(const string& name, int cost, vector<FoodPosition> composition, int cookingTime, time_t ExparationTime);

    vector<FoodPosition> getComposition() const;
    void setComposition(vector<FoodPosition> composition);
    
    int getCalories();

    bool getDone() const;
    void setDone(bool done);
private:
    vector<FoodPosition> composition;
    bool done;
};