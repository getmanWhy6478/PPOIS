#include "../include/Workshop.h"
#include "../include/Gallery.h"

Workshop::Workshop(const std::string& eventId, const std::string& title,
                   Gallery* gallery, const std::string& instructorName)
    : Event(eventId, title, gallery), instructorName(instructorName),
    materialFee(0.0) {
}

std::string Workshop::getInstructorName() const {
    return instructorName;
}

void Workshop::setInstructorName(const std::string& name) {
    this->instructorName = name;
}

void Workshop::addMaterialNeeded(const std::string& material) {
    materialsNeeded.push_back(material);
}

std::vector<std::string> Workshop::getMaterialsNeeded() const {
    return materialsNeeded;
}

double Workshop::getMaterialFee() const {
    return materialFee;
}

void Workshop::setMaterialFee(double fee) {
    this->materialFee = fee;
}

