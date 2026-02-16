#include "../include/Event.h"
#include "../include/Gallery.h"
#include "../include/Visitor.h"

Event::Event(const std::string& eventId, const std::string& title,
             Gallery* gallery)
    : eventId(eventId), title(title), gallery(gallery), maxCapacity(0),
      ticketPrice(0.0), durationMinutes(0) {
}

std::string Event::getEventId() const {
    return eventId;
}

void Event::setEventId(const std::string& id) {
    this->eventId = id;
}

std::string Event::getTitle() const {
    return title;
}

void Event::setTitle(const std::string& title) {
    this->title = title;
}

std::string Event::getDescription() const {
    return description;
}

void Event::setDescription(const std::string& description) {
    this->description = description;
}

Gallery* Event::getGallery() const {
    return gallery;
}

void Event::setGallery(Gallery* gallery) {
    this->gallery = gallery;
}

int Event::getDurationMinutes() const {
    return durationMinutes;
}

void Event::setDurationMinutes(int minutes) {
    this->durationMinutes = minutes;
}

void Event::addAttendee(Visitor* attendee) {
    attendees.push_back(attendee);
}

std::vector<Visitor*> Event::getAttendees() const {
    return attendees;
}

int Event::getMaxCapacity() const {
    return maxCapacity;
}

void Event::setMaxCapacity(int capacity) {
    this->maxCapacity = capacity;
}

bool Event::isFull() const {
    if (maxCapacity <= 0) return false;
    return attendees.size() >= static_cast<size_t>(maxCapacity);
}

double Event::getTicketPrice() const {
    return ticketPrice;
}

void Event::setTicketPrice(double price) {
    this->ticketPrice = price;
}


