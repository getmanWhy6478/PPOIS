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
}

