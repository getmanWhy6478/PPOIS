#include "UnitTest++/UnitTest++.h"
#include "../include/Lecture.h"
#include "../include/Gallery.h"

SUITE(LectureTests) {
    TEST(LectureConstructor) {
        Gallery* gallery = new Gallery("MoMA", "11 W 53rd St", "New York", "USA");
        Lecture* lecture = new Lecture("LEC001", "Art History", gallery, "Dr. Smith");
        
        CHECK_EQUAL("Dr. Smith", lecture->getSpeakerName());
        
        delete lecture;
        delete gallery;
    }
    
    TEST(LectureProperties) {
        Gallery* gallery = new Gallery("Tate", "Bankside", "London", "UK");
        Lecture* lecture = new Lecture("LEC002", "Modernism", gallery, "Prof. Jones");
        
        lecture->setTopic("Abstract Expressionism");
        lecture->setRequiresRegistration(true);
        
        CHECK_EQUAL("Abstract Expressionism", lecture->getTopic());
        CHECK(lecture->getRequiresRegistration());
        
        delete lecture;
        delete gallery;
    }
}

