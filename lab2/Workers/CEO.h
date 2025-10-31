#pragma once
#include <string>
#include "Worker.h"
#include "Restaurant.h"
#include "Manager.h"
using namespace std;
class CEO : public Worker {
public:
    CEO();
    CEO(const string& name, int salary, Restaurant* restaurant);

    void hireManager(Restaurant& restaurant, const Manager& manager);
    void fireManager(Restaurant& restaurant);

};
