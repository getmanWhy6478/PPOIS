#pragma once
#include <string>
#include "Worker.h"
#include "OrderPosition.h"
#include "Product.h"

class Restaurant;
using namespace std;
class Cook : public Worker {
public:
    Cook();
    Cook(const string& name, int salary, bool active = true);
    
    bool getActive() const;
    void setActive(bool active);

    void takeProducts(const Product& product, int amount, Restaurant restaurant);
    void Cooking(OrderPosition& orderPosition);
private:
    bool active;
};