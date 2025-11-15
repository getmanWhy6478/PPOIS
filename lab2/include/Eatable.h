#pragma once
#include <string>
#include <ctime>
using namespace std;
class Eatable{
public:
    Eatable(); 
    Eatable(const string& name, double cost, int cookingTime, time_t exparationTime);

    double getCost() const;
    void setCost(double cost);

    string getName() const;
    void setName(const string& name);

    int getTime() const;
    void setTime(int cookingTime);

    time_t getExparationTime() const;
    void setExparationTime(time_t exparationTime);
    
    bool operator==(const Eatable& other);
protected:
    string name;
    double cost;
    int cookingTime;
    time_t exparationTime;
};