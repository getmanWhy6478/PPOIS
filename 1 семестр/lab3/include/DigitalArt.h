#pragma once

#include "Artwork.h"
#include <string>

class DigitalArt : public Artwork {
private:
    std::string fileFormat;
    std::string displayType;
    int resolutionWidth;
    int resolutionHeight;
    bool isInteractive;

public:
    DigitalArt() = default;
    DigitalArt(const std::string& title, int year, Artist* artist);
    ~DigitalArt() = default;
    
    std::string getFileFormat() const;
    void setFileFormat(const std::string& format);
    std::string getDisplayType() const;
    void setDisplayType(const std::string& type);
    int getResolutionWidth() const;
    void setResolutionWidth(int width);
    int getResolutionHeight() const;
    void setResolutionHeight(int height);
    bool getIsInteractive() const;
    void setIsInteractive(bool interactive);
};

