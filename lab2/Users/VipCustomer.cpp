#include "VipCustomer.h"
#include <iostream>

// Конструктор по умолчанию
Vip_Customer::Vip_Customer()
    : vipDays(0), vipCategory(0) {}

Vip_Customer::Vip_Customer(const std::string& name, int age, const std::string& email, int cash, int bonusesAmount, int vipDays, int vipCategory)
    : Customer(name, age, email, cash, bonusesAmount),
      vipDays(vipDays),
      vipCategory(vipCategory){}


// Геттеры
int Vip_Customer::getVipDays() const {
    return vipDays;
}

int Vip_Customer::getVipCategory() const {
    return vipCategory;
}

// Сеттеры
void Vip_Customer::setVipDays(int days) {
    vipDays = days;
}

void Vip_Customer::setVipCategory(int category) {
    vipCategory = category;
}

void Vip_Customer::fastDelivery(Order order) {
    cout << "VIP клиент запросил быструю доставку заказа #" << order.getID() << endl;//добавить
}
