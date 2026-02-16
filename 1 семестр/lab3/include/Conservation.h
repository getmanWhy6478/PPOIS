#pragma once

#include <string>
#include <vector>
#include "Artwork.h"
#include "Restorer.h"

class Conservation {
private:
    std::string conservationId;
    Artwork* artwork;
    Restorer* conservator;
    int startYear;
    int completionYear;
    double cost;
    std::string status;

public:
    Conservation() = default;
    Conservation(const std::string& conservationId, Artwork* artwork,
                 Restorer* conservator);
    ~Conservation() = default;
    
    std::string getConservationId() const;
    void setConservationId(const std::string& id);
    Artwork* getArtwork() const;
    void setArtwork(Artwork* artwork);
    Restorer* getConservator() const;
    void setConservator(Restorer* conservator);
    int getStartYear() const;
    void setStartYear(int year);
    int getCompletionYear() const;
    void setCompletionYear(int year);
    double getCost() const;
    void setCost(double cost);
    std::string getStatus() const;
    void setStatus(const std::string& status);
    bool isCompleted() const;
};

