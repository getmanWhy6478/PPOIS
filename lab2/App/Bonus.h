#pragma once
#include <string>
#include <ctime>
using namespace std;
class Bonus {
public:
    Bonus();
    Bonus(const string& name, double discountPercent, time_t expirationTime, bool isActive = true);

    string getName() const;
    double getDiscountPercent() const;
    bool getIsActive() const;
    time_t getExpirationTime() const;

    void setName(const string& name);
    void setDiscountPercent(double percent);
    void setIsActive(bool active);
    void setExpirationTime(time_t time);

    double applyTo(double originalPrice) const;

    bool isExpired() const;

private:
    string name;
    double discountPercent;
    bool isActive;
    time_t expirationTime;
};
