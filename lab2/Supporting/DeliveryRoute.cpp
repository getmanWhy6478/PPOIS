#include "DeliveryRoute.h"

DeliveryRoute::DeliveryRoute()
    : startPoint(""), endPoint(""), totalDistance(0.0){}

DeliveryRoute::DeliveryRoute(const std::string& startPoint, const std::string& endPoint, double totalDistance)
    : startPoint(startPoint), endPoint(endPoint), totalDistance(totalDistance) {}

const std::string& DeliveryRoute::getStartPoint() const {
    return startPoint;
}

const std::string& DeliveryRoute::getEndPoint() const {
    return endPoint;
}

double DeliveryRoute::getTotalDistance() const {
    return totalDistance;
}

void DeliveryRoute::setStartPoint(const std::string& point) {
    startPoint = point;
}

void DeliveryRoute::setEndPoint(const std::string& point) {
    endPoint = point;
}

void DeliveryRoute::setTotalDistance(double distance) {
    totalDistance = distance;
}
