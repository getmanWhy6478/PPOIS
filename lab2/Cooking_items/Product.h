#pragma once
#include <string>
using namespace std;
class Product{
public:
    Product();
    Product(string name, int calories, int amount);
    Product(const Product& other);

    int getCalories();
    void setCalories(int calories);

    string getName();
    void setName(const string& name);

private:
    string name;
    int calories;
};