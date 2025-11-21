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
        
        workshop->setSkillLevel("Beginner");
        workshop->addMaterialProvided("Clay");
        workshop->addMaterialProvided("Tools");
        workshop->addMaterialNeeded("Apron");
        workshop->setMaxParticipants(15);
        workshop->setMaterialFee(25.0);
        workshop->setWorkshopType("Sculpture");
        
        CHECK_EQUAL("Beginner", workshop->getSkillLevel());
        std::vector<std::string> provided = workshop->getMaterialsProvided();
        CHECK_EQUAL(2, provided.size());
        std::vector<std::string> needed = workshop->getMaterialsNeeded();
        CHECK_EQUAL(1, needed.size());
        CHECK_EQUAL(15, workshop->getMaxParticipants());
        CHECK_CLOSE(25.0, workshop->getMaterialFee(), 0.01);
        CHECK_EQUAL("Sculpture", workshop->getWorkshopType());
        
        delete workshop;
        delete gallery;
    }
}

