#include "UnitTest++/UnitTest++.h"
#include "../include/Exhibition.h"
#include "../include/Gallery.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"

SUITE(ExhibitionTests) {
    TEST(ExhibitionConstructor) {
        Gallery* gallery = new Gallery("Guggenheim", "1071 5th Ave", "New York", "USA");
        Exhibition* exhibition = new Exhibition("Modern Masters", gallery, 2024, 2025);
        
        CHECK_EQUAL("Modern Masters", exhibition->getTitle());
        CHECK(exhibition->getGallery() == gallery);
        CHECK_EQUAL(0, exhibition->getVisitorCount());
        
        delete exhibition;
        delete gallery;
    }
    
    TEST(ExhibitionSetters) {
        Gallery* gallery = new Gallery("Tate", "Bankside", "London", "UK");
        Exhibition* exhibition = new Exhibition("impressionists", gallery, 2023, 2024);
        
        exhibition->setDescription("Major impressionist works");
        exhibition->setTheme("impressionism");
        exhibition->setAdmissionPrice(20.0);
        
        CHECK_EQUAL("Major impressionist works", exhibition->getDescription());
        CHECK_EQUAL("impressionism", exhibition->getTheme());
        CHECK_CLOSE(20.0, exhibition->getAdmissionPrice(), 0.01);
        
        delete exhibition;
        delete gallery;
    }
    
    TEST(ExhibitionIncrementVisitorCount) {
        Gallery* gallery = new Gallery("MoMA", "11 W 53rd St", "New York", "USA");
        Exhibition* exhibition = new Exhibition("Contemporary Art", gallery, 2024, 2024);
        
        CHECK_EQUAL(0, exhibition->getVisitorCount());
        exhibition->incrementVisitorCount();
        CHECK_EQUAL(1, exhibition->getVisitorCount());
        exhibition->setVisitorCount(100);
        CHECK_EQUAL(100, exhibition->getVisitorCount());
        
        delete exhibition;
        delete gallery;
    }
}

