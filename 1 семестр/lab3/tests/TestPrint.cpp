#include "UnitTest++/UnitTest++.h"
#include "../include/Print.h"
#include "../include/Artist.h"

SUITE(PrintTests) {
    TEST(PrintConstructor) {
        Artist* artist = new Artist("Albrecht", "Durer", "German", 1471);
        Print* print = new Print("The Four Horsemen", 1498, artist);
        
        CHECK_EQUAL(1498, print->getYear());
        
        delete print;
        delete artist;
    }
    
    TEST(PrintProperties) {
        Artist* artist = new Artist("Rembrandt", "van Rijn", "Dutch", 1606);
        Print* print = new Print("The Three Crosses", 1653, artist);
        
        print->setPrintType("Etching");
        print->setIsSigned(true);
        print->setIsNumbered(true);
        
        CHECK_EQUAL("Etching", print->getPrintType());
        CHECK(print->getIsSigned());
        CHECK(print->getIsNumbered());
        
        delete print;
        delete artist;
    }
}

