#include "../include/Order.h"
#include "../include/Artwork.h"
#include "../include/Visitor.h"
#include <ctime>

Order::Order(const std::string& orderNumber, Visitor* customer)
    : orderNumber(orderNumber), customer(customer), totalAmount(0.0),
      status("pending") {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    orderYear = now->tm_year + 1900;
}

std::string Order::getOrderNumber() const {
    return orderNumber;
}

void Order::setOrderNumber(const std::string& number) {
    this->orderNumber = number;
}

Visitor* Order::getCustomer() const {
    return customer;
}

void Order::setCustomer(Visitor* customer) {
    this->customer = customer;
}

void Order::addArtwork(Artwork* artwork) {
    artworks.push_back(artwork);
    calculateTotalAmount();
}

std::vector<Artwork*> Order::getArtworks() const {
    return artworks;
}

int Order::getOrderYear() const {
    return orderYear;
}

void Order::setOrderYear(int year) {
    this->orderYear = year;
}

double Order::getTotalAmount() const {
    return totalAmount;
}

void Order::calculateTotalAmount() {
    totalAmount = 0.0;
    for (auto* artwork : artworks) {
        if (artwork) {
            totalAmount += artwork->getEstimatedValue();
        }
    }
}

std::string Order::getStatus() const {
    return status;
}

void Order::setStatus(const std::string& status) {
    this->status = status;
}

