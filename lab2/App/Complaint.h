#pragma once
#include <string>
#include "Restaurant.h"
using namespace std;
class Complaint{
public:
    string getBadWords() const;
    void setBadWords(string words);
private:
    string badWords;
};