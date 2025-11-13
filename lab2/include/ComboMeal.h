#pragma once
#include <string>
#include <vector>
#include <Eatable.h>
using namespace std;
class ComboMeal {
public:
    ComboMeal();
    ComboMeal(const string& name, const vector<Eatable>& items, double price);

    const string& getName() const;
    void setName(const string& name);

    const vector<Eatable>& getIncludedItems() const;

    void setPrice(double price);
    double getPrice() const;

    bool isAvailable() const;
    void setAvailability(bool available);

    void addItem(const Eatable& item);
    void removeItem(const Eatable& item);
    void clearItems();
private:
    string name;
    vector<Eatable> includedItems;
    double price;
    bool available;
};
