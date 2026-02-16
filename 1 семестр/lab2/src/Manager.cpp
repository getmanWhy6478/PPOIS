#include "../include/Manager.h"
#include <algorithm>
#include "../include/Errors.h"
#include "../include/Restaurant.h"
#include "../include/Courier.h"

Manager::Manager() : Worker() {}

Manager::Manager(const std::string& name, int salary) : Worker(name, salary) {}

void Manager::Hire(Courier& courier, Restaurant& restaurant) {
    if (restaurant.getManager() == *this) {
        restaurant.couriers.push_back(courier);
    }
    else{
        throw UnempolymentError();
    }
}
void Manager::Hire(Cook& cook, Restaurant& restaurant) {
    if (restaurant.getManager() == *this) {
        restaurant.cooks.push_back(cook);
    }
    else{
        throw UnempolymentError();
    }
}
void Manager::Fire(Courier& courier, Restaurant& restaurant) {
    if (restaurant.getManager() == *this) {
        for (auto i : restaurant.couriers)
            if (i == courier){
                auto begin = restaurant.couriers.begin();
                auto end = restaurant.couriers.end();
                auto newEnd = remove(begin, end, courier);
                restaurant.couriers.erase(newEnd, end);
            }
    }
    else{
        throw UnempolymentError();
    }
}
void Manager::Fire(Cook& cook, Restaurant& restaurant) {
    if (restaurant.getManager() == *this) {
        for (auto i : restaurant.cooks)
            if (i == cook){
                auto begin = restaurant.cooks.begin();
                auto end = restaurant.cooks.end();
                auto newEnd = remove(begin, end, cook);
                restaurant.cooks.erase(newEnd, end);
            }
    }
    else{
        throw UnempolymentError();
    }
}
void Manager::addEatable(Eatable& eat, Restaurant& restaurant) {
    if (restaurant.getManager() == *this) {
        restaurant.menu.addItem(eat);
    }
    else{
        throw UnempolymentError();
    }
}

void Manager::deleteEatable(Eatable& eat, Restaurant& restaurant) {
    if (restaurant.getManager() == *this) {
        for (auto i : restaurant.menu.items)
            if (i == eat){
                auto begin = restaurant.menu.items.begin();
                auto end = restaurant.menu.items.end();
                auto newEnd = remove(begin, end, eat);
                restaurant.menu.items.erase(newEnd, end);
            }
    }
    else{
        throw UnempolymentError();
    }
}
