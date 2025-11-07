#pragma once
#include <string>
using namespace std;
class Eatable{
public:
    Eatable(); 
    Eatable(const string& name, double cost, int cookingTime);
    Eatable(const Eatable& other);

    virtual double getCost() const;
    virtual void setCost(double cost);

    virtual string getName() const;
    virtual void setName(const string& name);

    int getTime() const;
    void setTime(int cookingTime);

    virtual ~Eatable();
    bool operator==(const Eatable& other);
protected:
    string name;
    double cost;
    int cookingTime;
};