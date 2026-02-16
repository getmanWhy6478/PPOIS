#include "UnitTest++/UnitTest++.h"
#include "../include/Photography.h"
#include "../include/Artist.h"

SUITE(PhotographyTests) {
    TEST(PhotographyConstructor) {
        Artist* artist = new Artist("Ansel", "Adams", "American", 1902);
        Photography* photo = new Photography("Moonrise", 1941, artist);
        
        CHECK_EQUAL(1941, photo->getYear());
        
        delete photo;
        delete artist;
    }
    
    TEST(PhotographyProperties) {
        Artist* artist = new Artist("Henri", "Cartier-Bresson", "French", 1908);
        Photography* photo = new Photography("Behind Gare Saint-Lazare", 1932, artist);
        
        photo->setCameraType("Leica");
        photo->setFilmType("Film");
        photo->setShootYear(1932);
        
        CHECK_EQUAL("Leica", photo->getCameraType());
        CHECK_EQUAL("Film", photo->getFilmType());
        CHECK_EQUAL(1932, photo->getShootYear());
        
        delete photo;
        delete artist;
    }
}

