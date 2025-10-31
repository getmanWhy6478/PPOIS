#pragma once
#include <string>
using namespace std;
class Eatable{
public:
    Eatable(); 
    Eatable(const string& name, int cost, int cookingTime);
    Eatable(const Eatable& other);

    virtual int getCost() const;
    virtual void setCost(int cost);

    virtual string getName() const;
    virtual void setName(const string& name);

    int getTime() const;
    void setTime(int cookingTime);

    virtual ~Eatable();
protected:
    string name;
    int cost;
    int cookingTime;
};