#pragma once
#include <string>
using namespace std;
class KitchenAppliance {
public:
    KitchenAppliance();
    KitchenAppliance(const string& name, bool isElectric, bool isAvailable = true);

    string getName() const;
    bool getIsElectric() const;
    bool getIsAvailable() const;

    void setName(const string& name);
    void setIsElectric(bool isElectric);
    void setIsAvailable(bool isAvailable);

private:
    string name;
    bool isElectric;
    bool isAvailable;
};
