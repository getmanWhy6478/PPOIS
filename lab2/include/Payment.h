#pragma once
#include <string>
#include <ctime>
using namespace std;
class Payment {
public:
    Payment();
    Payment(double amount, const string& method, const string& currency);

    double getAmount() const;
    string getMethod() const;
    string getCurrency() const;
    time_t getTime() const;
    bool isConfirmed() const;

    void setAmount(double amount);
    void setMethod(const string& method);
    void setCurrency(const string& currency);
    void confirm();

private:
    double amount;
    string method;     
    string currency;   
    time_t times;
    bool confirmed;
};