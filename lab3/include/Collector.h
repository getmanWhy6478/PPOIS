#pragma once

#include <string>
#include <vector>
#include "Collection.h"

class Artwork;

class Collector {
private:
    std::string firstName;
    std::string lastName;
    std::string phone;
    std::vector<Collection*> collections;
    std::string collectingFocus;
    int startYear;
    bool isPrivateCollector;

public:
    Collector() = default;
    Collector(const std::string& firstName, const std::string& lastName);
    ~Collector() = default;
    
    std::string getFirstName() const;
    void setFirstName(const std::string& firstName);

    std::string getLastName() const;
    void setLastName(const std::string& lastName);

    std::string getFullName() const;

    std::string getPhone() const;
    void setPhone(const std::string& phone);

    void addCollection(Collection* collection);
    std::vector<Collection*> getCollections() const;

    std::string getCollectingFocus() const;
    void setCollectingFocus(const std::string& focus);
    
    int getStartYear() const;
    void setStartYear(int year);

    bool getIsPrivateCollector() const;
    void setIsPrivateCollector(bool isPrivate);

    bool purchaseArtwork(Artwork* artwork, Collection* targetCollection, double purchasePrice);
};

