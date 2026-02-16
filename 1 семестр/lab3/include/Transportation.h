#pragma once

#include <string>
#include <vector>
#include "Artwork.h"

class Transportation {
private:
    std::string shipmentNumber;
    std::vector<Artwork*> artworks;
    std::string origin;
    std::string destination;
    double cost;
    std::string status;

public:
    Transportation() = default;
    Transportation(const std::string& shipmentNumber, const std::string& origin,
                   const std::string& destination);
    ~Transportation() = default;
    
    std::string getShipmentNumber() const;
    void setShipmentNumber(const std::string& number);
    void addArtwork(Artwork* artwork);
    std::vector<Artwork*> getArtworks() const;
    std::string getOrigin() const;
    void setOrigin(const std::string& origin);
    std::string getDestination() const;
    void setDestination(const std::string& destination);
    double getCost() const;
    void setCost(double cost);
    std::string getStatus() const;
    void setStatus(const std::string& status);
};

