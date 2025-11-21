#pragma once

#include "Event.h"
#include <string>
#include <vector>

// Класс для мастер-класса
class Workshop : public Event {
private:
    std::string instructorName;
    std::string skillLevel;
    std::vector<std::string> materialsProvided;
    std::vector<std::string> materialsNeeded;
    int maxParticipants;
    double materialFee;
    std::string workshopType;

public:
    Workshop() = default;
    Workshop(const std::string& eventId, const std::string& title,
             Gallery* gallery, const std::string& instructorName);
    ~Workshop() = default;
    
    std::string getInstructorName() const;
    void setInstructorName(const std::string& name);
    std::string getSkillLevel() const;
    void setSkillLevel(const std::string& level);
    void addMaterialProvided(const std::string& material);
    std::vector<std::string> getMaterialsProvided() const;
    void addMaterialNeeded(const std::string& material);
    std::vector<std::string> getMaterialsNeeded() const;
    int getMaxParticipants() const;
    void setMaxParticipants(int max);
    double getMaterialFee() const;
    void setMaterialFee(double fee);
    std::string getWorkshopType() const;
    void setWorkshopType(const std::string& type);
};

