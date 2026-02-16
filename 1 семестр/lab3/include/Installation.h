#pragma once

#include "Artwork.h"
#include <string>
#include <vector>

class Artwork;

class Installation : public Artwork {
private:
    std::vector<Artwork*> components;
    std::string spaceRequirements;
    std::string setupInstructions;

public:
    Installation() = default;
    Installation(const std::string& title, int year, Artist* artist);
    ~Installation() = default;
    
    void addComponent(Artwork* component);
    std::vector<Artwork*> getComponents() const;
    std::string getSpaceRequirements() const;
    void setSpaceRequirements(const std::string& requirements);
    std::string getSetupInstructions() const;
    void setSetupInstructions(const std::string& instructions);
};

