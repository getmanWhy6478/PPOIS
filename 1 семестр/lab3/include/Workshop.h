#pragma once

#include "Event.h"
#include <string>
#include <vector>

class Workshop : public Event {
private:
    std::string instructorName;
    std::vector<std::string> materialsNeeded;
    double materialFee;

public:
    Workshop() = default;
    Workshop(const std::string& eventId, const std::string& title,
             Gallery* gallery, const std::string& instructorName);
    ~Workshop() = default;
    
    std::string getInstructorName() const;
    void setInstructorName(const std::string& name);
    void addMaterialNeeded(const std::string& material);
    std::vector<std::string> getMaterialsNeeded() const;
    double getMaterialFee() const;
    void setMaterialFee(double fee);
};

