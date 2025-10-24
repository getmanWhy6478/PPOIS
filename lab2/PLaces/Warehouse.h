#pragma once
#include <string>
#include <vector>
#include "Product.h"
#include "Place.h"
using namespace std;
class Warehouse : public Place{
public:
    int getCapacity();
    void setCapacity(int capacity);
    vector <pair<Product,int>> getStored();
    void setStored (Product product, int amount);
private:
    int capacity;
    vector <pair<Product,int>> stored;
friend class Cook;
};