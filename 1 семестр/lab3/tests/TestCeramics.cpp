#include "UnitTest++/UnitTest++.h"
#include "../include/Ceramics.h"
#include "../include/Artist.h"

SUITE(CeramicsTests) {
    TEST(CeramicsConstructor) {
        Artist* artist = new Artist("Pablo", "Picasso", "Spanish", 1881);
        Ceramics* ceramics = new Ceramics("Vase", 1950, artist);
        
        CHECK_EQUAL(1950, ceramics->getYear());
        
        delete ceramics;
        delete artist;
    }
    
    TEST(CeramicsProperties) {
        Artist* artist = new Artist("Claude", "Monet", "French", 1840);
        Ceramics* ceramics = new Ceramics("Pottery", 1880, artist);
        
        ceramics->setClayType("Stoneware");
        ceramics->setFiringTechnique("High fire");
        ceramics->setGlazeType("Celadon");
        
        CHECK_EQUAL("Stoneware", ceramics->getClayType());
        CHECK_EQUAL("High fire", ceramics->getFiringTechnique());
        CHECK_EQUAL("Celadon", ceramics->getGlazeType());
        
        delete ceramics;
        delete artist;
    }
}

