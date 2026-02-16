#include "UnitTest++/UnitTest++.h"
#include "../include/Insurance.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"

SUITE(InsuranceTests) {
    TEST(InsuranceConstructor) {
        Insurance* insurance = new Insurance("POL001", "Art Insurance Co", 1000000.0);
        
        CHECK_EQUAL("POL001", insurance->getPolicyNumber());
        CHECK_EQUAL("Art Insurance Co", insurance->getInsuranceCompany());
        CHECK_CLOSE(1000000.0, insurance->getCoverageAmount(), 0.01);
        CHECK(insurance->getIsActive());
        
        delete insurance;
    }
    
    TEST(InsuranceExpired) {
        Insurance* insurance = new Insurance("POL002", "Insurer", 500000.0);
        
        insurance->setStartYear(2020);
        insurance->setEndYear(2021);
        insurance->setIsActive(true);
        
        delete insurance;
    }
    
    TEST(InsuranceAddArtwork) {
        Insurance* insurance = new Insurance("POL003", "Coverage Inc", 2000000.0);
        Artist* artist = new Artist("Test", "Artist", "Unknown", 1900);
        Artwork* artwork = new Painting("Insured Work", 2000, artist);
        
        insurance->addInsuredArtwork(artwork);
        std::vector<Artwork*> artworks = insurance->getInsuredArtworks();
        
        CHECK_EQUAL(1, artworks.size());
        
        delete insurance;
        delete artwork;
        delete artist;
    }
}

