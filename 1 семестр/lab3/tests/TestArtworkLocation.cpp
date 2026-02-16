#include "UnitTest++/UnitTest++.h"
#include "../include/ArtworkLocation.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"
#include "../include/Room.h"
#include "../include/Storage.h"

SUITE(ArtworkLocationTests) {
    TEST(ArtworkLocationConstructor) {
        Artist* artist = new Artist("Test", "Artist", "Unknown", 1900);
        Artwork* artwork = new Painting("Location Test", 2000, artist);
        ArtworkLocation* location = new ArtworkLocation("LOC001", artwork);
        
        CHECK_EQUAL("LOC001", location->getLocationId());
        CHECK(location->getArtwork() == artwork);
        
        delete location;
        delete artwork;
        delete artist;
    }
    
    TEST(ArtworkLocationUpdate) {
        Artist* artist = new Artist("Test", "Artist", "Unknown", 1900);
        Artwork* artwork = new Painting("Moving Work", 2000, artist);
        ArtworkLocation* location = new ArtworkLocation("LOC002", artwork);
        Room* room = new Room("Gallery A", "R001", 200.0);
        Storage* storage = new Storage("Vault", "Secure");
        location->setLocationId("LOC002");
        location->setCurrentRoom(room);

        
        CHECK(location->getCurrentRoom() == room);
        
        delete location;
        delete storage;
        delete room;
        delete artwork;
        delete artist;
    }
}

