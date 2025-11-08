#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class DeliveryRoute {
public:
    DeliveryRoute();
    DeliveryRoute(const string& startPoint, const string& endPoint, double totalDistance);

    string getStartPoint() const;

    string getEndPoint() const;

    double getTotalDistance() const;
    
    void setStartPoint(const string& point);

    void setEndPoint(const string& point);

    void setTotalDistance(double distance);
    bool operator==(const DeliveryRoute& other) const;
    friend std::ostream& operator<<(std::ostream& os, const DeliveryRoute& v) {
        os << "Route: " << v.totalDistance;
        return os;
    }
private:
    string startPoint;
    string endPoint;
    double totalDistance;
};
