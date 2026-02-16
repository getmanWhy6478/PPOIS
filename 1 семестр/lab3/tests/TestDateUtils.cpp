#include "UnitTest++/UnitTest++.h"
#include "../include/DateUtils.h"

SUITE(DateUtilsTests) {
    TEST(FormatYear) {
        std::string yearStr = DateUtils::formatYear(2024);
        CHECK_EQUAL("2024", yearStr);
    }
    
    TEST(ParseYear) {
        int year = DateUtils::parseYear("2024");
        CHECK_EQUAL(2024, year);
        
        int invalidYear = DateUtils::parseYear("invalid");
        CHECK_EQUAL(0, invalidYear);
    }
    
    TEST(GetAge) {
        int age = DateUtils::getAge(1990);
        CHECK(age > 0);
        CHECK(age < 150);
    }
    
    TEST(IsYearInRange) {
        CHECK(DateUtils::isYearInRange(2020, 2010, 2030));
        CHECK(DateUtils::isYearInRange(2010, 2010, 2030));
        CHECK(DateUtils::isYearInRange(2030, 2010, 2030));
        CHECK(DateUtils::isYearInRange(2000, 2010, 2030) == false);
        CHECK(DateUtils::isYearInRange(2040, 2010, 2030) == false);
    }
    
    TEST(YearsBetween) {
        CHECK_EQUAL(10, DateUtils::yearsBetween(2020, 2010));
        CHECK_EQUAL(10, DateUtils::yearsBetween(2010, 2020));
        CHECK_EQUAL(0, DateUtils::yearsBetween(2020, 2020));
    }
}

