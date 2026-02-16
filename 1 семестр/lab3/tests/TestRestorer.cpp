#include "UnitTest++/UnitTest++.h"
#include "../include/Restorer.h"
#include "../include/Gallery.h"
#include "../include/Restoration.h"
#include "../include/Artist.h"
#include "../include/Painting.h"

SUITE(RestorerTests) {
    TEST(RestorerConstructor) {
        Gallery* gallery = new Gallery("Louvre", "Rue de Rivoli", "Paris", "France");
        Restorer* restorer = new Restorer("Marie", "Dupont", "REST001", gallery);
        
        CHECK_EQUAL("Restorer", restorer->getPosition());
        
        delete restorer;
        delete gallery;
    }
    
    TEST(RestorerProperties) {
        Gallery* gallery = new Gallery("Met", "1000 5th Ave", "New York", "USA");
        Restorer* restorer = new Restorer("John", "Smith", "REST002", gallery);
        
        restorer->setSpecialization("Paintings");
        restorer->setEducation("Conservation degree");
        
        CHECK_EQUAL("Paintings", restorer->getSpecialization());
        CHECK_EQUAL("Conservation degree", restorer->getEducation());
        
        delete restorer;
        delete gallery;
    }

    TEST(RestorerStartRestoration) {
        Gallery* gallery = new Gallery("Prado", "Calle de Ruiz de Alarcón", "Madrid", "Spain");
        Restorer* restorer = new Restorer("Luis", "Garcia", "REST003", gallery);
        Artist* artist = new Artist("Diego", "Velazquez", "Spain", 1599);
        Painting* painting = new Painting("Las Meninas", 1656, artist);

        Restoration* restoration = restorer->startRestoration("RES-001", painting, "Surface dust");

        CHECK(restoration != nullptr);
        CHECK_EQUAL(restorer, restoration->getRestorer());
        CHECK_EQUAL(painting, restoration->getArtwork());
        CHECK_EQUAL("in progress", restoration->getStatus());
        CHECK_EQUAL(1, restorer->getRestorations().size());

        delete restoration;
        delete painting;
        delete artist;
        delete restorer;
        delete gallery;
    }
}

