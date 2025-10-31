#include "DinningRoom.h"

DinningRoom::DinningRoom()
    : Place(), requirement(), isOpen(true) {}

DinningRoom::DinningRoom(int area, DinningRoomRequirement requirement, bool isOpen, int tables)
    : Place(area), requirement(requirement), isOpen(isOpen), tables(tables) {}

DinningRoomRequirement DinningRoom::getRequirement() const {
    return requirement;
}

bool DinningRoom::getIsOpen() const {
    return isOpen;
}
int DinningRoom::getTablesCount() const {
    return tables;
}

void DinningRoom::setRequirement(DinningRoomRequirement requirement) {
    this->requirement = requirement;
}

void DinningRoom::setIsOpen(bool open) {
    isOpen = open;
}
void DinningRoom::setTablesCount(int tables){
     this->tables = tables;
}