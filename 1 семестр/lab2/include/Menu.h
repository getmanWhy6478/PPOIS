#pragma once
#include <vector>
#include <string>
#include "Eatable.h" 
using namespace std;
class Menu {
public:

    Menu();
    Menu(const vector<Eatable>& items);

    void addItem(Eatable item);
    void removeItemByName(const string& name);
    Eatable findItemByName(const string& name);
    vector<Eatable> getItems() const;
    void clear();

private:
    vector<Eatable> items;
friend class Manager;
};
