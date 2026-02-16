#include "UnitTest++/UnitTest++.h"
#include "../include/Visitor.h"
#include "../include/Ticket.h"
#include "../include/Exhibition.h"
#include "../include/Gallery.h"
#include "../include/Artist.h"

SUITE(VisitorTests) {
    TEST(VisitorConstructor) {
        Visitor* visitor = new Visitor("John", "Doe", "john@example.com");
        
        CHECK_EQUAL("John", visitor->getFirstName());
        CHECK_EQUAL("Doe", visitor->getLastName());
        CHECK_EQUAL("John Doe", visitor->getFullName());
        CHECK_EQUAL("john@example.com", visitor->getEmail());
        CHECK(visitor->getIsMember() == false);
        CHECK_EQUAL(0, visitor->getVisitCount());
        
        delete visitor;
    }
    
    TEST(VisitorSetters) {
        Visitor* visitor = new Visitor("J", "S", "jane@e.com");
        
        visitor->setBirthYear(1990);
        visitor->setIsMember(true);
        visitor->setMembershipType("Premium");
        visitor->setFirstName("Jane");
        visitor->setLastName("Smith");
        visitor->setEmail("jane@example.com");
        
        CHECK_EQUAL(1990, visitor->getBirthYear());
        CHECK(visitor->getIsMember());
        CHECK_EQUAL("Premium", visitor->getMembershipType());
        
        delete visitor;
    }
    
    TEST(VisitorIncrementVisitCount) {
        Visitor* visitor = new Visitor("Bob", "Johnson", "bob@example.com");
        
        CHECK_EQUAL(0, visitor->getVisitCount());
        visitor->incrementVisitCount();
        CHECK_EQUAL(1, visitor->getVisitCount());
        visitor->incrementVisitCount();
        CHECK_EQUAL(2, visitor->getVisitCount());
        
        delete visitor;
    }

    TEST(VisitorPurchaseTicket) {
        Gallery* gallery = new Gallery("Rijksmuseum", "Museumstraat 1", "Amsterdam", "Netherlands");
        Exhibition* exhibition = new Exhibition("Dutch Masters", gallery, 2024, 2025);
        Visitor* visitor = new Visitor("Eva", "Vermeer", "eva@example.com");

        Ticket* ticket = visitor->purchaseTicket("TICK-001", exhibition, 20.0, "card");

        CHECK(ticket != nullptr);
        CHECK_EQUAL(1, visitor->getTickets().size());
        CHECK_EQUAL(visitor, ticket->getVisitor());
        CHECK_EQUAL(exhibition, ticket->getExhibition());
        CHECK_EQUAL(1, visitor->getVisitCount());
        visitor->leaveRecommendation("Супер-пупер-шмупер!");

        delete ticket;
        delete visitor;
        delete exhibition;
        delete gallery;
    }
    TEST(GetTooExcitedCreatesArtistFromVisitor) {
        Visitor v("Иван", "Иванов", "meow@mail.ru");
        v.setBirthYear(1985);
        Artist a = v.getTooExcited("Беларусь");

        CHECK_EQUAL("Иван", a.getFirstName());
        CHECK_EQUAL("Иванов", a.getLastName());
        CHECK_EQUAL("Беларусь", a.getNationality());
        CHECK_EQUAL(1985, a.getBirthYear());
    }
}

