#include "UnitTest++/UnitTest++.h"
#include "../include/Guide.h"
#include "../include/Gallery.h"
#include "../include/Tour.h"
#include "../include/Exhibition.h"

SUITE(GuideTests) {
    TEST(GuideConstructor) {
        Gallery* gallery = new Gallery("Louvre", "Rue de Rivoli", "Paris", "France");
        Guide* guide = new Guide("Marie", "Dubois", "GUID001", gallery);
        
        CHECK_EQUAL("Guide", guide->getPosition());
        CHECK_EQUAL(0, guide->getTotalToursConducted());
        
        delete guide;
        delete gallery;
    }
    
    TEST(GuideLanguages) {
        Gallery* gallery = new Gallery("Met", "1000 5th Ave", "New York", "USA");
        Guide* guide = new Guide("John", "Smith", "GUID002", gallery);
        
        guide->addLanguage("English");
        guide->addLanguage("French");
        guide->addLanguage("Spanish");
        
        std::vector<std::string> languages = guide->getLanguages();
        CHECK_EQUAL(3, languages.size());
        
        delete guide;
        delete gallery;
    }
    
    TEST(GuideRating) {
        Gallery* gallery = new Gallery("Tate", "Bankside", "London", "UK");
        Guide* guide = new Guide("Sarah", "Jones", "GUID003", gallery);
        
        guide->setAverageRating(4.5);
        guide->incrementToursConducted();
        guide->updateAverageRating(4.5);
        
        CHECK_CLOSE(4.5, guide->getAverageRating(), 0.1);
        CHECK_EQUAL(1, guide->getTotalToursConducted());
        
        delete guide;
        delete gallery;
    }

    TEST(GuideConductTour) {
        Gallery* gallery = new Gallery("Hermitage", "Palace Square", "Saint Petersburg", "Russia");
        Guide* guide = new Guide("Ivan", "Petrov", "GUID004", gallery);
        guide->addLanguage("English");

        Exhibition* exhibition = new Exhibition("Russian Masters", gallery, 2024, 2025);
        Tour* tour = new Tour("TOUR-001", guide, exhibition);

        bool conducted = guide->conductTour(tour, "English");

        CHECK(conducted);
        CHECK_EQUAL(1, guide->getTotalToursConducted());
        CHECK_EQUAL(1, guide->getTours().size());
        CHECK_EQUAL(guide, tour->getGuide());

        delete tour;
        delete exhibition;
        delete guide;
        delete gallery;
    }
}

