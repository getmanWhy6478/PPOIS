#pragma once
#include "Place.h"
#include "DinningRoomRequirement.h"
class DinningRoom : public Place {
public:
    DinningRoom();
    DinningRoom(int area, DinningRoomRequirement requirement, bool isOpen = true, int tables);

    DinningRoomRequirement getRequirement() const;
    void setRequirement(DinningRoomRequirement requirement);

    int getTablesCount() const;
    void setTablesCount(int count);

    bool getIsOpen() const;
    void setIsOpen(bool open);

private:
    DinningRoomRequirement requirement; 
    bool isOpen; 
    int tables;
};
