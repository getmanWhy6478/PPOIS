#pragma once

#include <string>
#include <vector>
#include "Artwork.h"
#include "Artist.h"

class Archive {
private:
    std::string archiveId;
    std::string archiveName;
    std::string location;
    std::vector<Artwork*> archivedArtworks;
    std::vector<Artist*> archivedArtists;
    int establishedYear;
    int totalItems;

public:
    Archive() = default;
    Archive(const std::string& archiveId, const std::string& archiveName,
            const std::string& location);
    ~Archive() = default;
    
    std::string getArchiveId() const;
    void setArchiveId(const std::string& id);
    std::string getArchiveName() const;
    void setArchiveName(const std::string& name);
    std::string getLocation() const;
    void setLocation(const std::string& location);
    void addArchivedArtwork(Artwork* artwork);
    std::vector<Artwork*> getArchivedArtworks() const;
    void addArchivedArtist(Artist* artist);
    std::vector<Artist*> getArchivedArtists() const;
    int getEstablishedYear() const;
    void setEstablishedYear(int year);
    int getTotalItems() const;
    void setTotalItems(int items);
};

