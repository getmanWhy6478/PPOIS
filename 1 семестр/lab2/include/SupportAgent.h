#pragma once
#include <string>
#include <vector>
#include "Rating.h"
#include "Restaurant.h"
#include "User.h"
using namespace std;
class SupportAgent : public User {
public:
    SupportAgent();
    SupportAgent(const string& name, int age, const string& email);
    
    void banUser(User& user);
    void deleteRating(Rating& rating, Restaurant& restaurant);
};
