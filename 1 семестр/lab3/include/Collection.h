#pragma once

#include <string>
#include <vector>
#include "Artwork.h"

class Collector;

class Collection {
private:
    std::string name;
    std::string description;
    Collector* collector;
    std::vector<Artwork*> artworks;
    int totalArtworks;
    double totalValue;

public:
    Collection() = default;
    Collection(const std::string& name, Collector* collector);
    ~Collection() = default;
    
    std::string getName() const;
    void setName(const std::string& name);
    std::string getDescription() const;
    void setDescription(const std::string& description);
    Collector* getCollector() const;
    void setCollector(Collector* collector);
    void addArtwork(Artwork* artwork);
    void removeArtwork(Artwork* artwork);
    std::vector<Artwork*> getArtworks() const;
    int getTotalArtworks() const;
    double getTotalValue() const;
    void updateStatistics();
    bool  operator==(const Collection& other) const;
};

