#pragma once

#include "Artwork.h"
#include <string>

class Painting : public Artwork {
private:
    std::string paintType;
    std::string canvasType;
    bool isFramed;

public:
    Painting() = default;
    Painting(const std::string& title, int year, Artist* artist);
    ~Painting() = default;
    
    std::string getPaintType() const;
    void setPaintType(const std::string& type);
    std::string getCanvasType() const;
    void setCanvasType(const std::string& type);
    bool getIsFramed() const;
    void setIsFramed(bool framed);
};

