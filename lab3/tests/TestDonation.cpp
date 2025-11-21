#include "UnitTest++/UnitTest++.h"
#include "../include/Donation.h"
#include "../include/Collector.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"

SUITE(DonationTests) {
    TEST(DonationConstructor) {
        Collector* donor = new Collector("John", "Patron");
        Donation* donation = new Donation("DON001", donor, "Metropolitan Museum");
        
        CHECK_EQUAL("DON001", donation->getDonationId());
        CHECK(donation->getDonor() == donor);
        CHECK_EQUAL("Metropolitan Museum", donation->getRecipientInstitution());
        
        delete donation;
        delete donor;
    }
    
    TEST(DonationProperties) {
        Collector* donor = new Collector("Jane", "Benefactor");
        Donation* donation = new Donation("DON002", donor, "MoMA");
        
        donation->setEstimatedValue(1000000.0);
        
        CHECK_CLOSE(1000000.0, donation->getEstimatedValue(), 0.01);
        
        delete donation;
        delete donor;
    }
    
    TEST(DonationAddArtwork) {
        Collector* donor = new Collector("Bob", "Collector");
        Donation* donation = new Donation("DON003", donor, "Tate");
        Artist* artist = new Artist("Test", "Artist", "Unknown", 1900);
        Artwork* artwork = new Painting("Donated Work", 2000, artist);
        
        artwork->setEstimatedValue(50000.0);
        donation->addDonatedArtwork(artwork);
        
        std::vector<Artwork*> artworks = donation->getDonatedArtworks();
        CHECK_EQUAL(1, artworks.size());
        CHECK_CLOSE(50000.0, donation->getEstimatedValue(), 0.01);
        
        delete donation;
        delete artwork;
        delete artist;
        delete donor;
    }
}

