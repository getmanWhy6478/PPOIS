#pragma once
#include <string>
using namespace std;
class Adress{
public:
    Adress();
    Adress(const string& city, const string& street, int house);

    string getCity();
    void setCity(const string& city);

    string getStreet();
    void setStreet(const string& street);

    int getHouse();
    void setHouse(int house);

private:
    string city;
    string street;
    int house;
};