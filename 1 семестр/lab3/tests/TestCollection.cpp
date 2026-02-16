#include "UnitTest++/UnitTest++.h"
#include "../include/Collection.h"
#include "../include/Collector.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"

SUITE(CollectionTests) {
    TEST(CollectionConstructor) {
        Collector* collector = new Collector("John", "Patron");
        Collection* collection = new Collection("Modern Masters", collector);
        
        CHECK_EQUAL("Modern Masters", collection->getName());
        CHECK(collection->getCollector() == collector);
        
        delete collection;
        delete collector;
    }
    
    TEST(CollectionAddArtwork) {
        Collector* collector = new Collector("Jane", "Collector");
        Collection* collection = new Collection("Impressionists", collector);
        Artist* artist = new Artist("Claude", "Monet", "French", 1840);
        Artwork* artwork = new Painting("Water Lilies", 1919, artist);
        
        artwork->setEstimatedValue(50000000.0);
        collection->addArtwork(artwork);
        
        std::vector<Artwork*> artworks = collection->getArtworks();
        CHECK_EQUAL(1, artworks.size());
        CHECK_EQUAL(1, collection->getTotalArtworks());
        CHECK_CLOSE(50000000.0, collection->getTotalValue(), 0.01);
        
        delete collection;
        delete artwork;
        delete artist;
        delete collector;
    }
    TEST(CollectionsEqual) {
        Collection c1 ;
        Collection c2 ;
        CHECK_EQUAL(c1 == c2, false);
    }

    TEST(DifferentName) {
        Collection c1 ;
        Collection c2 ;
        c2.setName("Другая");
        CHECK_EQUAL(!(c1 == c2), true);
    }

    TEST(DifferentDescription) {
        Collection c1 ;
        Collection c2 ;
        c2.setDescription("Другое описание");
        CHECK_EQUAL(!(c1 == c2), true);
    }

    TEST(DifferentCollectorPointer) {
        Collection c1 ;
        Collection c2 ;
        Collector* j;
        c2.setCollector(j);
        CHECK_EQUAL(!(c1 == c2), true);
    }

    TEST(DifferentTotalArtworks) {
        Collection c1 ;
        Collection c2 ;
        Artwork* a1;
        c2.addArtwork(a1); 
        CHECK_EQUAL(!(c1 == c2), true);
    }

    TEST(DifferentTotalValue) {
        Collection c1 ;
        Collection c2 ;
        Artwork* a1;
        c2.addArtwork(a1);
        CHECK_EQUAL(!(c1 == c2), true);
    }

    TEST(DifferentArtworksSize) {
        Collection c1 ;
        Collection c2 ;
        Artwork* a1;
        c2.addArtwork(a1);
        CHECK_EQUAL(!(c1 == c2), true);
    }

    TEST(DifferentArtworkPointer) {
        Collection c1 ;
        Collection c2 ;
        Artwork* a1;
        c2.addArtwork(a1);
        CHECK_EQUAL(!(c1 == c2), true);
    }
}

