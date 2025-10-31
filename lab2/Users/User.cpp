#include "User.h"

User::User()
    : name(""), age(0), email("") {}

User::User(const string& name, int age, const string& email)
    : name(name), age(age), email(email) {}

string User::getName() const {
    return name;
}

int User::getAge() const{
    return age;
}

string User::getEmail() const{
    return email;
}

void User::setName(const string& name) {
    this->name = name;
}

void User::setAge(int age) {
    this->age = age;
}

void User::setEmail(const string& email) {
    this->email = email;
}
