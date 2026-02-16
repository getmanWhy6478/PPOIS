#include "UnitTest++/UnitTest++.h"
#include "../include/Storage.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"

SUITE(StorageTests) {
    TEST(StorageConstructor) {
        Storage* storage = new Storage("Warehouse A", "Archive");
        
        CHECK_EQUAL("Warehouse A", storage->getLocation());
        CHECK_EQUAL("Archive", storage->getStorageType());
        
        delete storage;
    }
    
    TEST(StorageProperties) {
        Storage* storage = new Storage("Vault B", "Secure");
        
        storage->setSecurityLevel("Maximum");
        storage->setCapacity(100);
        
        CHECK_EQUAL("Maximum", storage->getSecurityLevel());
        CHECK_EQUAL(100, storage->getCapacity());
        delete storage;
    }
    
    TEST(StorageIsFull) {
        Storage* storage = new Storage("Vault C", "Secure");
        storage->setCapacity(2);
        
        Artist* artist = new Artist("Test", "Artist", "Unknown", 1900);
        Artwork* artwork1 = new Painting("Art 1", 2000, artist);
        Artwork* artwork2 = new Painting("Art 2", 2001, artist);
        
        CHECK(storage->isFull() == false);
        storage->addArtwork(artwork1);
        CHECK(storage->isFull() == false);
        storage->addArtwork(artwork2);
        CHECK(storage->isFull());
        
        delete storage;
        delete artwork1;
        delete artwork2;
        delete artist;
    }
}

