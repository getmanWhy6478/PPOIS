#pragma once
#include <string>
#include "PushNotification.h"
#include "User.h"
using namespace std;
class PushService{
public:
    string getLanguage();
    void setLanguage(string language);
    void createPushNotification(User& user, string words, int bonuses, int promo);
private:
    string language;
};