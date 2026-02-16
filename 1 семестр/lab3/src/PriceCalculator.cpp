#include "../include/PriceCalculator.h"
#include "../include/Artwork.h"
#include "../include/Membership.h"

double PriceCalculator::calculateTicketPrice(double basePrice, Membership* membership) {
    if (!membership || !membership->getIsActive()) {
        return basePrice;
    }
    
    int discount = membership->getDiscountPercentage();
    if (discount > 0 && discount <= 100) {
        return basePrice * (1.0 - discount / 100.0);
    }
    
    return basePrice;
}

double PriceCalculator::calculateOrderTotal(const std::vector<Artwork*>& artworks) {
    double total = 0.0;
    for (auto* artwork : artworks) {
        if (artwork) {
            total += artwork->getEstimatedValue();
        }
    }
    return total;
}

double PriceCalculator::calculateInsurancePremium(double artworkValue,
                                                   const std::string& coverageType) {
    double rate = 0.01;
    
    if (coverageType == "полная") {
        rate = 0.015; // 1.5%
    } else if (coverageType == "частичная") {
        rate = 0.01; // 1%
    }
    
    return artworkValue * rate;
}

double PriceCalculator::applyDiscount(double price, int discountPercentage) {
    if (discountPercentage < 0 || discountPercentage > 100) {
        return price;
    }
    return price * (1.0 - discountPercentage / 100.0);
}

double PriceCalculator::calculateShippingCost(double weight, const std::string& shippingMethod,
                                               double distance) {
    double baseCost = 0.0;
    double weightMultiplier = 1.0;
    double distanceMultiplier = 1.0;
    
    if (shippingMethod == "грузовик") {
        baseCost = 100.0;
        weightMultiplier = 0.5;
        distanceMultiplier = 0.1;
    } else if (shippingMethod == "самолет") {
        baseCost = 500.0;
        weightMultiplier = 2.0;
        distanceMultiplier = 0.5;
    } else if (shippingMethod == "корабль") {
        baseCost = 200.0;
        weightMultiplier = 0.3;
        distanceMultiplier = 0.05;
    }
    
    return baseCost + (weight * weightMultiplier) + (distance * distanceMultiplier);
}


