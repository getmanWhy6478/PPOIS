#include "UnitTest++/UnitTest++.h"
#include "../include/Artist.h"
#include "../include/ArtMovement.h"
#include "../include/Artwork.h"

SUITE(ArtistTests) {
    TEST(ArtistConstructor) {
        Artist* artist = new Artist("Pablo", "Picasso", "Spanish", 1881);
        
        CHECK_EQUAL("Pablo", artist->getFirstName());
        CHECK_EQUAL("Picasso", artist->getLastName());
        CHECK_EQUAL("Pablo Picasso", artist->getFullName());
        CHECK_EQUAL("Spanish", artist->getNationality());
        CHECK_EQUAL(1881, artist->getBirthYear());
        CHECK(artist->getIsAlive() == true);
        
        delete artist;
    }
    
    TEST(ArtistSetters) {
        Artist* artist = new Artist("Claude", "Monet", "French", 1840);
        
        artist->setFirstName("Oscar-Claude");
        artist->setLastName("Monet");
        artist->setNationality("France");
        artist->setBirthYear(1840);
        artist->setDeathYear(1926);
        artist->setBiography("impressionist painter");
        artist->setStyle("impressionism");
        artist->setIsAlive(false);
        
        CHECK_EQUAL("Oscar-Claude", artist->getFirstName());
        CHECK_EQUAL("Monet", artist->getLastName());
        CHECK_EQUAL("France", artist->getNationality());
        CHECK_EQUAL(1840, artist->getBirthYear());
        CHECK_EQUAL(1926, artist->getDeathYear());
        CHECK_EQUAL("impressionist painter", artist->getBiography());
        CHECK_EQUAL("impressionism", artist->getStyle());
        CHECK(artist->getIsAlive() == false);
        
        delete artist;
    }
    
    TEST(ArtistAddMovement) {
        Artist* artist = new Artist("Salvador", "Dali", "Spanish", 1904);
        ArtMovement* movement = new ArtMovement("Surrealism", 1924);
        
        artist->addMovement(movement);
        std::vector<ArtMovement*> movements = artist->getMovements();
        
        CHECK_EQUAL(1, movements.size());
        CHECK(movements[0] == movement);
        
        delete artist;
        delete movement;
    }
    TEST(CreateMasterpieceReturnsArtworkByValue) {
        Artist artist("Иван", "Иванов", "Беларусь", 1980);

        Artwork art = artist.createMasterpiece("Шедевр", 45);
        CHECK_EQUAL("Шедевр", art.getTitle());
        CHECK_EQUAL(45, art.getYear()); 
        CHECK_EQUAL(&artist, art.getArtist());
    }
}

