#pragma once
#include "OrderPosition.h"
#include <vector>
class Order{
public:
    int getCost();
    int getTime();
    int getBonuses();
    vector<OrderPosition> getEatList();
    string getAdress();
    bool isDone();
    bool isDelievered();
    void setEatList(vector<OrderPosition> eatList);
    void setAdress(const string& adress);
    void setIsDone(bool done);
    void setIsDelievered(bool delievered);
private:
    vector<OrderPosition> eatList;
    string adress;
    bool done;
    bool delievered;
friend class Customer;
};