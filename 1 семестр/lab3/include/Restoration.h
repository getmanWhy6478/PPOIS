#pragma once

#include <string>
#include <vector>
#include "Artwork.h"
#include "Restorer.h"

class Restorer;
class Restoration {
private:
    std::string restorationId;
    Artwork* artwork;
    Restorer* restorer;
    int startYear;
    int completionYear;
    std::string conditionBefore;
    std::string conditionAfter;
    std::vector<std::string> techniquesUsed;
    double cost;
    std::string status; 

public:
    Restoration() = default;
    Restoration(const std::string& restorationId, Artwork* artwork,
                 Restorer* restorer);
    ~Restoration() = default;
    
    std::string getRestorationId() const;
    void setRestorationId(const std::string& id);
    Artwork* getArtwork() const;
    void setArtwork(Artwork* artwork);
    Restorer* getRestorer() const;
    void setRestorer(Restorer* restorer);
    int getStartYear() const;
    void setStartYear(int year);
    int getCompletionYear() const;
    void setCompletionYear(int year);
    std::string getConditionBefore() const;
    void setConditionBefore(const std::string& condition);
    std::string getConditionAfter() const;
    void setConditionAfter(const std::string& condition);
    void addTechnique(const std::string& technique);
    std::vector<std::string> getTechniquesUsed() const;
    double getCost() const;
    void setCost(double cost);
    std::string getStatus() const;
    void setStatus(const std::string& status);
    bool isCompleted() const;
};

