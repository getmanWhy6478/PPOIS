#include "UnitTest++/UnitTest++.h"
#include "../include/ArtMovement.h"
#include "../include/Artist.h"

SUITE(ArtMovementTests) {
    TEST(ArtMovementConstructor) {
        ArtMovement* movement = new ArtMovement("impressionism", 1874);
        
        CHECK_EQUAL("impressionism", movement->getName());
        CHECK_EQUAL(1874, movement->getStartYear());
        
        delete movement;
    }
    
    TEST(ArtMovementProperties) {
        ArtMovement* movement = new ArtMovement("Cubism", 1907);
        
        movement->setDescription("Avant-garde art movement");
        movement->setEndYear(1920);
        
        CHECK_EQUAL("Avant-garde art movement", movement->getDescription());
        CHECK_EQUAL(1920, movement->getEndYear());
        
        delete movement;
    }
    
    TEST(ArtMovementAddArtist) {
        ArtMovement* movement = new ArtMovement("Surrealism", 1924);
        Artist* artist1 = new Artist("Salvador", "Dali", "Spanish", 1904);
        Artist* artist2 = new Artist("Rene", "Magritte", "Belgian", 1898);
        
        movement->addArtist(artist1);
        movement->addArtist(artist2);
        
        std::vector<Artist*> artists = movement->getArtists();
        CHECK_EQUAL(2, artists.size());
        
        delete movement;
        delete artist1;
        delete artist2;
    }
}

