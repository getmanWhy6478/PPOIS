#include "UnitTest++/UnitTest++.h"
#include "../include/Room.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"

SUITE(RoomTests) {
    TEST(RoomConstructor) {
        Room* room = new Room("Main Hall", "R001", 500.0);
        
        CHECK_EQUAL("Main Hall", room->getName());
        CHECK_EQUAL("R001", room->getNumber());
        CHECK_CLOSE(500.0, room->getArea(), 0.01);
        
        delete room;
    }
    
    TEST(RoomSetters) {
        Room* room = new Room("Gallery A", "R002", 300.0);
        
        room->setHeight(4.5);
        room->setMaxCapacity(100);
        
        CHECK_CLOSE(4.5, room->getHeight(), 0.01);
        CHECK_EQUAL(100, room->getMaxCapacity());
        
        delete room;
    }
    
    TEST(RoomAddArtwork) {
        Room* room = new Room("Gallery B", "R003", 200.0);
        Artist* artist = new Artist("Test", "Artist", "Unknown", 1900);
        Artwork* artwork = new Painting("Test Painting", 2000, artist);
        
        room->addArtwork(artwork);
        std::vector<Artwork*> artworks = room->getArtworks();
        
        CHECK_EQUAL(1, artworks.size());
        CHECK(artworks[0] == artwork);
        
        delete room;
        delete artwork;
        delete artist;
    }
}

