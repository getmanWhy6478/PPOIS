#pragma once

#include <string>

class Validator {
public:
    static bool isValidEmail(const std::string& email);
    static bool isValidPhone(const std::string& phone);
    static bool isValidYear(int year);
    static bool isValidPrice(double price);
    static bool isValidRating(int rating, int min = 1, int max = 10);
    static bool isValidPercentage(int percentage);
};

