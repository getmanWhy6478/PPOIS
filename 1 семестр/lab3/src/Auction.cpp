#include "../include/Auction.h"
#include "../include/Artwork.h"
#include "../include/Collector.h"

Auction::Auction(const std::string& auctionId, const std::string& auctionHouse,
                 const std::string& location)
    : auctionId(auctionId), auctionHouse(auctionHouse), location(location),
      totalRevenue(0.0), isCompleted(false) {
}

std::string Auction::getAuctionId() const {
    return auctionId;
}

void Auction::setAuctionId(const std::string& id) {
    this->auctionId = id;
}

std::string Auction::getAuctionHouse() const {
    return auctionHouse;
}

void Auction::setAuctionHouse(const std::string& house) {
    this->auctionHouse = house;
}

std::string Auction::getLocation() const {
    return location;
}

void Auction::setLocation(const std::string& location) {
    this->location = location;
}

void Auction::addArtwork(Artwork* artwork) {
    artworks.push_back(artwork);
}

std::vector<Artwork*> Auction::getArtworks() const {
    return artworks;
}

void Auction::addBidder(Collector* bidder) {
    bidders.push_back(bidder);
}

std::vector<Collector*> Auction::getBidders() const {
    return bidders;
}

double Auction::getTotalRevenue() const {
    return totalRevenue;
}


bool Auction::getIsCompleted() const {
    return isCompleted;
}

void Auction::setIsCompleted(bool completed) {
    this->isCompleted = completed;
}

