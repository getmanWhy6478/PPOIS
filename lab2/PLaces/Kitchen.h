#pragma once
#include <string>
#include "Place.h"
using namespace std;
class Kitchen : public Place {
public:

private:
    int cooksNeeded;

    bool hasStove;
    bool hasOven;
    bool hasMicrowave;
    bool hasDishwasher;
    bool hasFridge;
};ыкп