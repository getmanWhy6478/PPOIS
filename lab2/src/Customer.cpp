#include "../include/Customer.h"
#include "../include/Errors.h"
#include "../include/Payment.h"
#include <algorithm>

Customer::Customer() = default;

Customer::Customer(const string& name, int age, const string& email, int cash, Order order)
    : User(name, age, email, false), NotAuthorisedCustomer(order, cash), bonuses() {}

bool Customer::findBonus(Bonus bonus){
    return find(bonuses.begin(), bonuses.end(), bonus) != bonuses.end();
}
void Customer::useBonus(Bonus bonus) {
    if (banned)
        throw BannedUserError();
    else if (!findBonus(bonus) || bonus.isExpired()){
        throw BonusExpired();
    }
        cash += bonus.getDiscount();
}

void Customer::leaveRating(Restaurant& restaurant, Rating rating) {
    if (!banned)
        restaurant.addRating(rating);
    else{
        throw BannedUserError();
    }
}

void Customer::leaveComplaint(ComplaintBook& complaintBook, Complaint complaint) {
    if (!banned)
            complaintBook.addComplaint(complaint);
    else{
        throw BannedUserError();
    }
}

vector<Bonus> Customer::getBonuses() const {
    return bonuses;
}

void Customer::addBonus(Bonus bonus) {
    bonuses.push_back(bonus);
}


void Customer::clearBonuses(){
    bonuses.clear();
}
void Customer::useLoyaltyProgram(LoyaltyProgram& program){
    if(program.isActive() && loyaltypoints >= program.getMinPointsForReward()){
        cash += program.getRewardAmount();
        loyaltypoints -= program.getMinPointsForReward();
        program.deactivate();
    }
    else{
        throw LoyaltyProgramError();
    }
}