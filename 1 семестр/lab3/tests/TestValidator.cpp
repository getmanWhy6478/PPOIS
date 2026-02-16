#include "UnitTest++/UnitTest++.h"
#include "../include/Validator.h"

SUITE(ValidatorTests) {
    TEST(IsValidEmail) {
        CHECK(Validator::isValidEmail("test@example.com"));
        CHECK(Validator::isValidEmail("user.name@domain.co.uk"));
        CHECK(Validator::isValidEmail("user+tag@example.org"));
        CHECK(Validator::isValidEmail("invalid") == false);
        CHECK(Validator::isValidEmail("@example.com") == false);
        CHECK(Validator::isValidEmail("") == false);
    }
    
    TEST(IsValidPhone) {
        CHECK(Validator::isValidPhone("+1-555-123-4567"));
        CHECK(Validator::isValidPhone("(555) 123-4567"));
        CHECK(Validator::isValidPhone("555-1234"));
        CHECK(Validator::isValidPhone("") == false);
        CHECK(Validator::isValidPhone("abc") == false);
    }
    
    TEST(IsValidYear) {
        CHECK(Validator::isValidYear(2024));
        CHECK(Validator::isValidYear(1900));
        CHECK(Validator::isValidYear(2000));
        CHECK(Validator::isValidYear(999) == false);
        CHECK(Validator::isValidYear(3001) == false);
    }
    
    TEST(IsValidPrice) {
        CHECK(Validator::isValidPrice(0.0));
        CHECK(Validator::isValidPrice(100.0));
        CHECK(Validator::isValidPrice(1000000.0));
        CHECK(Validator::isValidPrice(-10.0) == false);
    }
    
    TEST(IsValidRating) {
        CHECK(Validator::isValidRating(5));
        CHECK(Validator::isValidRating(1));
        CHECK(Validator::isValidRating(10));
        CHECK(Validator::isValidRating(0) == false);
        CHECK(Validator::isValidRating(11) == false);
        CHECK(Validator::isValidRating(5, 1, 5));
        CHECK(Validator::isValidRating(3, 1, 5));
    }
    
    TEST(IsValidPercentage) {
        CHECK(Validator::isValidPercentage(0));
        CHECK(Validator::isValidPercentage(50));
        CHECK(Validator::isValidPercentage(100));
        CHECK(Validator::isValidPercentage(-1) == false);
        CHECK(Validator::isValidPercentage(101) == false);
    }
}

