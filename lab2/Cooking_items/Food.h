#pragma once
#include "Product.h"
#include "Eatable.h"
#include <vector>
using namespace std;
class Food : public Eatable{
public:
    Food(const string& name, int cost, vector<pair<Product, int>> composition, int cooking_time);
    Food(Food& other);
    int getTime() const;
    void setTime(int cookingTime);
    vector<pair<Product, int>> getComposition() const;
    void setComposition(vector<pair<Product, int>> composition);
    int getCalories();
private:
    vector<pair<Product, int>> composition;
    bool done;
};