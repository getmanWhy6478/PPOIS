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
    void setAdress(const Adress& adress);

    Manager getManager() const;
    void setManager(const Manager& manager);

    DinningRoom getDinningRoom() const;
    void setDinningRoom(const DinningRoom& dinningRoom);

    Warehouse getWarehouse() const;
    void setWarehouse(const Warehouse& warehouse);

    Kitchen getKitchen() const;
    void setKitchen(const Kitchen& kitchen);

    vector<Cook> getCooks() const;
    void setCooks(const vector<Cook>& cooks);

    vector<Courier> getCouriers() const;
    void setCouriers(const vector<Courier>& couriers);

    vector <Order> getOrders() const;
    void setOrders(const vector <Order>& orders);

    vector<Rating> getRatings() const;

    Menu getMenu() const;
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
