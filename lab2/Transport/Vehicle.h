#pragma once
#include <string>
using namespace std;
class Vehicle {
public:

    Vehicle();
    Vehicle(const string& model, int capacity);

    string getModel() const;
    int getCapacity() const;

    void setModel(const string& model);
    void setCapacity(int capacity);

protected:
    string model;
    int capacity;
};
