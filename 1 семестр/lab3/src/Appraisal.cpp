#include "../include/Appraisal.h"
#include "../include/Artwork.h"

Appraisal::Appraisal(const std::string& appraisalId, Artwork* artwork,
                     const std::string& appraiserName)
    : appraisalId(appraisalId), artwork(artwork), appraiserName(appraiserName),
    marketValue(0.0),
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

double Appraisal::getMarketValue() const {
    return marketValue;
}

void Appraisal::setMarketValue(double value) {
    this->marketValue = value;
}



