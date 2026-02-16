#include "UnitTest++/UnitTest++.h"
#include "../include/Conservation.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"
#include "../include/Restorer.h"
#include "../include/Gallery.h"

SUITE(ConservationTests) {
    TEST(ConservationConstructor) {
        Gallery* gallery = new Gallery("Louvre", "Rue de Rivoli", "Paris", "France");
        Restorer* conservator = new Restorer("Pierre", "Martin", "CONS001", gallery);
        Artist* artist = new Artist("Test", "Artist", "Unknown", 1800);
        Artwork* artwork = new Painting("Valuable Work", 1850, artist);
        Conservation* conservation = new Conservation("CONS001", artwork, conservator);
        
        CHECK_EQUAL("CONS001", conservation->getConservationId());
        CHECK(conservation->getArtwork() == artwork);
        CHECK(conservation->getConservator() == conservator);
        CHECK_EQUAL("planned", conservation->getStatus());
        
        delete conservation;
        delete artwork;
        delete artist;
        delete conservator;
        delete gallery;
    }
    
    TEST(ConservationProperties) {
        Gallery* gallery = new Gallery("Met", "1000 5th Ave", "New York", "USA");
        Restorer* conservator = new Restorer("Anna", "White", "CONS002", gallery);
        Artist* artist = new Artist("Test", "Artist", "Unknown", 1700);
        Artwork* artwork = new Painting("Fragile Work", 1750, artist);
        Conservation* conservation = new Conservation("CONS002", artwork, conservator);
        
        conservation->setStartYear(2023);
        conservation->setCompletionYear(2024);
        conservation->setCost(30000.0);
        conservation->setStatus("completed");
        
        CHECK_EQUAL(2023, conservation->getStartYear());
        CHECK_EQUAL(2024, conservation->getCompletionYear());
        CHECK_CLOSE(30000.0, conservation->getCost(), 0.01);
        CHECK(conservation->isCompleted());
        
        delete conservation;
        delete artwork;
        delete artist;
        delete conservator;
        delete gallery;
    }
}

