#include "../include/DinningRoom.h"

DinningRoom::DinningRoom()
    : Place(), requirement(), tables(0), isOpen(true) {}

DinningRoom::DinningRoom(int area, DinningRoomRequirement requirement, int tables, bool isOpen)
    : Place(area), requirement(requirement), tables(tables), isOpen(isOpen) {}

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