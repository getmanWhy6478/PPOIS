#pragma once
#include "Product.h"
#include "Eatable.h"
#include <vector>
using namespace std;
class Food : public Eatable{
public:
    Food();
    Food(const string& name, int cost, Product* composition, int cooking_time, bool done = false);
    Food(Food& other);
    int getTime();
    void setTime(int cooking_time);
    int getProductNeeded();
    void setProductNeeded(int product_needed);
    Product* getComposition();
    void setComposition(Product* composition);
    int countCalories();
    bool checkIfEnough(Product product);
private:
    vector<Product> composition;
    int cooking_time;
    int product_needed;
};