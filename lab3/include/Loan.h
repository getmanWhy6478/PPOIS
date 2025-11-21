#pragma once

#include <string>
#include <vector>
#include "Artwork.h"
#include "Gallery.h"

// Класс для займа произведений
class Loan {
private:
    std::string loanId;
    std::vector<Artwork*> artworks;
    Gallery* lenderGallery;
    Gallery* borrowerGallery;
    int startYear;
    int endYear;
    double insuranceAmount;
    std::string status;
    std::string transportMethod;

public:
    Loan() = default;
    Loan(const std::string& loanId, Gallery* lenderGallery,
         Gallery* borrowerGallery);
    ~Loan() = default;
    
    std::string getLoanId() const;
    void setLoanId(const std::string& id);
    void addArtwork(Artwork* artwork);
    std::vector<Artwork*> getArtworks() const;
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
    std::string getTransportMethod() const;
    void setTransportMethod(const std::string& method);
    bool isActive() const;
};

