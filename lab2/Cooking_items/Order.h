#pragma once
#include "OrderPosition.h"
#include <vector>
class Order{
public:
    int countCost();
    int countTime();
    int countBonuses();
    int countTime();
private:
    vector<OrderPosition> eatList;
    string adress;
    bool done;
    bool delievered;
};