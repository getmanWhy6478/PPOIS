#include "UnitTest++/UnitTest++.h"
#include "../include/MultimediaGuide.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"
#include "../include/Exhibition.h"
#include "../include/Gallery.h"

SUITE(MultimediaGuideTests) {
    TEST(MultimediaGuideConstructor) {
        MultimediaGuide* guide = new MultimediaGuide("MG001", "Audio Tour", "English");
        
        CHECK_EQUAL("MG001", guide->getGuideId());
        CHECK_EQUAL("Audio Tour", guide->getGuideName());
        CHECK_EQUAL("English", guide->getLanguage());
        CHECK(guide->getIsAvailable());
        CHECK_EQUAL(0, guide->getTotalRentals());
        
        delete guide;
    }
    
    TEST(MultimediaGuideProperties) {
        MultimediaGuide* guide = new MultimediaGuide("MG002", "Video Guide", "French");
        
        guide->setDurationMinutes(60);
        guide->setAverageRating(4.5);
        
        CHECK_EQUAL(60, guide->getDurationMinutes());
        CHECK_CLOSE(4.5, guide->getAverageRating(), 0.01);
        
        guide->incrementTotalRentals();
        CHECK_EQUAL(1, guide->getTotalRentals());
        
        delete guide;
    }
}

