#pragma once

#include <string>
#include "Artwork.h"

class Appraisal {
private:
    std::string appraisalId;
    Artwork* artwork;
    std::string appraiserName;
    int appraisalYear;
    double marketValue;

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
    double getMarketValue() const;
    void setMarketValue(double value);
};

