#pragma once
#include "Worker.h"
#include "Cook.h"
using namespace std;
class Restaurant;
class Courier;
class Manager : public Worker {
public:
    Manager();
    Manager(const string& name, int salary);

    void Hire(Courier& courier, Restaurant& restaurant);
    void Hire(Cook& cook, Restaurant& restaurant);
    void Fire(Courier& courier, Restaurant& restaurant);
    void Fire(Cook& cook, Restaurant& restaurant);
    void addEatable(Eatable& eat, Restaurant& restaurant);
    void deleteEatable(Eatable& eat, Restaurant& restaurant);
};