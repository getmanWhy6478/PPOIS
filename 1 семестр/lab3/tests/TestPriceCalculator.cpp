#include "UnitTest++/UnitTest++.h"
#include "../include/PriceCalculator.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"
#include "../include/Membership.h"
#include "../include/Visitor.h"

SUITE(PriceCalculatorTests) {
    TEST(CalculateTicketPriceWithoutMembership) {
        double basePrice = 20.0;
        double price = PriceCalculator::calculateTicketPrice(basePrice, nullptr);
        CHECK_CLOSE(20.0, price, 0.01);
    }
    
    TEST(CalculateTicketPriceWithMembership) {
        Visitor* visitor = new Visitor("John", "Doe", "john@example.com");
        Membership* membership = new Membership("MEM001", visitor, "Premium");
        membership->setDiscountPercentage(20);
        membership->setIsActive(true);
        
        double basePrice = 20.0;
        double price = PriceCalculator::calculateTicketPrice(basePrice, membership);
        CHECK_CLOSE(16.0, price, 0.01);
        
        delete membership;
        delete visitor;
    }
    
    TEST(CalculateOrderTotal) {
        Artist* artist = new Artist("Test", "Artist", "Unknown", 1900);
        Artwork* artwork1 = new Painting("Art 1", 2000, artist);
        Artwork* artwork2 = new Painting("Art 2", 2001, artist);
        
        artwork1->setEstimatedValue(1000.0);
        artwork2->setEstimatedValue(2000.0);
        
        std::vector<Artwork*> artworks = {artwork1, artwork2};
        double total = PriceCalculator::calculateOrderTotal(artworks);
        
        CHECK_CLOSE(3000.0, total, 0.01);
        
        delete artwork1;
        delete artwork2;
        delete artist;
    }
    
    TEST(CalculateInsurancePremium) {
        double artworkValue = 1000000.0;
        double premium1 = PriceCalculator::calculateInsurancePremium(artworkValue, "полная");
        double premium2 = PriceCalculator::calculateInsurancePremium(artworkValue, "частичная");
        
        CHECK_CLOSE(15000.0, premium1, 0.01);
        CHECK_CLOSE(10000.0, premium2, 0.01);
    }
    
    TEST(ApplyDiscount) {
        double price = 100.0;
        double discounted = PriceCalculator::applyDiscount(price, 25);
        CHECK_CLOSE(75.0, discounted, 0.01);
        
        double noDiscount = PriceCalculator::applyDiscount(price, 0);
        CHECK_CLOSE(100.0, noDiscount, 0.01);
    }
    
    TEST(CalculateShippingCost) {
        double cost1 = PriceCalculator::calculateShippingCost(100.0, "грузовик", 500.0);
        double cost2 = PriceCalculator::calculateShippingCost(100.0, "самолет", 1000.0);
        double cost3 = PriceCalculator::calculateShippingCost(100.0, "корабль", 2000.0);
        
        CHECK(cost1 > 0);
        CHECK(cost2 > cost1);
        CHECK(cost3 > 0);
    }
}

