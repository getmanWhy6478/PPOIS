#pragma once
#include <string>
using namespace std;
class LoyaltyProgram {

public:
    LoyaltyProgram();
    LoyaltyProgram(const string& name, int minPoints, double reward);

    const string& getName() const;
    int getMinPointsForReward() const;
    double getRewardAmount() const;
    bool isActive() const;

    void deactivate();
    void activate();

    bool isEligible(int userPoints) const;
    double claimReward(int& userPoints);
private:
    string programName;
    int minPointsForReward;
    double rewardAmount;
    bool active;
};
