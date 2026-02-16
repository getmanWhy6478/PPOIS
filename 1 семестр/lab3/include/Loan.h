#pragma once

#include <string>
#include <vector>
#include "Collection.h"
#include "Gallery.h"

class Loan {
private:
    std::string loanId;
    std::vector<Collection*> collections;
    Gallery* lenderGallery;
    Gallery* borrowerGallery;
    int startYear;
    int endYear;
    double insuranceAmount;
    std::string status;

public:
    Loan() = default;
    Loan(const std::string& loanId, Gallery* lenderGallery,
         Gallery* borrowerGallery);
    ~Loan() = default;
    
    std::string getLoanId() const;
    void setLoanId(const std::string& id);
    void addCollection(Collection* collection);
    std::vector<Collection*> getCollections() const;
    Gallery* getLenderGallery() const;
    void setLenderGallery(Gallery* gallery);
    Gallery* getBorrowerGallery() const;
    void setBorrowerGallery(Gallery* gallery);
    int getStartYear() const;
    void setStartYear(int year);
    int getEndYear() const;
    void setEndYear(int year);
    double getInsuranceAmount() const;
    void setInsuranceAmount(double amount);
    std::string getStatus() const;
    void setStatus(const std::string& status);
    bool isActive() const;
};

