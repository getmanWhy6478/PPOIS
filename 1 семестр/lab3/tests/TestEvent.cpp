#include "UnitTest++/UnitTest++.h"
#include "../include/Event.h"
#include "../include/Gallery.h"
#include "../include/Visitor.h"

SUITE(EventTests) {
    TEST(EventConstructor) {
        Gallery* gallery = new Gallery("MoMA", "11 W 53rd St", "New York", "USA");
        Event* event = new Event("EVT001", "Opening Night", gallery);
        
        CHECK_EQUAL("EVT001", event->getEventId());
        CHECK_EQUAL("Opening Night", event->getTitle());
        CHECK(event->getGallery() == gallery);
        
        delete event;
        delete gallery;
    }
    
    TEST(EventSetters) {
        Gallery* gallery = new Gallery("Tate", "Bankside", "London", "UK");
        Event* event = new Event("EVT002", "Art Lecture", gallery);
        
        event->setDescription("Evening lecture on modern art");
        event->setDurationMinutes(90);
        event->setMaxCapacity(100);
        event->setTicketPrice(15.0);
        
        CHECK_EQUAL("Evening lecture on modern art", event->getDescription());
        CHECK_EQUAL(90, event->getDurationMinutes());
        CHECK_EQUAL(100, event->getMaxCapacity());
        CHECK_CLOSE(15.0, event->getTicketPrice(), 0.01);
        
        delete event;
        delete gallery;
    }
    
    TEST(EventIsFull) {
        Gallery* gallery = new Gallery("Louvre", "Rue de Rivoli", "Paris", "France");
        Event* event = new Event("EVT003", "Workshop", gallery);
        
        event->setMaxCapacity(2);
        CHECK(event->isFull() == false);
        
        Visitor* v1 = new Visitor("John", "Doe", "john@example.com");
        Visitor* v2 = new Visitor("Jane", "Smith", "jane@example.com");
        
        event->addAttendee(v1);
        CHECK(event->isFull() == false);
        
        event->addAttendee(v2);
        CHECK(event->isFull());
        
        delete event;
        delete v1;
        delete v2;
        delete gallery;
    }
}

