#include "../include/LoyaltyProgram.h"

LoyaltyProgram::LoyaltyProgram()
    : programName(""), minPointsForReward(0), rewardAmount(0), active(true) {}


LoyaltyProgram::LoyaltyProgram(const string& name, int minPoints, double reward)
    : programName(name), minPointsForReward(minPoints), rewardAmount(reward), active(true) {}

const string& LoyaltyProgram::getName() const {
    return programName;
}

int LoyaltyProgram::getMinPointsForReward() const {
    return minPointsForReward;
}

double LoyaltyProgram::getRewardAmount() const {
    return rewardAmount;
}

bool LoyaltyProgram::isActive() const {
    return active;
}

void LoyaltyProgram::deactivate() {
    active = false;
}

void LoyaltyProgram::activate() {
    active = true;
}

bool LoyaltyProgram::isEligible(int userPoints) const {
    return active && userPoints >= minPointsForReward;
}

double LoyaltyProgram::claimReward(int& userPoints) {
    if (isEligible(userPoints)) {
        userPoints -= minPointsForReward;
        return rewardAmount;
    }
    return 0.0;
}
