#include "UnitTest++/UnitTest++.h"
#include "../include/Drawing.h"
#include "../include/Artist.h"

SUITE(DrawingTests) {
    TEST(DrawingConstructor) {
        Artist* artist = new Artist("Leonardo", "da Vinci", "Italian", 1452);
        Drawing* drawing = new Drawing("Study of Hands", 1474, artist);
        
        CHECK_EQUAL("Drawing", drawing->getType());
        
        delete drawing;
        delete artist;
    }
    
    TEST(DrawingProperties) {
        Artist* artist = new Artist("Michelangelo", "Buonarroti", "Italian", 1475);
        Drawing* drawing = new Drawing("Study", 1500, artist);
        
        drawing->setDrawingMedium("Charcoal");
        drawing->setPaperType("Sketch paper");
        drawing->setPaperSize("A4");
        drawing->setIsSigned(true);
        drawing->setIsDated(true);
        
        CHECK_EQUAL("Charcoal", drawing->getDrawingMedium());
        CHECK_EQUAL("Sketch paper", drawing->getPaperType());
        CHECK_EQUAL("A4", drawing->getPaperSize());
        CHECK(drawing->getIsSigned());
        CHECK(drawing->getIsDated());
        
        delete drawing;
        delete artist;
    }
}

