#include "../include/Curator.h"
#include "../include/Exhibition.h"
#include <algorithm>

Curator::Curator(const std::string& firstName, const std::string& lastName,
                 const std::string& employeeId, Gallery* gallery)
    : Employee(firstName, lastName, employeeId, gallery) {
}

std::string Curator::getPosition() const {
    return "Curator";
}

std::string Curator::getSpecialization() const {
    return specialization;
}

void Curator::setSpecialization(const std::string& specialization) {
    this->specialization = specialization;
}

std::string Curator::getEducation() const {
    return education;
}

void Curator::setEducation(const std::string& education) {
    this->education = education;
}

void Curator::addExhibition(Exhibition* exhibition) {
    exhibitions.push_back(exhibition);
}

std::vector<Exhibition*> Curator::getExhibitions() const {
    return exhibitions;
}

bool Curator::curateExhibition(Exhibition* exhibition, const std::string& theme,
                               double admissionPrice) {
    if (!exhibition) {
        return false;
    }

    if (std::find(exhibitions.begin(), exhibitions.end(), exhibition) == exhibitions.end()) {
        exhibitions.push_back(exhibition);
    }

    exhibition->setCurator(this);
    if (!theme.empty()) {
        exhibition->setTheme(theme);
    }
    if (admissionPrice >= 0.0) {
        exhibition->setAdmissionPrice(admissionPrice);
    }

    return true;
}

