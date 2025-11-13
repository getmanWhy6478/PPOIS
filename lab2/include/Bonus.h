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

    double getDiscountPercent() const;
    void setDiscountPercent(double percent);

    time_t getExpirationTime() const;
    void setExpirationTime(time_t time);
    
    double applyTo(double originalPrice) const;

    bool isExpired() const;

private:
    string name;
    double discountPercent;
    time_t expirationTime;
};
