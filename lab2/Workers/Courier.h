#pragma once
#include <string>
#include "Worker.h"
#include "Rating.h"
using namespace std;

class Courier : public Worker {
public:
    Courier();
    Courier(const string& name, int age, const string& email, const string& phoneNumber);

    string getPhoneNumber() const;

    void setPhoneNumber(const string& phoneNumber);

private:
    string phoneNumber;
    vector<Rating> ratings;
friend class Customer;
};
