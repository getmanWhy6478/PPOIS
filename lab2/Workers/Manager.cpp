#include "Manager.h"
#include <algorithm>

void Manager::Hire(Courier& courier) {
    if (restaurant) {
        restaurant->couriers.push_back(courier);
        courier.setRestaurant(restaurant);
    }
}
void Manager::Hire(Cook& cook) {
    if (restaurant) {
        restaurant->cooks.push_back(cook);
        cook.setRestaurant(restaurant);
    }
}
void Manager::Fire(Courier& courier) {
    if (restaurant) {
        for (auto i : restaurant->couriers)
            if (i == courier){
                auto begin = restaurant->couriers.begin();
                auto end = restaurant->couriers.end();
                auto newEnd = remove(begin, end, courier);
                restaurant->couriers.erase(newEnd, end);
            }
            courier.setRestaurant(nullptr);
    }
}
void Manager::Fire(Cook& cook) {
    if (restaurant) {
        for (auto i : restaurant->cooks)
            if (i == cook){
                auto begin = restaurant->cooks.begin();
                auto end = restaurant->cooks.end();
                auto newEnd = remove(begin, end, cook);
                restaurant->cooks.erase(newEnd, end);
            }
            cook.setRestaurant(nullptr);
    }
}
void Manager::addEatable(Eatable& eat) {
    if (restaurant) {
        restaurant->menu.addItem(eat);
    }
}

void Manager::deleteEatable(Eatable& eat) {
    if (restaurant) {
        for (auto i : restaurant->menu.items)
            if (i == eat){
                auto begin = restaurant->cooks.begin();
                auto end = restaurant->cooks.end();
                auto newEnd = remove(begin, end, eat);
                restaurant->cooks.erase(newEnd, end);
            }
    }
}
