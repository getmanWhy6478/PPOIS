#include "../include/Ticket.h"
#include "../include/Visitor.h"
#include "../include/Exhibition.h"
#include <ctime>

Ticket::Ticket(const std::string& ticketNumber, Visitor* visitor,
               Exhibition* exhibition, double price)
    : ticketNumber(ticketNumber), visitor(visitor), exhibition(exhibition),
      price(price), isUsed(false) {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
}

std::string Ticket::getTicketNumber() const {
    return ticketNumber;
}

void Ticket::setTicketNumber(const std::string& number) {
    this->ticketNumber = number;
}

Visitor* Ticket::getVisitor() const {
    return visitor;
}

void Ticket::setVisitor(Visitor* visitor) {
    this->visitor = visitor;
}

Exhibition* Ticket::getExhibition() const {
    return exhibition;
}

void Ticket::setExhibition(Exhibition* exhibition) {
    this->exhibition = exhibition;
}

int Ticket::getVisitYear() const {
    return visitYear;
}

void Ticket::setVisitYear(int year) {
    this->visitYear = year;
}

double Ticket::getPrice() const {
    return price;
}

void Ticket::setPrice(double price) {
    this->price = price;
}

bool Ticket::getIsUsed() const {
    return isUsed;
}

void Ticket::setIsUsed(bool used) {
    this->isUsed = used;
}

void Ticket::useTicket() {
    isUsed = true;
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    visitYear = now->tm_year + 1900;
}

bool Ticket:: operator==(const Ticket& other) const {
        return ticketNumber == other.ticketNumber
            && visitor == other.visitor
            && exhibition == other.exhibition
            && visitYear == other.visitYear
            && price == other.price
            && isUsed == other.isUsed;
    }