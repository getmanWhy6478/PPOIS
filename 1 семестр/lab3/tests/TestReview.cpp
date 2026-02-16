#include "UnitTest++/UnitTest++.h"
#include "../include/Review.h"
#include "../include/Critic.h"
#include "../include/Exhibition.h"
#include "../include/Gallery.h"

SUITE(ReviewTests) {
    TEST(ReviewConstructor) {
        Critic* critic = new Critic("Art", "Reviewer", "Art Magazine");
        Gallery* gallery = new Gallery("MoMA", "11 W 53rd St", "New York", "USA");
        Exhibition* exhibition = new Exhibition("Contemporary", gallery, 2024, 2024);
        Review* review = new Review("REV001", critic, exhibition);
        
        CHECK_EQUAL("REV001", review->getReviewId());
        CHECK(review->getCritic() == critic);
        CHECK(review->getExhibition() == exhibition);
        CHECK_EQUAL(0, review->getRating());
        CHECK_EQUAL(0, review->getViewCount());
        
        delete review;
        delete exhibition;
        delete gallery;
        delete critic;
    }
    
    TEST(ReviewContent) {
        Critic* critic = new Critic("Jane", "Critic", "Art Weekly");
        Gallery* gallery = new Gallery("Tate", "Bankside", "London", "UK");
        Exhibition* exhibition = new Exhibition("Modern Masters", gallery, 2024, 2024);
        Review* review = new Review("REV002", critic, exhibition);
        
        review->setTitle("Excellent Exhibition");
        review->setContent("This exhibition showcases amazing works...");
        review->setRating(9);
        review->setPublication("Art Weekly");
        
        CHECK_EQUAL("Excellent Exhibition", review->getTitle());
        CHECK_EQUAL("This exhibition showcases amazing works...", review->getContent());
        CHECK_EQUAL(9, review->getRating());
        CHECK_EQUAL("Art Weekly", review->getPublication());
        
        delete review;
        delete exhibition;
        delete gallery;
        delete critic;
    }
    
    TEST(ReviewViewCount) {
        Critic* critic = new Critic("Bob", "Writer", "Art News");
        Gallery* gallery = new Gallery("Louvre", "Rue de Rivoli", "Paris", "France");
        Exhibition* exhibition = new Exhibition("Renaissance", gallery, 2024, 2024);
        Review* review = new Review("REV003", critic, exhibition);
        
        CHECK_EQUAL(0, review->getViewCount());
        review->incrementViewCount();
        CHECK_EQUAL(1, review->getViewCount());
        review->incrementViewCount();
        CHECK_EQUAL(2, review->getViewCount());
        
        delete review;
        delete exhibition;
        delete gallery;
        delete critic;
    }
}

