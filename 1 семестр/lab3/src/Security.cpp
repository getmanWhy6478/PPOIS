#include "../include/Security.h"
#include "../include/Room.h"

Security::Security(const std::string& firstName, const std::string& lastName,
                   const std::string& employeeId, Gallery* gallery)
    : Employee(firstName, lastName, employeeId, gallery),
       assignedRoom(nullptr),hasWeaponLicense(false) {
}

std::string Security::getPosition() const {
    return "Security";
}

Room* Security::getAssignedRoom() const {
    return assignedRoom;
}

void Security::setAssignedRoom(Room* room) {
    this->assignedRoom = room;
}

bool Security::getHasWeaponLicense() const {
    return hasWeaponLicense;
}

void Security::setHasWeaponLicense(bool has) {
    this->hasWeaponLicense = has;
}

void Security::reportIncident(const std::string& description, Room* roomInvolved) {
    if (roomInvolved) {
        assignedRoom = roomInvolved;
    }

    if (description.empty()) {
        incidentReports.push_back("incident reported");
    } else {
    incidentReports.push_back(description);
    }
}

const std::vector<std::string>& Security::getIncidentReports() const {
    return incidentReports;
}

