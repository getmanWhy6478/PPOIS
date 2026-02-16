#pragma once
#include <string>
using namespace std;
class KitchenAppliance {
public:
    KitchenAppliance();
    KitchenAppliance(const string& name, bool isElectric, bool isAvailable = true);

    string getName() const;
    void setName(const string& name);

    bool getIsElectric() const;
    void setIsElectric(bool isElectric);
    
    bool getIsAvailable() const;
    void setIsAvailable(bool isAvailable);

private:
    string name;
    bool isElectric;
    bool isAvailable;
};
