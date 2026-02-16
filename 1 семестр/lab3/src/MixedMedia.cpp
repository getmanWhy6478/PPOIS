#include "../include/MixedMedia.h"
#include "../include/Artist.h"

MixedMedia::MixedMedia(const std::string& title, int year, Artist* artist)
    : Artwork(title, year, artist) {
}

void MixedMedia::addMediaType(const std::string& type) {
    mediaTypes.push_back(type);
}

std::vector<std::string> MixedMedia::getMediaTypes() const {
    return mediaTypes;
}
