#include "UnitTest++/UnitTest++.h"
#include "../include/Appraisal.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"

SUITE(AppraisalTests) {
    TEST(AppraisalConstructor) {
        Artist* artist = new Artist("Test", "Artist", "Unknown", 1900);
        Artwork* artwork = new Painting("Appraised Work", 2000, artist);
        Appraisal* appraisal = new Appraisal("APP001", artwork, "Expert Appraiser");
        
        CHECK_EQUAL("APP001", appraisal->getAppraisalId());
        CHECK(appraisal->getArtwork() == artwork);
        CHECK_EQUAL("Expert Appraiser", appraisal->getAppraiserName());
        
        delete appraisal;
        delete artwork;
        delete artist;
    }
    
    TEST(AppraisalValues) {
        Artist* artist = new Artist("Test", "Artist", "Unknown", 1800);
        Artwork* artwork = new Painting("Valuable Work", 1850, artist);
        Appraisal* appraisal = new Appraisal("APP002", artwork, "Certified Appraiser");
        
        appraisal->setEstimatedValue(1000000.0);
        appraisal->setMarketValue(1200000.0);
        appraisal->setAppraisalYear(2024);
        appraisal->setAppraiserName("John");
        appraisal->setArtwork(artwork);
        appraisal->setInsuranceValue(0);
        
        CHECK_CLOSE(1000000.0, appraisal->getEstimatedValue(), 0.01);
        CHECK_CLOSE(1200000.0, appraisal->getMarketValue(), 0.01);
        CHECK_CLOSE(0, appraisal->getInsuranceValue(), 0.01);
        CHECK_EQUAL(2024, appraisal->getAppraisalYear());
        CHECK_EQUAL("John", appraisal->getAppraiserName());

        
        delete appraisal;
        delete artwork;
        delete artist;
    }
}

