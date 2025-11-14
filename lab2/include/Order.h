#pragma once
#include "OrderPosition.h"
#include <vector>
class Order{
public:
    Order();
    Order(const vector<OrderPosition>& eatList, const string& adress, bool done,
          bool delievered, int id);

    double getCost() const;
    int getTime() const;
    int getBonuses() const;

    vector<OrderPosition> getEatList() const;
    void addEat(OrderPosition eat);
    void clearOrder();

    string getAdress() const;
    void setAdress(const string& adress);

    bool isDone()const;
    void setIsDone(bool done);

    bool isDelievered() const;
    void setIsDelievered(bool delievered);

    int getID() const;
    void setID(int id);

private:
    vector<OrderPosition> eatList;
    string adress;
    bool done;
    bool delievered;
    int id;
};