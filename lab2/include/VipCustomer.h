#pragma once
#include "Customer.h"
#include "Order.h"
#include "Order.h"
using namespace std;
class Vip_Customer : public Customer{
public:
    Vip_Customer();
    Vip_Customer(const string& name, int age, const string& email, int cash, 
        int vipDays, int vipCategory, Order order);
    
    void fastDelivery(Order order);
    
    int getVipDays() const;
    void setVipDays(int vipDays);

    int getVipCategory() const;
    void setVipCategory(int vipCategory);
private:
    int vipDays;
    int vipCategory;
};
