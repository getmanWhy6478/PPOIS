#pragma once
#include <string>
#include <iostream>
#include "Worker.h"
#include "Rating.h"
#include "Customer.h"
using namespace std;
class Courier : public Worker {
public:
    Courier();
    Courier(const string& name, int age, const string& phoneNumber);
    string getPhoneNumber() const;
    void setPhoneNumber(const string& phoneNumber);
    void textUser(const string& text);
private:
    string phoneNumber;
};
