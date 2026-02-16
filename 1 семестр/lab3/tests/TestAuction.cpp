#include "UnitTest++/UnitTest++.h"
#include "../include/Auction.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"
#include "../include/Collector.h"
#include <string>
SUITE(AuctionTests) {
    TEST(AuctionConstructor) {
        Auction* auction = new Auction("AUC001", "Sotheby's", "New York");
        
        CHECK_EQUAL("AUC001", auction->getAuctionId());
        CHECK_EQUAL("Sotheby's", auction->getAuctionHouse());
        CHECK_EQUAL("New York", auction->getLocation());
        CHECK(auction->getIsCompleted() == false);
        
        delete auction;
    }
    
    TEST(AuctionProperties) {
        Auction* auction = new Auction("AUC002", "Christie's", "London");    
        CHECK_CLOSE(0, auction->getTotalRevenue(), 0.01);
        
        delete auction;
    }
    
    TEST(AuctionAddArtwork) {
        Auction* auction = new Auction("AUC003", "Bonhams", "Paris");
        Artist* artist = new Artist("Test", "Artist", "Unknown", 1900);
        Artwork* artwork = new Painting("Auction Piece", 2000, artist);
        auction->setIsCompleted(false);
        auction->setAuctionHouse("My home");
        auction->setLocation("Smolevichi");

        
        auction->addArtwork(artwork);
        std::vector<Artwork*> artworks = auction->getArtworks();
        
        CHECK_EQUAL(1, artworks.size());
        
        delete auction;
        delete artwork;
        delete artist;
    }
    
}

