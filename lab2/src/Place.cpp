#include "../include/Place.h"

Place::Place() : area(0) {}

Place::Place(int area) : area(area) {}

Place::Place(const Place& other) : area(other.area) {}

int Place::getArea() const{
    return area;
}

void Place::setArea(int area) {
    this->area = area;
}
