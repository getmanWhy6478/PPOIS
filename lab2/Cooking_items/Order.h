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
    int getID();
    void setEatList(vector<OrderPosition> eatList);
    void setAdress(const string& adress);
    void setIsDone(bool done);
    void setIsDelievered(bool delievered);
    void setID(int id);
private:
    vector<OrderPosition> eatList;
    string adress;
    bool done;
    bool delievered;
    int id;
friend class Customer;
friend class NotAuthorisedCustomer;
};