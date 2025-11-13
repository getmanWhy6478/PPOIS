#pragma once
#include <string>
using namespace std;
class Complaint{
public:
    Complaint();
    Complaint(string badWords);
    
    string getBadWords() const;
    void setBadWords(string words);
private:
    string badWords;
};