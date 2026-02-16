#pragma once

#include "Artwork.h"
#include <string>

class Print : public Artwork {
private:
    std::string printType;
    int editionNumber;
    bool isSigned;
    bool isNumbered;

public:
    Print() = default;
    Print(const std::string& title, int year, Artist* artist);
    ~Print() = default;
    
    std::string getPrintType() const;
    void setPrintType(const std::string& type);
    int getEditionNumber() const;
    bool getIsSigned() const;
    void setIsSigned(bool issigned);
    bool getIsNumbered() const;
    void setIsNumbered(bool numbered);
};

