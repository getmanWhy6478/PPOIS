#include "UnitTest++/UnitTest++.h"
#include "../include/Security.h"
#include "../include/Gallery.h"
#include "../include/Room.h"

SUITE(SecurityTests) {
    TEST(SecurityConstructor) {
        Gallery* gallery = new Gallery("MoMA", "11 W 53rd St", "New York", "USA");
        Security* security = new Security("Mike", "Guard", "SEC001", gallery);
        
        CHECK_EQUAL("Security", security->getPosition());
        delete security;
        delete gallery;
    }
    
    TEST(SecurityProperties) {
        Gallery* gallery = new Gallery("Louvre", "Rue de Rivoli", "Paris", "France");
        Security* security = new Security("Jean", "Martin", "SEC002", gallery);
        Room* room = new Room("Main Hall", "R001", 500.0);
        
        security->setAssignedRoom(room);
        security->setHasWeaponLicense(true);
        
        CHECK(security->getAssignedRoom() == room);
        CHECK(security->getHasWeaponLicense());
        
        delete security;
        delete room;
        delete gallery;
    }

    TEST(SecurityReportIncident) {
        Gallery* gallery = new Gallery("Uffizi", "Piazzale degli Uffizi", "Florence", "Italy");
        Security* security = new Security("Marco", "Rossi", "SEC003", gallery);
        Room* room = new Room("Botticelli Room", "R010", 200.0);

        security->reportIncident("Suspicious activity", room);

        CHECK_EQUAL(1u, security->getIncidentReports().size());
        CHECK(security->getAssignedRoom() == room);
        CHECK_EQUAL("Suspicious activity", security->getIncidentReports().front());

        delete security;
        delete room;
        delete gallery;
    }
}

