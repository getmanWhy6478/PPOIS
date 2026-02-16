#include "UnitTest++/UnitTest++.h"
#include "../include/Order.h"
#include "../include/Visitor.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"

SUITE(OrderTests) {
    TEST(OrderConstructor) {
        Visitor* customer = new Visitor("Alice", "Brown", "alice@example.com");
        Order* order = new Order("ORD001", customer);
        
        CHECK_EQUAL("ORD001", order->getOrderNumber());
        CHECK(order->getCustomer() == customer);
        CHECK_CLOSE(0.0, order->getTotalAmount(), 0.01);
        CHECK_EQUAL("pending", order->getStatus());
        
        delete order;
        delete customer;
    }
    
    TEST(OrderAddArtwork) {
        Visitor* customer = new Visitor("Charlie", "Wilson", "charlie@example.com");
        Order* order = new Order("ORD002", customer);
        Artist* artist = new Artist("Test", "Artist", "Unknown", 1900);
        Artwork* artwork1 = new Painting("Artwork 1", 2000, artist);
        Artwork* artwork2 = new Painting("Artwork 2", 2001, artist);
        
        artwork1->setEstimatedValue(1000.0);
        artwork2->setEstimatedValue(2000.0);
        
        order->addArtwork(artwork1);
        order->addArtwork(artwork2);
        
        std::vector<Artwork*> artworks = order->getArtworks();
        CHECK_EQUAL(2, artworks.size());
        CHECK_CLOSE(3000.0, order->getTotalAmount(), 0.01);
        
        delete order;
        delete artwork1;
        delete artwork2;
        delete artist;
        delete customer;
    }
    
    TEST(OrderStatus) {
        Visitor* customer = new Visitor("David", "Lee", "david@example.com");
        Order* order = new Order("ORD003", customer);
        
        order->setStatus("confirmed");
        
        CHECK_EQUAL("confirmed", order->getStatus());
        
        delete order;
        delete customer;
    }
}

