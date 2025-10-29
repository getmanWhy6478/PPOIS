#pragma once
#include <string>
using namespace std;
class Rating{
public:
    int getStars();
    void setStars(int stars);
    string getWords();
    void setWords(string words);
private:
    int stars;
    string words;
};