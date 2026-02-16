#pragma once

#include <string>

class DateUtils {
public:
    static std::string formatYear(int year);
    static int parseYear(const std::string& yearStr);
    static int getAge(int birthYear);
    static bool isYearInRange(int year, int startYear, int endYear);
    static int yearsBetween(int year1, int year2);
};

