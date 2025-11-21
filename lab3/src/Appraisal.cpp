#include "../include/Appraisal.h"
#include "../include/Artwork.h"

Appraisal::Appraisal(const std::string& appraisalId, Artwork* artwork,
                     const std::string& appraiserName)
    : appraisalId(appraisalId), artwork(artwork), appraiserName(appraiserName),
      estimatedValue(0.0), marketValue(0.0), insuranceValue(0.0),
      appraisalYear(0) {
}

std::string Appraisal::getAppraisalId() const {
    return appraisalId;
}

void Appraisal::setAppraisalId(const std::string& id) {
    this->appraisalId = id;
}

Artwork* Appraisal::getArtwork() const {
    return artwork;
}

void Appraisal::setArtwork(Artwork* artwork) {
    this->artwork = artwork;
}

std::string Appraisal::getAppraiserName() const {
    return appraiserName;
}

void Appraisal::setAppraiserName(const std::string& name) {
    this->appraiserName = name;
}
int Appraisal::getAppraisalYear() const {
    return appraisalYear;
}

void Appraisal::setAppraisalYear(int year) {
    this->appraisalYear = year;
}

double Appraisal::getEstimatedValue() const {
    return estimatedValue;
}

void Appraisal::setEstimatedValue(double value) {
    this->estimatedValue = value;
}

double Appraisal::getMarketValue() const {
    return marketValue;
}

void Appraisal::setMarketValue(double value) {
    this->marketValue = value;
}

double Appraisal::getInsuranceValue() const {
    return insuranceValue;
}

void Appraisal::setInsuranceValue(double value) {
    this->insuranceValue = value;
}


