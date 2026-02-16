#include "../include/Installation.h"
#include "../include/Artist.h"

Installation::Installation(const std::string& title, int year, Artist* artist)
    : Artwork(title, year, artist) {
}

void Installation::addComponent(Artwork* component) {
    components.push_back(component);
}

std::vector<Artwork*> Installation::getComponents() const {
    return components;
}

std::string Installation::getSpaceRequirements() const {
    return spaceRequirements;
}

void Installation::setSpaceRequirements(const std::string& requirements) {
    this->spaceRequirements = requirements;
}

std::string Installation::getSetupInstructions() const {
    return setupInstructions;
}

void Installation::setSetupInstructions(const std::string& instructions) {
    this->setupInstructions = instructions;
}

