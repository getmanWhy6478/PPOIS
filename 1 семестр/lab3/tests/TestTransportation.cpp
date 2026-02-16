#include "UnitTest++/UnitTest++.h"
#include "../include/Transportation.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"

SUITE(TransportationTests) {
    TEST(TransportationConstructor) {
        Transportation* transport = new Transportation("SHIP001", "Paris", "New York");
        
        CHECK_EQUAL("SHIP001", transport->getShipmentNumber());
        CHECK_EQUAL("Paris", transport->getOrigin());
        CHECK_EQUAL("New York", transport->getDestination());
        CHECK_EQUAL("scheduled", transport->getStatus());
        
        delete transport;
    }
    
    TEST(TransportationProperties) {
        Transportation* transport = new Transportation("SHIP002", "London", "Tokyo");
        
        transport->setCost(15000.0);
        transport->setStatus("in transit");
        transport->setShipmentNumber("sgawsgr");
        
        CHECK_CLOSE(15000.0, transport->getCost(), 0.01);
        CHECK_EQUAL("in transit", transport->getStatus());
        
        delete transport;
    }
}

