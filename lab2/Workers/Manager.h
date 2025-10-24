#pragma once
#include "Worker.h"
#include "Order.h"
class Manager : public Worker {
public:
    void Hire(Worker& worker);
    void Fire(Worker& worker);
    void addEatable(Eatable& eat);
    void deleteEatable(Eatable& eat);
};