#include "UnitTest++/UnitTest++.h"
#include "../include/Painting.h"
#include "../include/Artist.h"

SUITE(PaintingTests) {
    TEST(PaintingConstructor) {
        Artist* artist = new Artist("Rembrandt", "van Rijn", "Dutch", 1606);
        Painting* painting = new Painting("The Night Watch", 1642, artist);
        
        CHECK_EQUAL("The Night Watch", painting->getTitle());
        CHECK_EQUAL(1642, painting->getYear());
        
        delete painting;
        delete artist;
    }
    
    TEST(PaintingProperties) {
        Artist* artist = new Artist("Johannes", "Vermeer", "Dutch", 1632);
        Painting* painting = new Painting("Girl with a Pearl Earring", 1665, artist);
        
        painting->setPaintType("Oil");
        painting->setCanvasType("Canvas");
        painting->setIsFramed(true);
        
        CHECK_EQUAL("Oil", painting->getPaintType());
        CHECK_EQUAL("Canvas", painting->getCanvasType());
        CHECK(painting->getIsFramed());
        
        delete painting;
        delete artist;
    }
}

