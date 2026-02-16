#pragma once

#include <vector>
#include "Artwork.h"
#include "Membership.h"

class PriceCalculator {
public:
    static double calculateTicketPrice(double basePrice, Membership* membership);
    static double calculateOrderTotal(const std::vector<Artwork*>& artworks);
    static double calculateInsurancePremium(double artworkValue, 
                                            const std::string& coverageType);
    static double applyDiscount(double price, int discountPercentage);
    static double calculateShippingCost(double weight, 
                                       const std::string& shippingMethod,
                                       double distance);
};

