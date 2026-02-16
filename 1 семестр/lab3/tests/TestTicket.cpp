#include "UnitTest++/UnitTest++.h"
#include "../include/Ticket.h"
#include "../include/Visitor.h"
#include "../include/Exhibition.h"
#include "../include/Gallery.h"

SUITE(TicketTests) {
    TEST(TicketConstructor) {
        Gallery* gallery = new Gallery("Louvre", "Rue de Rivoli", "Paris", "France");
        Exhibition* exhibition = new Exhibition("Renaissance", gallery, 2024, 2024);
        Visitor* visitor = new Visitor("John", "Doe", "john@example.com");
        Ticket* ticket = new Ticket("T000", visitor, exhibition, 15.0);
        ticket->setTicketNumber("T001");
        visitor = ticket->getVisitor();
        
        CHECK_EQUAL("T001", ticket->getTicketNumber());
        CHECK(ticket->getVisitor() == visitor);
        CHECK(ticket->getExhibition() == exhibition);
        CHECK_CLOSE(15.0, ticket->getPrice(), 0.01);
        CHECK(ticket->getIsUsed() == false);
        
        delete ticket;
        delete visitor;
        delete exhibition;
        delete gallery;
    }
    
    TEST(TicketUse) {
        Gallery* gallery = new Gallery("Met", "1000 5th Ave", "New York", "USA");
        Exhibition* exhibition = new Exhibition("Ancient Art", gallery, 2024, 2024);
        Visitor* visitor = new Visitor("Jane", "Smith", "jane@example.com");
        Ticket* ticket = new Ticket("T002", visitor, exhibition, 20.0);
        
        CHECK(ticket->getIsUsed() == false);
        ticket->useTicket();
        CHECK(ticket->getIsUsed());
        
        delete ticket;
        delete visitor;
        delete exhibition;
        delete gallery;
    }
    
    TEST(TicketSetters) {
        Gallery* gallery = new Gallery("Tate", "Bankside", "London", "UK");
        Exhibition* exhibition = new Exhibition("Modern Art", gallery, 2024, 2024);
        Visitor* visitor = new Visitor("Bob", "Johnson", "bob@example.com");
        Ticket* ticket = new Ticket("T003", visitor, exhibition, 18.0);
        
        ticket->setVisitYear(2024);
        CHECK_EQUAL(2024, ticket->getVisitYear());
        
        delete ticket;
        delete visitor;
        delete exhibition;
        delete gallery;
    }
}

