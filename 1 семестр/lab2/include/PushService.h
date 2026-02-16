#pragma once
#include <string>
#include "PushNotification.h"
#include "User.h"
using namespace std;
class PushService{
public:
    PushService();
    PushService(const std::string& language);

    string getLanguage() const;
    void setLanguage(const string& language);
    
    PushNotification createPushNotification(const string& words, int bonuses, int promo);
private:
    string language;
};