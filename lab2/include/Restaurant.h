#pragma once
#include <string>
#include <vector>
#include "Adress.h"
#include "Manager.h"
#include "Warehouse.h"
#include "Kitchen.h"
#include "DinningRoom.h"
#include "Cook.h"
#include "Courier.h"
#include "Menu.h"
#include "SupportAgent.h"
using namespace std;
class Restaurant {
public:
    Restaurant();
    Restaurant(const Adress& adress, const Manager& manager,
               const DinningRoom& dinningRoom, const Warehouse& warehouse, const Kitchen& kitchen);

    Adress getAdress() const;
    Manager getManager() const;
    DinningRoom getDinningRoom() const;
    Warehouse getWarehouse() const;
    Kitchen getKitchen() const;
    vector<Cook> getCooks() const;
    vector<Courier> getCouriers() const;
    vector <Order> getOrders() const;
    vector<Rating> getRatings() const;
    Menu getMenu() const;

    void setAdress(const Adress& adress);
    void setManager(const Manager& manager);
    void setDinningRoom(const DinningRoom& dinningRoom);
    void setWarehouse(const Warehouse& warehouse);
    void setKitchen(const Kitchen& kitchen);
    void setCooks(const vector<Cook>& cooks);
    void setCouriers(const vector<Courier>& couriers);
    void setOrders(const vector <Order>& orders);
    void setMenu(const Menu& menu);

    bool findCook(Cook cook) const;
    bool findCourier(Courier courier) const;

private:
    Adress adress;
    Manager manager;
    DinningRoom dinningRoom;
    Warehouse warehouse;
    Kitchen kitchen;
    vector<Cook> cooks;
    vector<Courier> couriers;
    vector <Order> orders;
    vector<Rating> ratings;
    Menu menu;
friend class Customer;
friend class NotAuthorisedCustomer;
friend class SupportAgent;
friend class Manager;
};
