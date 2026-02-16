#include "../include/Worker.h"

Worker::Worker() : name(""), salary(0) {}

Worker::Worker(const string& name, int salary)
    : name(name), salary(salary){}

int Worker::getSalary() const {
    return salary;
}

void Worker::setSalary(int salary) {
    this->salary = salary;
}

string Worker::getName() const{
    return name;
}

void Worker::setName(const string& name) {
    this->name = name;
}
bool Worker:: operator==(const Worker& other) const {
    return this->getName() == other.getName() &&
           this->getSalary() == other.getSalary();
}