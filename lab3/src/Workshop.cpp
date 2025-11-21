#include "../include/Workshop.h"
#include "../include/Gallery.h"

Workshop::Workshop(const std::string& eventId, const std::string& title,
                   Gallery* gallery, const std::string& instructorName)
    : Event(eventId, title, gallery), instructorName(instructorName),
      maxParticipants(0), materialFee(0.0) {
}

std::string Workshop::getInstructorName() const {
    return instructorName;
}

void Workshop::setInstructorName(const std::string& name) {
    this->instructorName = name;
}

std::string Workshop::getSkillLevel() const {
    return skillLevel;
}

void Workshop::setSkillLevel(const std::string& level) {
    this->skillLevel = level;
}

void Workshop::addMaterialProvided(const std::string& material) {
    materialsProvided.push_back(material);
}

std::vector<std::string> Workshop::getMaterialsProvided() const {
    return materialsProvided;
}

void Workshop::addMaterialNeeded(const std::string& material) {
    materialsNeeded.push_back(material);
}

std::vector<std::string> Workshop::getMaterialsNeeded() const {
    return materialsNeeded;
}

int Workshop::getMaxParticipants() const {
    return maxParticipants;
}

void Workshop::setMaxParticipants(int max) {
    this->maxParticipants = max;
}

double Workshop::getMaterialFee() const {
    return materialFee;
}

void Workshop::setMaterialFee(double fee) {
    this->materialFee = fee;
}

std::string Workshop::getWorkshopType() const {
    return workshopType;
}

void Workshop::setWorkshopType(const std::string& type) {
    this->workshopType = type;
}

