#include "Place.h"

Place::Place() : square(0), yearsUsed(0) {}

Place::Place(int square, const Adress& adress) : square(square), yearsUsed(yearsUsed) {}

Place::Place(const Place& other) : square(other.square),yearsUsed(other.yearsUsed) {}

int Place::getSquare() {
    return square;
}

void Place::setSquare(int square) {
    this->square = square;
}

int Place::getYearsUsed() {
    return yearsUsed;
}

void Place::setYearsUsed(int YearsUsed) {
    this->yearsUsed = yearsUsed;
}

