#include "UnitTest++/UnitTest++.h"
#include "../include/Critic.h"
#include "../include/Review.h"
#include "../include/Gallery.h"
#include "../include/Exhibition.h"

SUITE(CriticTests) {
    TEST(CriticConstructor) {
        Critic* critic = new Critic("Art", "Reviewer", "Art Magazine");
        
        CHECK_EQUAL("Art", critic->getFirstName());
        CHECK_EQUAL("Reviewer", critic->getLastName());
        CHECK_EQUAL("Art Magazine", critic->getPublication());
        
        delete critic;
    }
    
    TEST(CriticProperties) {
        Critic* critic = new Critic("Jane", "Writer", "Art Weekly");
        
        critic->setSpecialization("Contemporary Art");
        critic->setCredentials("MA Art History");
        
        CHECK_EQUAL("Contemporary Art", critic->getSpecialization());
        CHECK_EQUAL("MA Art History", critic->getCredentials());
        
        delete critic;
    }

    TEST(CriticWriteReview) {
        Gallery* gallery = new Gallery("MoMA", "11 W 53rd St", "New York", "USA");
        Exhibition* exhibition = new Exhibition("Modern Masters", gallery, 2024, 2025);
        Critic* critic = new Critic("Elena", "Marks", "Art Journal");

        Review* review = critic->writeReview("REV-001", exhibition,
                                             "Bold Curation",
                                             "An insightful take on modernism.", 8);

        CHECK(review != nullptr);
        CHECK_EQUAL(1, critic->getReviews().size());
        CHECK(review->getCritic() == critic);
        CHECK(review->getExhibition() == exhibition);
        CHECK_EQUAL(8, review->getRating());

        delete review;
        delete critic;
        delete exhibition;
        delete gallery;
    }
}

