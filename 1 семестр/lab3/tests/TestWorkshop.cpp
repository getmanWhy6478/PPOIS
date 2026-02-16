#include "UnitTest++/UnitTest++.h"
#include "../include/Workshop.h"
#include "../include/Gallery.h"

SUITE(WorkshopTests) {
    TEST(WorkshopConstructor) {
        Gallery* gallery = new Gallery("Louvre", "Rue de Rivoli", "Paris", "France");
        Workshop* workshop = new Workshop("WSH001", "Painting Workshop", gallery, "Master Artist");
        
        CHECK_EQUAL("Master Artist", workshop->getInstructorName());
        
        delete workshop;
        delete gallery;
    }
    
    TEST(WorkshopProperties) {
        Gallery* gallery = new Gallery("Met", "1000 5th Ave", "New York", "USA");
        Workshop* workshop = new Workshop("WSH002", "Sculpture", gallery, "Instructor");
        
        workshop->addMaterialNeeded("Apron");
        workshop->setMaterialFee(25.0);
        
        std::vector<std::string> needed = workshop->getMaterialsNeeded();
        CHECK_EQUAL(1, needed.size());
        CHECK_CLOSE(25.0, workshop->getMaterialFee(), 0.01);
        
        delete workshop;
        delete gallery;
    }
}

