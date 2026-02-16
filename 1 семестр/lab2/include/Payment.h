#pragma once
#include <string>
#include <ctime>
using namespace std;
class Payment {
public:
    Payment();
    Payment(double amount, const string& method, const string& currency);

    double getAmount() const;
    void setAmount(double amount);

    string getMethod() const;
    void setMethod(const string& method);
    
    string getCurrency() const;
    time_t getTime() const;
    void setCurrency(const string& currency);

    bool isConfirmed() const;
    void confirm();

private:
    double amount;
    string method;     
    string currency;   
    time_t times;
    bool confirmed;
};