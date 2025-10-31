#pragma once
#include <string>
#include "Restaurant.h"
using namespace std;
class Worker {
public:
    Worker();
    Worker(const string& name, int salary, Restaurant* restaurant = nullptr);
    Worker(const Worker& other);

    Restaurant* getRestaurant();
    void setRestaurant(Restaurant* restaurant);

    int getSalary();
    void setSalary(int salary);

    string getName();
    void setName(const string& name);

protected:
    string name;
    Restaurant* restaurant;
    int salary;
};