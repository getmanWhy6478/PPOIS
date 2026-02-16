#pragma once

#include <string>
#include "Visitor.h"
#include "Exhibition.h"

class Ticket {
private:
    std::string ticketNumber;
    Visitor* visitor;
    Exhibition* exhibition;
    int visitYear;
    double price;
    bool isUsed;

public:
    Ticket() = default;
    Ticket(const std::string& ticketNumber, Visitor* visitor,
           Exhibition* exhibition, double price);
    ~Ticket() = default;
    
    std::string getTicketNumber() const;
    void setTicketNumber(const std::string& number);
    Visitor* getVisitor() const;
    void setVisitor(Visitor* visitor);
    Exhibition* getExhibition() const;
    void setExhibition(Exhibition* exhibition);
    int getVisitYear() const;
    void setVisitYear(int year);
    double getPrice() const;
    void setPrice(double price);
    bool getIsUsed() const;
    void setIsUsed(bool used);
    void useTicket();
    bool operator==(const Ticket& other) const;
};

