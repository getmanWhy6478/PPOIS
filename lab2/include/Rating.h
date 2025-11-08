#pragma once
#include <string>
using namespace std;
class Rating{
public:
    Rating();
    Rating(int stars, const std::string& words);

    int getStars() const;
    void setStars(int stars);

    string getWords() const;
    void setWords(const string& words);

    bool operator==(const Rating& other) const;

private:
    int stars;
    string words;
};