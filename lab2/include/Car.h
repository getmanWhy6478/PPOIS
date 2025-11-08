#pragma once
#include "Vehicle.h"
using namespace std;
class Car : public Vehicle {
public:
    Car();
    Car(const string& model, int capacity, int seatCount);

    int getSeatCount() const;
    void setSeatCount(int count);
private:
    int seatCount;

};
