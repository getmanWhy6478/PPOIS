#pragma once

#include <string>
#include <vector>
#include "Artwork.h"
#include "Collector.h"

class Provenance {
private:
    Artwork* artwork;
    std::vector<Collector*> previousOwners;
    std::vector<int> ownershipYears;
    int acquisitionYear;
    double acquisitionPrice;
    std::string currentOwner;

public:
    Provenance() = default;
    Provenance(Artwork* artwork);
    ~Provenance() = default;
    
    Artwork* getArtwork() const;
    void setArtwork(Artwork* artwork);
    void addPreviousOwner(Collector* owner, int year);
    std::vector<Collector*> getPreviousOwners() const;
    std::vector<int> getOwnershipYears() const;
    int getAcquisitionYear() const;
    void setAcquisitionYear(int year);
    double getAcquisitionPrice() const;
    void setAcquisitionPrice(double price);
    std::string getCurrentOwner() const;
    void setCurrentOwner(const std::string& owner);
};

