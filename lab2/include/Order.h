#pragma once
#include "OrderPosition.h"
#include <vector>
class Order{
public:
    double getCost()const;
    int getTime()const;
    int getBonuses()const;
    vector<OrderPosition> getEatList() const;
    string getAdress() const;
    bool isDone()const;
    bool isDelievered() const;
    int getID() const;
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