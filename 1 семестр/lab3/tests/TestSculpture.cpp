#include "UnitTest++/UnitTest++.h"
#include "../include/Sculpture.h"
#include "../include/Artist.h"

SUITE(SculptureTests) {
    TEST(SculptureConstructor) {
        Artist* artist = new Artist("Michelangelo", "Buonarroti", "Italian", 1475);
        Sculpture* sculpture = new Sculpture("David", 1504, artist);
        
        CHECK_EQUAL("David", sculpture->getTitle());
        
        delete sculpture;
        delete artist;
    }
    
    TEST(SculptureProperties) {
        Artist* artist = new Artist("Auguste", "Rodin", "French", 1840);
        Sculpture* sculpture = new Sculpture("The Thinker", 1902, artist);
        
        sculpture->setMaterial("Bronze");
        sculpture->setBaseWidth(50.0);
        sculpture->setBaseHeight(30.0);
        sculpture->setBaseDepth(50.0);
        
        CHECK_EQUAL("Bronze", sculpture->getMaterial());
        CHECK_CLOSE(50.0, sculpture->getBaseWidth(), 0.01);
        CHECK_CLOSE(30.0, sculpture->getBaseHeight(), 0.01);
        CHECK_CLOSE(50.0, sculpture->getBaseDepth(), 0.01);
        
        delete sculpture;
        delete artist;
    }
}

