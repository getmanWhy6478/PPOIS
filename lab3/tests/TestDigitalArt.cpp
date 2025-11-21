#include "UnitTest++/UnitTest++.h"
#include "../include/DigitalArt.h"
#include "../include/Artist.h"

SUITE(DigitalArtTests) {
    TEST(DigitalArtConstructor) {
        Artist* artist = new Artist("Rafael", "Lozano-Hemmer", "Mexican", 1967);
        DigitalArt* digital = new DigitalArt("Pulse", 2006, artist);
        
        CHECK_EQUAL("DigitalArt", digital->getType());
        
        delete digital;
        delete artist;
    }
    
    TEST(DigitalArtProperties) {
        Artist* artist = new Artist("Refik", "Anadol", "Turkish", 1985);
        DigitalArt* digital = new DigitalArt("Machine Hallucination", 2019, artist);
        
        digital->setSoftware("Custom AI");
        digital->setFileFormat("Video");
        digital->setDisplayType("Projection");
        digital->setResolutionWidth(3840);
        digital->setResolutionHeight(2160);
        digital->setIsInteractive(true);
        
        CHECK_EQUAL("Custom AI", digital->getSoftware());
        CHECK_EQUAL("Video", digital->getFileFormat());
        CHECK_EQUAL("Projection", digital->getDisplayType());
        CHECK_EQUAL(3840, digital->getResolutionWidth());
        CHECK_EQUAL(2160, digital->getResolutionHeight());
        CHECK(digital->getIsInteractive());
        
        delete digital;
        delete artist;
    }
}

