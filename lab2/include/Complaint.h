#pragma once
#include <string>
using namespace std;
class Complaint{
public:
    string getBadWords() const;
    void setBadWords(string words);
private:
    string badWords;
};