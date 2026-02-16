#pragma once

#include <string>
#include <vector>
#include "Gallery.h"
#include "Visitor.h"

class Event {
private:
    std::string eventId;
    std::string title;
    std::string description;
    Gallery* gallery;
    int durationMinutes;
    std::vector<Visitor*> attendees;
    int maxCapacity;
    double ticketPrice;

public:
    Event() = default;
    Event(const std::string& eventId, const std::string& title,
          Gallery* gallery);
    ~Event() = default;
    
    std::string getEventId() const;
    void setEventId(const std::string& id);
    std::string getTitle() const;
    void setTitle(const std::string& title);
    std::string getDescription() const;
    void setDescription(const std::string& description);
    Gallery* getGallery() const;
    void setGallery(Gallery* gallery);
    int getEventYear() const;
    void setEventYear(int year);
    int getDurationMinutes() const;
    void setDurationMinutes(int minutes);
    void addAttendee(Visitor* attendee);
    std::vector<Visitor*> getAttendees() const;
    int getMaxCapacity() const;
    void setMaxCapacity(int capacity);
    bool isFull() const;
    double getTicketPrice() const;
    void setTicketPrice(double price);
};

