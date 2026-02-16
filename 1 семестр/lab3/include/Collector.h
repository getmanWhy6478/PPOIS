#pragma once

#include <string>
#include <vector>
#include "Collection.h"

class Artwork;

class Collector {
private:
    std::string firstName;
    std::string lastName;
    std::vector<Collection*> collections;
    int startYear;

public:
    Collector() = default;
    Collector(const std::string& firstName, const std::string& lastName);
    ~Collector() = default;
    
    std::string getFirstName() const;
    void setFirstName(const std::string& firstName);

    std::string getLastName() const;
    void setLastName(const std::string& lastName);

    std::string getFullName() const;

    void addCollection(Collection* collection);
    std::vector<Collection*> getCollections() const;
    
    int getStartYear() const;
    void setStartYear(int year);

    bool purchaseArtwork(Artwork* artwork, Collection* targetCollection, double purchasePrice);
};

