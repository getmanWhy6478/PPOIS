#pragma once
#include <string>
#include <ctime>
using namespace std;
class Bonus {
public:
    Bonus();
    Bonus(const string& name, double discountPercent, time_t expirationTime, bool isActive = true);

    string getName() const;
    void setName(const string& name);

    double getDiscount() const;
    void setDiscount(double discount);

    time_t getExpirationTime() const;
    void setExpirationTime(time_t time);

    bool isExpired() const;
    bool operator==(const Bonus& other) const;
    

private:
    string name;
    double discount;
    time_t expirationTime;
};
