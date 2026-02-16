#pragma once

#include <string>
#include <vector>
#include "Artwork.h"

class Insurance {
private:
    std::string policyNumber;
    std::string insuranceCompany;
    std::vector<Artwork*> insuredArtworks;
    double coverageAmount;
    int startYear;
    int endYear;
    bool isActive;

public:
    Insurance() = default;
    Insurance(const std::string& policyNumber, const std::string& insuranceCompany,
              double coverageAmount);
    ~Insurance() = default;
    
    std::string getPolicyNumber() const;
    void setPolicyNumber(const std::string& number);
    std::string getInsuranceCompany() const;
    void setInsuranceCompany(const std::string& company);
    void addInsuredArtwork(Artwork* artwork);
    std::vector<Artwork*> getInsuredArtworks() const;
    double getCoverageAmount() const;
    void setCoverageAmount(double amount);
    int getStartYear() const;
    void setStartYear(int year);
    int getEndYear() const;
    void setEndYear(int year);
    bool getIsActive() const;
    void setIsActive(bool active);
};

