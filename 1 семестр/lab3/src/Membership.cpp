#include "../include/Membership.h"
#include "../include/Visitor.h"
#include <ctime>

Membership::Membership(const std::string& membershipNumber, Visitor* member,
                       const std::string& membershipType)
    : membershipNumber(membershipNumber), member(member), membershipType(membershipType),
      annualFee(0.0), isActive(true), discountPercentage(0) {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    startYear = now->tm_year + 1900;
    endYear = startYear + 1;
}

std::string Membership::getMembershipNumber() const {
    return membershipNumber;
}

void Membership::setMembershipNumber(const std::string& number) {
    this->membershipNumber = number;
}

Visitor* Membership::getMember() const {
    return member;
}

void Membership::setMember(Visitor* member) {
    this->member = member;
}

std::string Membership::getMembershipType() const {
    return membershipType;
}

void Membership::setMembershipType(const std::string& type) {
    this->membershipType = type;
}

int Membership::getStartYear() const {
    return startYear;
}

void Membership::setStartYear(int year) {
    this->startYear = year;
}

int Membership::getEndYear() const {
    return endYear;
}

void Membership::setEndYear(int year) {
    this->endYear = year;
}

double Membership::getAnnualFee() const {
    return annualFee;
}

void Membership::setAnnualFee(double fee) {
    this->annualFee = fee;
}

void Membership::addBenefit(const std::string& benefit) {
    benefits.push_back(benefit);
}

std::vector<std::string> Membership::getBenefits() const {
    return benefits;
}

bool Membership::getIsActive() const {
    return isActive;
}

void Membership::setIsActive(bool active) {
    this->isActive = active;
}

bool Membership::isExpired() const {
    if (!isActive) return true;
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    int currentYear = now->tm_year + 1900;
    return currentYear > endYear;
}

int Membership::getDiscountPercentage() const {
    return discountPercentage;
}

void Membership::setDiscountPercentage(int discount) {
    this->discountPercentage = discount;
}

