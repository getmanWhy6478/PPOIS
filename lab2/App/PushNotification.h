#pragma once
#include <string>
#include "User.h"
using namespace std;
class PushNotification {
public:
    
    string getWords() const;
    void setWords(const string& words);

    int getBonuses() const;
    void setBonuses(int bonuses);

    int getPromo() const;
    void setPromo(int promo);

private:
    PushNotification();

    PushNotification(const string& words, int bonuses, int promo);
    string words;
    int bonuses;
    int promo;

    friend class PushService;
};
