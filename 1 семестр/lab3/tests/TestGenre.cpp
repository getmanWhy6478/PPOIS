#include "UnitTest++/UnitTest++.h"
#include "../include/Genre.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"

SUITE(GenreTests) {
    TEST(GenreConstructor) {
        Genre* genre = new Genre("Portrait");
        
        CHECK_EQUAL("Portrait", genre->getName());
        
        delete genre;
    }
    
    TEST(GenreProperties) {
        Genre* genre = new Genre("Landscape");
        
        genre->setDescription("Depiction of natural scenery");
        genre->setCharacteristics("Focus on nature, outdoor settings");
        
        CHECK_EQUAL("Depiction of natural scenery", genre->getDescription());
        CHECK_EQUAL("Focus on nature, outdoor settings", genre->getCharacteristics());
        
        delete genre;
    }
}

