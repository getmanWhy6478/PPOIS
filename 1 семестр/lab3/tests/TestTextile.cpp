#include "UnitTest++/UnitTest++.h"
#include "../include/Textile.h"
#include "../include/Artist.h"

SUITE(TextileTests) {
    TEST(TextileConstructor) {
        Artist* artist = new Artist("Anni", "Albers", "German", 1899);
        Textile* textile = new Textile("Tapestry", 1950, artist);
        
        CHECK_EQUAL("Tapestry", textile->getTitle());
        
        delete textile;
        delete artist;
    }
    
    TEST(TextileProperties) {
        Artist* artist = new Artist("Sheila", "Hicks", "American", 1934);
        Textile* textile = new Textile("Weaving", 1970, artist);
        
        textile->setTextileType("Tapestry");
        textile->setIsHandmade(true);
        
        CHECK_EQUAL("Tapestry", textile->getTextileType());
        CHECK(textile->getIsHandmade());
        
        delete textile;
        delete artist;
    }
}

