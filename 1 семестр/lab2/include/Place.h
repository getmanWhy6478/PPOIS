#pragma once
#include <string>
using namespace std;
class Place{
public:
    Place();
    Place(int area);
    Place(const Place& other);

    int getArea() const;
    void setArea(int area);
protected:
    int area;
};