#pragma once
#include "Client.h"
#include "Order.h"
class Vip_Client : public Client{
public:
    void suggestFood(Eatable eat);
    void fastDelivery(Order order);
    int getVipDays();
    void setVipDays(int vip_days);
    int getVipCategory();
    void setVipCategory(int vip_category);
private:
    int vip_days;
    int vip_category;
};