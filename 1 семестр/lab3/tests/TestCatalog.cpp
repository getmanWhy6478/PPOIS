#include "UnitTest++/UnitTest++.h"
#include "../include/Catalog.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"
#include "../include/Exhibition.h"
#include "../include/Gallery.h"

SUITE(CatalogTests) {
    TEST(CatalogConstructor) {
        Catalog* catalog = new Catalog("978-0-123456-78-9", "Modern Art Catalog", "Art Publishers");
        
        CHECK_EQUAL("978-0-123456-78-9", catalog->getIsbn());
        CHECK_EQUAL("Modern Art Catalog", catalog->getTitle());
        CHECK_EQUAL("Art Publishers", catalog->getPublisher());
        
        delete catalog;
    }
    
    TEST(CatalogProperties) {
        Catalog* catalog = new Catalog("978-0-987654-32-1", "impressionist Works", "Gallery Press");
        
        catalog->setPublicationYear(2024);
        catalog->setPageCount(250);
        catalog->setLanguage("English");
        catalog->setPrice(49.99);
        
        CHECK_EQUAL(2024, catalog->getPublicationYear());
        CHECK_EQUAL(250, catalog->getPageCount());
        CHECK_EQUAL("English", catalog->getLanguage());
        CHECK_CLOSE(49.99, catalog->getPrice(), 0.01);
        
        delete catalog;
    }
    
    TEST(CatalogAddArtwork) {
        Catalog* catalog = new Catalog("978-0-111111-11-1", "Collection Catalog", "Publisher");
        Gallery* gallery = new Gallery("MoMA", "11 W 53rd St", "New York", "USA");
        Exhibition* exhibition = new Exhibition("Collection", gallery, 2024, 2024);
        Artist* artist = new Artist("Test", "Artist", "Unknown", 1900);
        Artwork* artwork = new Painting("Catalog Artwork", 2000, artist);
        
        catalog->setExhibition(exhibition);
        catalog->addArtwork(artwork);
        
        std::vector<Artwork*> artworks = catalog->getArtworks();
        CHECK_EQUAL(1, artworks.size());
        CHECK(catalog->getExhibition() == exhibition);
        
        delete catalog;
        delete artwork;
        delete artist;
        delete exhibition;
        delete gallery;
    }
}

