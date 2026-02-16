#include "UnitTest++/UnitTest++.h"
#include "../include/Collector.h"
#include "../include/Collection.h"
#include "../include/Artist.h"
#include "../include/Painting.h"

SUITE(CollectorTests) {
    TEST(CollectorConstructor) {
        Collector* collector = new Collector("John", "Patron");
        
        CHECK_EQUAL("John", collector->getFirstName());
        CHECK_EQUAL("Patron", collector->getLastName());
        CHECK_EQUAL("John Patron", collector->getFullName());
        delete collector;
    }

    TEST(CollectorPurchaseArtwork) {
        Collector* collector = new Collector("Lydia", "Artlover");
        Collection* collection = new Collection("Modern Wonders", collector);
        collector->addCollection(collection);

        Artist* artist = new Artist("Pablo", "Picasso", "Spain", 1881);
        Painting* painting = new Painting("Guernica Replica", 1937, artist);

        bool purchased = collector->purchaseArtwork(painting, collection, 1000000.0);

        CHECK(purchased);
        CHECK_EQUAL(1, collection->getTotalArtworks());
        CHECK_CLOSE(1000000.0, collection->getTotalValue(), 0.01);

        delete painting;
        delete artist;
        delete collection;
        delete collector;
    }
}

