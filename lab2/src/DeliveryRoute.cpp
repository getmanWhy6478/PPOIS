#include "../include/DeliveryRoute.h"

DeliveryRoute::DeliveryRoute()
    : startPoint(""), endPoint(""), totalDistance(0.0){}

DeliveryRoute::DeliveryRoute(const string& startPoint, const string& endPoint, double totalDistance)
    : startPoint(startPoint), endPoint(endPoint), totalDistance(totalDistance) {}

string DeliveryRoute::getStartPoint() const {
    return startPoint;
}

string DeliveryRoute::getEndPoint() const {
    return endPoint;
}

double DeliveryRoute::getTotalDistance() const {
    return totalDistance;
}

void DeliveryRoute::setStartPoint(const string& point) {
    startPoint = point;
}

void DeliveryRoute::setEndPoint(const string& point) {
    endPoint = point;
}

void DeliveryRoute::setTotalDistance(double distance) {
    totalDistance = distance;
}
bool DeliveryRoute:: operator==(const DeliveryRoute& other) const {
        return startPoint == other.startPoint &&
               endPoint == other.endPoint &&
               totalDistance == other.totalDistance;
}