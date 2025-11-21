#pragma once

#include <string>
#include "Artwork.h"

// Класс для оценки произведений
class Appraisal {
private:
    std::string appraisalId;
    Artwork* artwork;
    std::string appraiserName;
    int appraisalYear;
    double estimatedValue;
    double marketValue;
    double insuranceValue;

public:
    Appraisal() = default;
    Appraisal(const std::string& appraisalId, Artwork* artwork,
              const std::string& appraiserName);
    ~Appraisal() = default;
    
    std::string getAppraisalId() const;
    void setAppraisalId(const std::string& id);
    Artwork* getArtwork() const;
    void setArtwork(Artwork* artwork);
    std::string getAppraiserName() const;
    void setAppraiserName(const std::string& name);
    int getAppraisalYear() const;
    void setAppraisalYear(int year);
    double getEstimatedValue() const;
    void setEstimatedValue(double value);
    double getMarketValue() const;
    void setMarketValue(double value);
    double getInsuranceValue() const;
    void setInsuranceValue(double value);
};

