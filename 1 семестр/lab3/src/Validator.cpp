#include "../include/Validator.h"
#include <regex>
#include <cctype>

bool Validator::isValidEmail(const std::string& email) {
    if (email.empty()) 
        return false;
    
    std::regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(email, pattern);
}

bool Validator::isValidPhone(const std::string& phone) {
    if (phone.empty()) return false;
    
    std::regex pattern(R"([+]?[0-9\s\-\(\)]{7,20})");
    return std::regex_match(phone, pattern);
}

bool Validator::isValidYear(int year) {
    return year >= 1000 && year <= 3000;
}

bool Validator::isValidPrice(double price) {
    return price >= 0.0;
}

bool Validator::isValidRating(int rating, int min, int max) {
    return rating >= min && rating <= max;
}

bool Validator::isValidPercentage(int percentage) {
    return percentage >= 0 && percentage <= 100;
}


