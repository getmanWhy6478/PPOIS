#include "../include/Restorer.h"
#include "../include/Restoration.h"
#include <ctime>

Restorer::Restorer(const std::string& firstName, const std::string& lastName,
                   const std::string& employeeId, Gallery* gallery)
    : Employee(firstName, lastName, employeeId, gallery) {
}

std::string Restorer::getPosition() const {
    return "Restorer";
}

std::string Restorer::getSpecialization() const {
    return specialization;
}

void Restorer::setSpecialization(const std::string& specialization) {
    this->specialization = specialization;
}

std::string Restorer::getEducation() const {
    return education;
}

void Restorer::setEducation(const std::string& education) {
    this->education = education;
}

void Restorer::addRestoration(Restoration* restoration) {
    restorations.push_back(restoration);
}

std::vector<Restoration*> Restorer::getRestorations() const {
    return restorations;
}

Restoration* Restorer::startRestoration(const std::string& restorationId,
                                        Artwork* artwork,
                                        const std::string& conditionBefore) {
    if (restorationId.empty() || !artwork) {
        return nullptr;
    }

    Restoration* restoration = new Restoration(restorationId, artwork, this);
    restoration->setConditionBefore(conditionBefore);
    restoration->setStatus("in progress");

    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    restoration->setStartYear(now->tm_year + 1900);

    restorations.push_back(restoration);
    return restoration;
}
void Restorer::endRestoration(Restoration* restoration, const std::string& conditionAfter) {
    restoration->setConditionAfter(conditionAfter);
    restoration->setStatus("ended");
}

