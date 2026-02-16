#pragma once

#include "Artwork.h"
#include <string>
#include <vector>

class MixedMedia : public Artwork {
private:
    std::vector<std::string> mediaTypes;

public:
    MixedMedia() = default;
    MixedMedia(const std::string& title, int year, Artist* artist);
    ~MixedMedia() = default;
    
    void addMediaType(const std::string& type);
    std::vector<std::string> getMediaTypes() const;
};

