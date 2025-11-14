#pragma once
#include <string>
#include <vector>
#include "FoodPosition.h"
#include "Place.h"
#include "WarehouseRequirement.h"
using namespace std;
class Warehouse : public Place {
public:
    Warehouse();

    Warehouse(int capacity, int area, const WarehouseRequirement& requirement, const vector<FoodPosition>& stored) ;

    WarehouseRequirement getRequirement() const;
    void setRequirement(const WarehouseRequirement& requirement);

    vector<FoodPosition> getStored() const;
    void setStored(FoodPosition& foodPosition);

    int getCapacity() const;
    void setCapacity(int capacity);

    bool isFull() const;

private:
    int capacity;
    WarehouseRequirement requirement;
    vector<FoodPosition> stored;

    friend class Cook;
    friend class Supplier;
};
