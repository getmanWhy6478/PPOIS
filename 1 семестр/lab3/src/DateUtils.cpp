#include "../include/DateUtils.h"
#include <sstream>
#include <ctime>

std::string DateUtils::formatYear(int year) {
    std::ostringstream oss;
    oss << year;
    return oss.str();
}

int DateUtils::parseYear(const std::string& yearStr) {
    try {
        return std::stoi(yearStr);
    } catch (...) {
        return 0;
    }
}

int DateUtils::getAge(int birthYear) {
    if (birthYear <= 0) return 0;
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    int currentYear = now->tm_year + 1900;
    return currentYear - birthYear;
}

bool DateUtils::isYearInRange(int year, int startYear, int endYear) {
    return year >= startYear && year <= endYear;
}

int DateUtils::yearsBetween(int year1, int year2) {
    if (year1 > year2) {
        return year1 - year2;
    }
    return year2 - year1;
}


