#pragma once
#include <string>
using namespace std;
class Eatable{
public:
    Eatable(); 
    Eatable(const string& name, int cost, int calories);
    Eatable(const Eatable& other);
    int getCost();
    void setCost(int cost);
    string getName();
    void setName(const string& name);
    int getCalories();
    void setCalories(int calories);
protected:
    string name;
    int cost;
    int calories;
};