#pragma once

#include "Employee.h"
#include <string>
#include <vector>
#include "Room.h"

class Security : public Employee {
private:
    Room* assignedRoom;
    bool hasWeaponLicense;
    int incidentCount;
    std::vector<std::string> incidentReports;

public:
    Security() = default;
    Security(const std::string& firstName, const std::string& lastName,
             const std::string& employeeId, Gallery* gallery);
    ~Security() = default;
    
    std::string getPosition() const override;

    Room* getAssignedRoom() const;
    void setAssignedRoom(Room* room);

    bool getHasWeaponLicense() const;
    void setHasWeaponLicense(bool has);
    
    int getIncidentCount() const;
    void incrementIncidentCount();

    void reportIncident(const std::string& description, Room* roomInvolved = nullptr);
    const std::vector<std::string>& getIncidentReports() const;
};

