#pragma once
#include <string>
#include "Adress.h"
using namespace std;
class Place{
public:
    Place();

    Place(int square, const Adress& adress);

    Place(const Place& other);

    int getSquare();
    void setSquare(int square);

    int getYearsUsed();
    void setYearsUsed(int years_used);

protected:
    int square;
    int yearsUsed;
};