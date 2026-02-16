#pragma once
#include "Eatable.h"
#include <string>
using namespace std;
class OrderPosition {
public:
    OrderPosition();
    OrderPosition(Eatable& eatable, int amount);

    Eatable getEatable();
    void setEatable(Eatable& eat);

    int getAmount() const;
    void setAmount(int amount);
    
    bool isDone() const;
    void setDone(bool done);
private:
    Eatable eat;
    int amount;
    bool done;
friend class Order;
};