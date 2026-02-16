#pragma once
#include <string>
using namespace std;
class Product{
public:
    Product();
    Product(string name, int calories);
    Product(const Product& other);

    int getCalories() const;
    void setCalories(int calories);

    string getName() const;
    void setName(const string& name);
    
    bool operator==(const Product& other) const;

private:
    string name;
    int calories;
};