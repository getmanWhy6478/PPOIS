#pragma once
#include <string>
#include <iostream>
#include "Worker.h"
#include "Rating.h"
using namespace std;
class Courier : public Worker {
public:
    Courier();
    Courier(const string& name, int salary, const string& phoneNumber);
    string getPhoneNumber() const;
    void setPhoneNumber(const string& phoneNumber);
    
    void textUser(const string& text);
    bool operator ==(const Courier& other) const;
    friend ostream& operator<<(ostream& os, const Courier&);
private:
    string phoneNumber;
};
