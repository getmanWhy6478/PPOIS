#pragma once
#include "Eatable.h"
class Drink : public Eatable{
public:
    Drink();
    Drink(const string& name, int cost, int calories);
    Drink(const Drink& other);

    bool isEighteenPlus();
    void setIsEighteenPlus(bool eighteenPlus);
    
private:
    bool eighteenPlus;
};