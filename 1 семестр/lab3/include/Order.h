#pragma once

#include <string>
#include <vector>
#include "Artwork.h"
#include "Visitor.h"

class Order {
private:
    std::string orderNumber;
    Visitor* customer;
    std::vector<Artwork*> artworks;
    int orderYear;
    double totalAmount;
    std::string status;

public:
    Order() = default;
    Order(const std::string& orderNumber, Visitor* customer);
    ~Order() = default;
    
    std::string getOrderNumber() const;
    void setOrderNumber(const std::string& number);
    Visitor* getCustomer() const;
    void setCustomer(Visitor* customer);
    void addArtwork(Artwork* artwork);
    std::vector<Artwork*> getArtworks() const;
    int getOrderYear() const;
    void setOrderYear(int year);
    double getTotalAmount() const;
    void calculateTotalAmount();
    std::string getStatus() const;
    void setStatus(const std::string& status);
};

