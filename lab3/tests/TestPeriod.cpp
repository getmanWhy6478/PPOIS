#include "UnitTest++/UnitTest++.h"
#include "../include/Period.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"

SUITE(PeriodTests) {
    TEST(PeriodConstructor) {
        Period* period = new Period("Renaissance", 1400, 1600);
        
        CHECK_EQUAL("Renaissance", period->getName());
        CHECK_EQUAL(1400, period->getStartYear());
        CHECK_EQUAL(1600, period->getEndYear());
        CHECK_EQUAL(200, period->getDuration());
        
        delete period;
    }
    
    TEST(PeriodProperties) {
        Period* period = new Period("Baroque", 1600, 1750);
        
        period->setDescription("Ornate and dramatic style");
        period->setCulturalContext("European art");
        period->addKeyEvent("Counter-Reformation");
        period->addKeyEvent("Rise of absolute monarchies");
        
        CHECK_EQUAL("Ornate and dramatic style", period->getDescription());
        CHECK_EQUAL("European art", period->getCulturalContext());
        std::vector<std::string> events = period->getKeyEvents();
        CHECK_EQUAL(2, events.size());
        
        delete period;
    }
}

