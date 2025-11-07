#pragma once
#include <string>
using namespace std;
class LoyaltyProgram {
private:
    string programName;
    int minPointsForReward;
    double rewardAmount;
    bool active;
public:
    LoyaltyProgram(const string& name, int minPoints, double reward);

    const string& getName() const;
    int getMinPointsForReward() const;
    double getRewardAmount() const;
    bool isActive() const;

    void deactivate();
    void activate();

    bool isEligible(int userPoints) const;
    double claimReward(int& userPoints);
};
