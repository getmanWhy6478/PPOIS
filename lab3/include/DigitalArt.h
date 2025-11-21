#pragma once

#include "Artwork.h"
#include <string>

// Класс для цифрового искусства
class DigitalArt : public Artwork {
private:
    std::string software;
    std::string fileFormat;
    std::string displayType; // экран, проекция, печать
    int resolutionWidth;
    int resolutionHeight;
    bool isInteractive;

public:
    DigitalArt() = default;
    DigitalArt(const std::string& title, int year, Artist* artist);
    ~DigitalArt() = default;
    
    std::string getType() const override;
    std::string getSoftware() const;
    void setSoftware(const std::string& software);
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

