#pragma once

#include <string>
#include <vector>
#include "Ticket.h"
#include "Event.h"
#include "Recommendation.h"
class Exhibition;
class Tour;
class Ticket;
class Event;
class Recommendation;
class Visitor {
private:
    std::string firstName;
    std::string lastName;
    std::string email;
    int birthYear;
    std::vector<Ticket*> tickets;
    std::vector<Tour*> tours;
    bool isMember;
    std::string membershipType;
    int visitCount;
    double cash;

public:
    Visitor() = default;
    Visitor(const std::string& firstName, const std::string& lastName, 
            const std::string& email);
    ~Visitor() = default;
    
    std::string getFirstName() const;
    void setFirstName(const std::string& firstName);

    std::string getLastName() const;
    void setLastName(const std::string& lastName);

    std::string getFullName() const;

    std::string getEmail() const;
    void setEmail(const std::string& email);

    int getBirthYear() const;
    void setBirthYear(int year);

    void addTicket(Ticket* ticket);
    std::vector<Ticket*> getTickets() const;

    void addTour(Tour* tour);
    std::vector<Tour*> getTours() const;

    bool getIsMember() const;
    void setIsMember(bool member);

    void useTicket(Ticket* ticket);
    void visitTour(Tour* tour);
    void watchPainting();
    void visitExhibition(Event* event);
    std::string getMembershipType() const;
    void setMembershipType(const std::string& type);

    int getVisitCount() const;
    void incrementVisitCount();

    double getCash();
    void setCash(double cash);

    Artist getTooExcited(const std::string& nationality);
    Recommendation leaveRecommendation(std::string text);
    void vandolise(Artwork* artwork);

    Ticket* purchaseTicket(const std::string& ticketNumber, Exhibition* exhibition,
                           double price, const std::string& paymentMethod);
};

