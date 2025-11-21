#include "../include/VipCustomer.h"
#include <iostream>

Vip_Customer::Vip_Customer()
    : vipDays(0), vipCategory(0) {}

Vip_Customer::Vip_Customer(const string& name, int age, const string& email, int cash, 
    int vipDays, int vipCategory, Order order)
    : Customer(name, age, email, cash, order),
      vipDays(vipDays),
      vipCategory(vipCategory){}


int Vip_Customer::getVipDays() const {
    return vipDays;
}

int Vip_Customer::getVipCategory() const {
    return vipCategory;
}

void Vip_Customer::setVipDays(int days) {
    vipDays = days;
}

void Vip_Customer::setVipCategory(int category) {
    vipCategory = category;
}

void Vip_Customer::fastDelivery(Order order) {
    cout << "VIP клиент запросил быструю доставку заказа #" << order.getID() << endl;
}
