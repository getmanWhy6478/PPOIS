#include "UnitTest++/UnitTest++.h"
#include "../include/Gallery.h"
#include "../include/Room.h"
#include "../include/Exhibition.h"

SUITE(GalleryTests) {
    TEST(GalleryConstructor) {
        Gallery* gallery = new Gallery("Louvre", "Rue de Rivoli", "Paris", "France");
        
        CHECK_EQUAL("Louvre", gallery->getName());
        CHECK_EQUAL("Rue de Rivoli", gallery->getAddress());
        CHECK_EQUAL("Paris", gallery->getCity());
        CHECK_EQUAL("France", gallery->getCountry());
        
        delete gallery;
    }
    
    TEST(GallerySetters) {
        Gallery* gallery = new Gallery("Met", "1000 5th Ave", "New York", "USA");
        
        gallery->setName("Metropolitan Museum");
        gallery->setAdmissionPrice(25.0);
        gallery->setMaxCapacity(5000);
        
        CHECK_EQUAL("Metropolitan Museum", gallery->getName());
        CHECK_CLOSE(25.0, gallery->getAdmissionPrice(), 0.01);
        
        delete gallery;
    }
    
    TEST(GalleryAddRoom) {
        Gallery* gallery = new Gallery("Tate", "Bankside", "London", "UK");
        Room* room = new Room("Modern Art", "Room 1", 200.0);
        
        gallery->addRoom(room);
        std::vector<Room*> rooms = gallery->getRooms();
        
        CHECK_EQUAL(1, rooms.size());
        CHECK(rooms[0] == room);
        
        delete gallery;
        delete room;
    }
}

