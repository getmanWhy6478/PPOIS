#include "UnitTest++/UnitTest++.h"
#include "../include/Curator.h"
#include "../include/Gallery.h"
#include "../include/Exhibition.h"

SUITE(CuratorTests) {
    TEST(CuratorConstructor) {
        Gallery* gallery = new Gallery("MoMA", "11 W 53rd St", "New York", "USA");
        Curator* curator = new Curator("Alice", "Smith", "CUR001", gallery);
        
        CHECK_EQUAL("Curator", curator->getPosition());
        
        delete curator;
        delete gallery;
    }
    
    TEST(CuratorProperties) {
        Gallery* gallery = new Gallery("Tate", "Bankside", "London", "UK");
        Curator* curator = new Curator("Bob", "Johnson", "CUR002", gallery);
        
        curator->setSpecialization("Modern Art");
        curator->setEducation("PhD Art History");
        
        CHECK_EQUAL("Modern Art", curator->getSpecialization());
        CHECK_EQUAL("PhD Art History", curator->getEducation());
        
        delete curator;
        delete gallery;
    }

    TEST(CuratorCurateExhibition) {
        Gallery* gallery = new Gallery("Pompidou", "Place Georges-Pompidou", "Paris", "France");
        Curator* curator = new Curator("Claire", "Martin", "CUR003", gallery);
        Exhibition* exhibition = new Exhibition("New Perspectives", gallery, 2025, 2026);

        bool curated = curator->curateExhibition(exhibition, "Avant-garde", 25.0);

        CHECK(curated);
        CHECK(exhibition->getCurator() == curator);
        CHECK_EQUAL("Avant-garde", exhibition->getTheme());
        CHECK_CLOSE(25.0, exhibition->getAdmissionPrice(), 0.01);
        CHECK_EQUAL(1, curator->getExhibitions().size());

        delete exhibition;
        delete curator;
        delete gallery;
    }
}

