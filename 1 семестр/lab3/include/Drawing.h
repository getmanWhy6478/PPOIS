#pragma once

#include "Artwork.h"
#include <string>

class Drawing : public Artwork {
private:
    std::string drawingMedium;
    std::string paperSize;
    bool isSigned;
    bool isDated;

public:
    Drawing() = default;
    Drawing(const std::string& title, int year, Artist* artist);
    ~Drawing() = default;
    
    std::string getDrawingMedium() const;
    void setDrawingMedium(const std::string& medium);
    std::string getPaperSize() const;
    void setPaperSize(const std::string& size);
    bool getIsSigned() const;
    void setIsSigned(bool issigned);
    bool getIsDated() const;
    void setIsDated(bool dated);
};

