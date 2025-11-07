#pragma once
#include "Vehicle.h"
using namespace std;
class Bike : public Vehicle {
private:
    bool isElectric;

public:
    Bike();
    Bike(const string& model, int capacity, bool isElectric);

    bool getIsElectric() const;
    void setIsElectric(bool value);
};

