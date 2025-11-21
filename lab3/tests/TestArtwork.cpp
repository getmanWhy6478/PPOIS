#include "UnitTest++/UnitTest++.h"
#include "../include/Artwork.h"
#include "../include/Artist.h"
#include "../include/Painting.h"

SUITE(ArtworkTests) {
    TEST(ArtworkConstructor) {
        Artist* artist = new Artist("Leonardo", "da Vinci", "italian", 1452);
        Artwork* artwork = new Painting("Mona Lisa", 1503, artist);
        
        CHECK_EQUAL("Mona Lisa", artwork->getTitle());
        CHECK_EQUAL(1503, artwork->getYear());
        CHECK(artwork->getArtist() == artist);
        
        delete artwork;
        delete artist;
    }
    
    TEST(ArtworkSetters) {
        Artist* artist = new Artist("Vincent", "van Gogh", "Dutch", 1853);
        Artwork* artwork = new Painting("Starry Night", 1889, artist);
        
        artwork->setTitle("The Starry Night");
        artwork->setDescription("A famous painting");
        artwork->setYear(1889);
        artwork->setWidth(73.7);
        artwork->setHeight(92.1);
        artwork->setEstimatedValue(100000000.0);
        artwork->setCondition("Excellent");
        
        CHECK_EQUAL("The Starry Night", artwork->getTitle());
        CHECK_EQUAL("A famous painting", artwork->getDescription());
        CHECK_EQUAL(1889, artwork->getYear());
        CHECK_CLOSE(73.7, artwork->getWidth(), 0.01);
        CHECK_CLOSE(92.1, artwork->getHeight(), 0.01);
        CHECK_CLOSE(100000000.0, artwork->getEstimatedValue(), 0.01);
        CHECK_EQUAL("Excellent", artwork->getCondition());
        
        delete artwork;
        delete artist;
    }
}

