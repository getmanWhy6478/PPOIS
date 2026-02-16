#include "UnitTest++/UnitTest++.h"
#include "../include/Restoration.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"
#include "../include/Restorer.h"
#include "../include/Gallery.h"

SUITE(RestorationTests) {
    TEST(RestorationConstructor) {
        Gallery* gallery = new Gallery("Louvre", "Rue de Rivoli", "Paris", "France");
        Restorer* restorer = new Restorer("Marie", "Dupont", "REST001", gallery);
        Artist* artist = new Artist("Test", "Artist", "Unknown", 1800);
        Artwork* artwork = new Painting("Old Painting", 1850, artist);
        Restoration* restoration = new Restoration("REST001", artwork, restorer);
        
        CHECK_EQUAL("REST001", restoration->getRestorationId());
        CHECK(restoration->getArtwork() == artwork);
        CHECK(restoration->getRestorer() == restorer);
        CHECK_EQUAL("planned", restoration->getStatus());
        
        delete restoration;
        delete artwork;
        delete artist;
        delete restorer;
        delete gallery;
    }
    
    TEST(RestorationProperties) {
        Gallery* gallery = new Gallery("Met", "1000 5th Ave", "New York", "USA");
        Restorer* restorer = new Restorer("John", "Smith", "REST002", gallery);
        Artist* artist = new Artist("Test", "Artist", "Unknown", 1700);
        Artwork* artwork = new Painting("Damaged Work", 1750, artist);
        Restoration* restoration = new Restoration("REST002", artwork, restorer);
        
        restoration->setStartYear(2023);
        restoration->setCompletionYear(2024);
        restoration->setConditionBefore("Poor");
        restoration->setConditionAfter("Good");
        restoration->setCost(50000.0);
        restoration->setStatus("completed");
        
        CHECK_EQUAL(2023, restoration->getStartYear());
        CHECK_EQUAL(2024, restoration->getCompletionYear());
        CHECK_EQUAL("Poor", restoration->getConditionBefore());
        CHECK_EQUAL("Good", restoration->getConditionAfter());
        CHECK_CLOSE(50000.0, restoration->getCost(), 0.01);
        CHECK_EQUAL("completed", restoration->getStatus());
        CHECK(restoration->isCompleted());
        
        delete restoration;
        delete artwork;
        delete artist;
        delete restorer;
        delete gallery;
    }
    
    TEST(RestorationTechniques) {
        Gallery* gallery = new Gallery("Tate", "Bankside", "London", "UK");
        Restorer* restorer = new Restorer("Sarah", "Jones", "REST003", gallery);
        Artist* artist = new Artist("Test", "Artist", "Unknown", 1600);
        Artwork* artwork = new Painting("Antique", 1650, artist);
        Restoration* restoration = new Restoration("REST003", artwork, restorer);
        
        restoration->addTechnique("Cleaning");
        restoration->addTechnique("Varnishing");
        restoration->addTechnique("Retouching");
        
        std::vector<std::string> techniques = restoration->getTechniquesUsed();
        CHECK_EQUAL(3, techniques.size());
        CHECK_EQUAL("Cleaning", techniques[0]);
        
        delete restoration;
        delete artwork;
        delete artist;
        delete restorer;
        delete gallery;
    }
}

