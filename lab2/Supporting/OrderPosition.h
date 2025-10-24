#pragma once
#include "Eatable.h"
#include <string>
using namespace std;
class OrderPosition {
public:
    Eatable getEatable();
    void setEatable(Eatable& eat);
    int getAmount();
    void setAmount(int amount);
    bool isDone();
    void setDone(bool done);
private:
    Eatable eat;
    int amount;
    bool done;
};