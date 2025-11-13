#pragma once
#include <string>
using namespace std;
class Eatable{
public:
    Eatable(); 
    Eatable(const string& name, double cost, int cookingTime);

    double getCost() const;
    void setCost(double cost);

    string getName() const;
    void setName(const string& name);

    int getTime() const;
    void setTime(int cookingTime);
    
    bool operator==(const Eatable& other);
protected:
    string name;
    double cost;
    int cookingTime;
};