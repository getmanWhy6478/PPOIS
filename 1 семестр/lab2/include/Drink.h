#pragma once
#include "Eatable.h"
#include <ctime>
class Drink : public Eatable{
public:
    Drink();
    Drink(const string& name, int cost, int calories);

    bool isEighteenPlus() const;
    void setIsEighteenPlus(bool eighteenPlus);

    int getCalories() const;
    void setCalories(int calories);
    
private:
    bool eighteenPlus;
    int calories;
};