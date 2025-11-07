#pragma once
#include "Product.h"
#include "Eatable.h"
#include "FoodPosition.h"
#include <vector>
using namespace std;
class Food : public Eatable{
public:
    Food(const string& name, int cost, vector<FoodPosition> composition, int cookingTime);
    Food(Food& other);
    int getTime() const;
    void setTime(int cookingTime);
    vector<FoodPosition> getComposition() const;
    void setComposition(vector<FoodPosition> composition);
    int getCalories();
private:
    vector<FoodPosition> composition;
    bool done;
};