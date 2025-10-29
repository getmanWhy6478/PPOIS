#pragma once
#include <string>
#include "User.h"
using namespace std;
class PushNotififcation{
public:
    string getWords();
    void setWords (string words);
    int getBonuses();
    void setBonuses (int bonuses);
    int getPromo();
    void setPromo (int promo);
private:
    PushNotififcation(const string & words, int bonuses, int promo);
    string words;
    int bonuses;
    int promo;
friend class PushService;
};