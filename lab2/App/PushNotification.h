#pragma once
#include <string>
#include "User.h"

class PushNotification {
public:
    
    std::string getWords() const;
    void setWords(const std::string& words);

    int getBonuses() const;
    void setBonuses(int bonuses);

    int getPromo() const;
    void setPromo(int promo);

private:
    PushNotification();

    PushNotification(const std::string& words, int bonuses, int promo);
    std::string words;
    int bonuses;
    int promo;

    friend class PushService;
};
