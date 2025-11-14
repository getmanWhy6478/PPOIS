#pragma once
#include <string>
using namespace std;
class User{
public:
    User();
    User(const string& name, int age, const string& email, bool banned);
    string getName() const;
    void setName(const string& name);

    int getAge() const;
    void setAge(int age);

    string getEmail() const;
    void setEmail(const string& email);

    bool getBanned();
    void setBanned(bool banned);
protected:
    string name;
    int age;
    string email;
    bool banned;  
};