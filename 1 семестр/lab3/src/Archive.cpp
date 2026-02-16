#include "../include/Archive.h"
#include "../include/Artwork.h"
#include "../include/Artist.h"
#include <ctime>

Archive::Archive(const std::string& archiveId, const std::string& archiveName,
                 const std::string& location)
    : archiveId(archiveId), archiveName(archiveName), location(location),
      totalItems(0), establishedYear(0) {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    establishedYear = now->tm_year + 1900;
}

std::string Archive::getArchiveId() const {
    return archiveId;
}

void Archive::setArchiveId(const std::string& id) {
    this->archiveId = id;
}

std::string Archive::getArchiveName() const {
    return archiveName;
}

void Archive::setArchiveName(const std::string& name) {
    this->archiveName = name;
}

std::string Archive::getLocation() const {
    return location;
}

void Archive::setLocation(const std::string& location) {
    this->location = location;
}

void Archive::addArchivedArtwork(Artwork* artwork) {
    archivedArtworks.push_back(artwork);
    totalItems = archivedArtworks.size() + archivedArtists.size();
}

std::vector<Artwork*> Archive::getArchivedArtworks() const {
    return archivedArtworks;
}

void Archive::addArchivedArtist(Artist* artist) {
    archivedArtists.push_back(artist);
    totalItems = archivedArtworks.size() + archivedArtists.size();
}

std::vector<Artist*> Archive::getArchivedArtists() const {
    return archivedArtists;
}

int Archive::getEstablishedYear() const {
    return establishedYear;
}

void Archive::setEstablishedYear(int year) {
    this->establishedYear = year;
}



int Archive::getTotalItems() const {
    return totalItems;
}

void Archive::setTotalItems(int items) {
    this->totalItems = items;
}

