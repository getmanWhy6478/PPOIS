#pragma once
#include "Customer.h"
#include "Order.h"
class Vip_Customer : public Customer{
public:
    void suggestFood(Eatable* eat);
    void fastDelivery(Order order);
    int getVipDays();
    void setVipDays(int vipDays);
    int getVipCategory();
    void setVipCategory(int vipCategory);
private:
    int vipDays;
    int vipCategory;
};