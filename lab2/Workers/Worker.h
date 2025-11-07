#pragma once
#include <string>
#include "Restaurant.h"
using namespace std;
class Worker {
public:
    Worker();
    Worker(const string& name, int salary, Restaurant* restaurant = nullptr);
    Worker(const Worker& other);

    Restaurant* getRestaurant() const;
    void setRestaurant(Restaurant* restaurant);

    int getSalary() const;
    void setSalary(int salary);

    string getName() const;
    void setName(const string& name);

    bool operator==(const Worker& other);

protected:
    string name;
    Restaurant* restaurant;
    int salary;
};