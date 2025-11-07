#pragma once
#include <vector>
#include <string>
using namespace std;
class DeliveryRoute {
private:
    string startPoint;
    string endPoint;
    double totalDistance;

public:
    DeliveryRoute();
    DeliveryRoute(const string& startPoint, const string& endPoint, double totalDistance);

    const string& getStartPoint() const;

    const string& getEndPoint() const;

    double getTotalDistance() const;
    
    void setStartPoint(const string& point);

    void setEndPoint(const string& point);

    void setTotalDistance(double distance);
};
