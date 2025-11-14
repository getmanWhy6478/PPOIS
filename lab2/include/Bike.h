#pragma once
#include "Vehicle.h"
#include "Delivery.h"
using namespace std;
class Bike : public Vehicle {
public:
    Bike();
    Bike(const string& model, int capacity, bool isElectric);

    bool getIsElectric() const;
    void setIsElectric(bool value);

    void speedUp(Delivery& delivery);
private:
    bool isElectric;

};

