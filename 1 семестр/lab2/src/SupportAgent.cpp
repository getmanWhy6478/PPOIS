#include "../include/SupportAgent.h"
#include <algorithm>
SupportAgent::SupportAgent()
    : User(){}

SupportAgent::SupportAgent(const string& name, int age, const string& email)
    : User(name, age, email, false){}

void SupportAgent::banUser(User& user){
    user.setBanned(true);
};
void SupportAgent::deleteRating(Rating& rating, Restaurant& restaurant){
    auto begin = restaurant.ratings.begin();
    auto end = restaurant.ratings.end();
    auto newEnd = remove(begin, end, rating);
    restaurant.ratings.erase(newEnd, end);
}
