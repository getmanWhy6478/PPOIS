#pragma once
#include "Worker.h"
#include "FoodPosition.h"
#include "Warehouse.h"
using namespace std;
class Supplier : public Worker {
public:
    Supplier();
    Supplier(const string& name, int salary);

    void addProduct(FoodPosition food, Warehouse& warehouse);
};