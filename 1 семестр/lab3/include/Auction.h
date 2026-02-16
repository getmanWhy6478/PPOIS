#pragma once

#include <string>
#include <vector>
#include "Artwork.h"
#include "Collector.h"

class Auction {
private:
    std::string auctionId;
    std::string auctionHouse;
    std::string location;
    std::vector<Artwork*> artworks;
    std::vector<Collector*> bidders;
    double totalRevenue;
    bool isCompleted;

public:
    Auction() = default;
    Auction(const std::string& auctionId, const std::string& auctionHouse,
            const std::string& location);
    ~Auction() = default;
    
    std::string getAuctionId() const;
    void setAuctionId(const std::string& id);
    std::string getAuctionHouse() const;
    void setAuctionHouse(const std::string& house);
    std::string getLocation() const;
    void setLocation(const std::string& location);
    void addArtwork(Artwork* artwork);
    std::vector<Artwork*> getArtworks() const;
    void addBidder(Collector* bidder);
    std::vector<Collector*> getBidders() const;
    double getTotalRevenue() const;
    bool getIsCompleted() const;
    void setIsCompleted(bool completed);
};

