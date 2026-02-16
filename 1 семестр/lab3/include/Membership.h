#pragma once

#include <string>
#include <vector>
#include "Visitor.h"

class Membership {
private:
    std::string membershipNumber;
    Visitor* member;
    std::string membershipType;
    int startYear;
    int endYear;
    double annualFee;
    std::vector<std::string> benefits;
    bool isActive;
    int discountPercentage;

public:
    Membership() = default;
    Membership(const std::string& membershipNumber, Visitor* member,
               const std::string& membershipType);
    ~Membership() = default;
    
    std::string getMembershipNumber() const;
    void setMembershipNumber(const std::string& number);
    Visitor* getMember() const;
    void setMember(Visitor* member);
    std::string getMembershipType() const;
    void setMembershipType(const std::string& type);
    int getStartYear() const;
    void setStartYear(int year);
    int getEndYear() const;
    void setEndYear(int year);
    double getAnnualFee() const;
    void setAnnualFee(double fee);
    void addBenefit(const std::string& benefit);
    std::vector<std::string> getBenefits() const;
    bool getIsActive() const;
    void setIsActive(bool active);
    bool isExpired() const;
    int getDiscountPercentage() const;
    void setDiscountPercentage(int discount);
};

