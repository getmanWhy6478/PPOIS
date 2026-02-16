#include "../include/Insurance.h"
#include "../include/Artwork.h"
#include <ctime>

Insurance::Insurance(const std::string& policyNumber, const std::string& insuranceCompany,
                     double coverageAmount)
    : policyNumber(policyNumber), insuranceCompany(insuranceCompany),
      coverageAmount(coverageAmount), isActive(true) {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    startYear = now->tm_year + 1900;
    endYear = startYear + 1;
}

std::string Insurance::getPolicyNumber() const {
    return policyNumber;
}

void Insurance::setPolicyNumber(const std::string& number) {
    this->policyNumber = number;
}

std::string Insurance::getInsuranceCompany() const {
    return insuranceCompany;
}

void Insurance::setInsuranceCompany(const std::string& company) {
    this->insuranceCompany = company;
}

void Insurance::addInsuredArtwork(Artwork* artwork) {
    insuredArtworks.push_back(artwork);
}

std::vector<Artwork*> Insurance::getInsuredArtworks() const {
    return insuredArtworks;
}

double Insurance::getCoverageAmount() const {
    return coverageAmount;
}

void Insurance::setCoverageAmount(double amount) {
    this->coverageAmount = amount;
}

int Insurance::getStartYear() const {
    return startYear;
}

void Insurance::setStartYear(int year) {
    this->startYear = year;
}

int Insurance::getEndYear() const {
    return endYear;
}

void Insurance::setEndYear(int year) {
    this->endYear = year;
}

bool Insurance::getIsActive() const {
    return isActive;
}

void Insurance::setIsActive(bool active) {
    this->isActive = active;
}


