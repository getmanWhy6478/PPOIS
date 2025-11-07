#pragma once
#include <string>
#include "Worker.h"
#include "OrderPosition.h"
#include "Product.h"
using namespace std;
class Cook : public Worker {
public:
    Cook();
    Cook(const string& name, int salary, Restaurant* restaurant = nullptr, bool active = true);
    bool getActive() const;
    void setActive(bool active);
    void takeProducts(const Product& product, int amount);
    void Cooking(OrderPosition& orderPosition);
private:
    bool active;
};