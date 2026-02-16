#include "../include/Print.h"
#include "../include/Artist.h"

Print::Print(const std::string& title, int year, Artist* artist)
    : Artwork(title, year, artist), editionNumber(0),
      isSigned(false), isNumbered(false) {
}

std::string Print::getPrintType() const {
    return printType;
}

void Print::setPrintType(const std::string& type) {
    this->printType = type;
}

int Print::getEditionNumber() const {
    return editionNumber;
}

bool Print::getIsSigned() const {
    return isSigned;
}

void Print::setIsSigned(bool issigned) {
    this->isSigned = issigned;
}

bool Print::getIsNumbered() const {
    return isNumbered;
}

void Print::setIsNumbered(bool numbered) {
    this->isNumbered = numbered;
}

