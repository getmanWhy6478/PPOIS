#pragma once
#include <string>
#include "Worker.h"
#include "OrderPosition.h"
#include "Product.h"
using namespace std;
class Cook : public Worker {
public:
    void takeProducts(Product product, int amount);
    void Cooking(OrderPosition orderPosition);
private:
    bool active;
};