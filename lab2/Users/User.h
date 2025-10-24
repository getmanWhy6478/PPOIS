#pragma once
#include <string>
using namespace std;
class User{
public:
    User();
    User(const string& name, int age, const string& email);
    string getName();
    void setName(const string& name);
    int getAge();
    void setAge(int age);
    string getEmail();
    void setEmail(const string& email);
protected:
    string name;
    int age;
    string email;  
};