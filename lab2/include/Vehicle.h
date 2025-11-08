#pragma once
#include <string>
#include <iostream>
using namespace std;
class Vehicle {
public:

    Vehicle();
    Vehicle(const string& model, int capacity);

    string getModel() const;
    int getCapacity() const;

    void setModel(const string& model);
    void setCapacity(int capacity);

    bool operator==(const Vehicle& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& v) {
        os << "Vehicle(model: " << v.model << ", capacity: " << v.capacity << ")";
        return os;
    }
protected:
    string model;
    int capacity;
};
