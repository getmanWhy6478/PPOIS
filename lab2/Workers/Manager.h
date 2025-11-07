#pragma once
#include "Worker.h"
#include "Order.h"
using namespace std;
class Manager : public Worker {
public:
    Manager();
    Manager(const string& name, int salary, Restaurant* restaurant = nullptr);

    void Hire(Courier& courier);
    void Hire(Cook& cook);
    void Fire(Courier& courier);
    void Fire(Cook& cook);
    void addEatable(Eatable& eat);
    void deleteEatable(Eatable& eat);
};