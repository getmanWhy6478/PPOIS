#include "../include/DigitalArt.h"
#include "../include/Artist.h"

DigitalArt::DigitalArt(const std::string& title, int year, Artist* artist)
    : Artwork(title, year, artist), resolutionWidth(0), resolutionHeight(0),
      isInteractive(false) {
}

std::string DigitalArt::getFileFormat() const {
    return fileFormat;
}

void DigitalArt::setFileFormat(const std::string& format) {
    this->fileFormat = format;
}

std::string DigitalArt::getDisplayType() const {
    return displayType;
}

void DigitalArt::setDisplayType(const std::string& type) {
    this->displayType = type;
}

int DigitalArt::getResolutionWidth() const {
    return resolutionWidth;
}

void DigitalArt::setResolutionWidth(int width) {
    this->resolutionWidth = width;
}

int DigitalArt::getResolutionHeight() const {
    return resolutionHeight;
}

void DigitalArt::setResolutionHeight(int height) {
    this->resolutionHeight = height;
}

bool DigitalArt::getIsInteractive() const {
    return isInteractive;
}

void DigitalArt::setIsInteractive(bool interactive) {
    this->isInteractive = interactive;
}

