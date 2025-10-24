#include "Worker.h"

Worker::Worker() : name(""), salary(0), restaurant(nullptr) {}

Worker::Worker(const string& name, int salary, int ID, Restaurant* restaurant)
    : name(name), salary(salary), restaurant(restaurant) {}

Worker::Worker(const Worker& other)
    : name(other.name), salary(other.salary),restaurant(other.restaurant) {}

Restaurant* Worker::getRestaurant() {
    return this->restaurant;
}

void Worker::setRestaurant(Restaurant* restaurant) {
    this->restaurant = restaurant;
}

int Worker::getSalary() {
    return salary;
}

void Worker::setSalary(int salary) {
    this->salary = salary;
}

string Worker::getName() {
    return name;
}

void Worker::setName(const string& name) {
    this->name = name;
}
