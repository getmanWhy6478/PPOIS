#pragma once
#include <string>
#include <iostream>
using namespace std;
class Vehicle {
public:

    Vehicle();
    Vehicle(const string& model, int capacity);

    string getModel() const;
    void setModel(const string& model);
    int getCapacity() const;
    void setCapacity(int capacity);

    bool operator==(const Vehicle& other) const;
    friend ostream& operator<<(ostream& os, const Vehicle& vehicle);
protected:
    string model;
    int capacity;
};
