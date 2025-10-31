#pragma once
#include <string>
using namespace std;
class Vehicle {
public:
    // Конструкторы
    Vehicle();
    Vehicle(const string& type, const string& model, const string& licensePlate, int capacity);

    // Геттеры
    string getType() const;
    string getModel() const;
    string getLicensePlate() const;
    int getCapacity() const;

    // Сеттеры
    void setType(const string& type);
    void setModel(const string& model);
    void setLicensePlate(const string& licensePlate);
    void setCapacity(int capacity);

private:
    string type;
    string model;
    string licensePlate;
    int capacity;
};
