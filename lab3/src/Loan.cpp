#include "../include/Loan.h"
#include "../include/Artwork.h"
#include "../include/Gallery.h"
#include <ctime>

Loan::Loan(const std::string& loanId, Gallery* lenderGallery,
           Gallery* borrowerGallery)
    : loanId(loanId), lenderGallery(lenderGallery), borrowerGallery(borrowerGallery),
      insuranceAmount(0.0), status("requested"), startYear(0), endYear(0) {
}

std::string Loan::getLoanId() const {
    return loanId;
}

void Loan::setLoanId(const std::string& id) {
    this->loanId = id;
}

void Loan::addArtwork(Artwork* artwork) {
    artworks.push_back(artwork);
}

std::vector<Artwork*> Loan::getArtworks() const {
    return artworks;
}

Gallery* Loan::getLenderGallery() const {
    return lenderGallery;
}

void Loan::setLenderGallery(Gallery* gallery) {
    this->lenderGallery = gallery;
}

Gallery* Loan::getBorrowerGallery() const {
    return borrowerGallery;
}

void Loan::setBorrowerGallery(Gallery* gallery) {
    this->borrowerGallery = gallery;
}

int Loan::getStartYear() const {
    return startYear;
}

void Loan::setStartYear(int year) {
    this->startYear = year;
}

int Loan::getEndYear() const {
    return endYear;
}

void Loan::setEndYear(int year) {
    this->endYear = year;
}

double Loan::getInsuranceAmount() const {
    return insuranceAmount;
}

void Loan::setInsuranceAmount(double amount) {
    this->insuranceAmount = amount;
}

std::string Loan::getStatus() const {
    return status;
}

void Loan::setStatus(const std::string& status) {
    this->status = status;
}

std::string Loan::getTransportMethod() const {
    return transportMethod;
}

void Loan::setTransportMethod(const std::string& method) {
    this->transportMethod = method;
}

bool Loan::isActive() const {
    if (status != "active") return false;
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    int currentYear = now->tm_year + 1900;
    return currentYear >= startYear && currentYear <= endYear;
}


