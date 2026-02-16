#pragma once
#include <string>
#include "Worker.h"
#include "Restaurant.h"
#include "Manager.h"
using namespace std;
class CEO : public Worker {
public:
    CEO();
    CEO(const string& name, int salary);

    void hireManager(const Manager& manager, Restaurant restaurant);
    void fireManager(Restaurant restaurant);

};
