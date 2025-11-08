#pragma once
#include <string>
#include <vector>
#include <Eatable.h>
using namespace std;
class ComboMeal {
private:
    string name;
    vector<Eatable> includedItems;
    double price;
    bool available;

public:
    ComboMeal(const string& name, const vector<Eatable>& items, double price);

    const string& getName() const;
    const vector<Eatable>& getIncludedItems() const;
    double getPrice() const;
    bool isAvailable() const;

    void setName(const string& name);
    void setPrice(double price);
    void setAvailability(bool available);

    void addItem(const Eatable& item);
    void removeItem(const Eatable& item);
    void clearItems();
};
