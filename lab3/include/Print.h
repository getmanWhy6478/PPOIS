#pragma once

#include "Artwork.h"
#include <string>

class Print : public Artwork {
private:
    std::string printType;
    int editionNumber;
    std::string paperType;
    bool isSigned;
    bool isNumbered;

public:
    Print() = default;
    Print(const std::string& title, int year, Artist* artist);
    ~Print() = default;
    
    std::string getType() const override;
    std::string getPrintType() const;
    void setPrintType(const std::string& type);
    int getEditionNumber() const;
    std::string getPaperType() const;
    void setPaperType(const std::string& type);
    bool getIsSigned() const;
    void setIsSigned(bool issigned);
    bool getIsNumbered() const;
    void setIsNumbered(bool numbered);
};

