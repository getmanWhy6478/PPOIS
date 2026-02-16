#include "../include/Visitor.h"
#include "../include/Ticket.h"
#include "../include/Tour.h"
#include "../include/Event.h"
#include "../include/Artist.h"
#include "../include/Recommendation.h"
#include "Errors.h"
#include <ctime>
#include <algorithm>
#include <iostream>
Visitor::Visitor(const std::string& firstName, const std::string& lastName,
                 const std::string& email)
    : firstName(firstName), lastName(lastName), email(email),
      isMember(false), visitCount(0), birthYear(0) {
}

std::string Visitor::getFirstName() const {
    return firstName;
}

void Visitor::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

std::string Visitor::getLastName() const {
    return lastName;
}

void Visitor::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

std::string Visitor::getFullName() const {
    return firstName + " " + lastName;
}

std::string Visitor::getEmail() const {
    return email;
}

void Visitor::setEmail(const std::string& email) {
    this->email = email;
}

int Visitor::getBirthYear() const {
    return birthYear;
}

void Visitor::setBirthYear(int year) {
    this->birthYear = year;
}

void Visitor::addTicket(Ticket* ticket) {
    tickets.push_back(ticket);
}

std::vector<Ticket*> Visitor::getTickets() const {
    return tickets;
}

void Visitor::addTour(Tour* tour) {
    tours.push_back(tour);
}

std::vector<Tour*> Visitor::getTours() const {
    return tours;
}

bool Visitor::getIsMember() const {
    return isMember;
}

void Visitor::setIsMember(bool member) {
    this->isMember = member;
}

std::string Visitor::getMembershipType() const {
    return membershipType;
}

void Visitor::setMembershipType(const std::string& type) {
    this->membershipType = type;
}

int Visitor::getVisitCount() const {
    return visitCount;
}

void Visitor::incrementVisitCount() {
    visitCount++;
}

void Visitor:: useTicket(Ticket* ticket){
    if (find(tickets.begin(), tickets.end(), ticket) != tickets.end()){
        tickets.erase(std::remove(tickets.begin(), tickets.end(), ticket), tickets.end());;
    }
}
void Visitor:: visitTour(Tour* tour){
    tour->addVisitor(this);
}
void Visitor::watchPainting(){
    std::cout << "Wow!";
}
void Visitor::visitExhibition(Event* event){
    event->addAttendee(this);
}
Artist Visitor::getTooExcited(const std::string& nationality){
    Artist artist(this->firstName, this->lastName, nationality, this->birthYear);
    return artist;
}
double Visitor::getCash(){
    return cash;
}
void Visitor::setCash(double cash){
    this-> cash = cash;
}
void Visitor::vandolise(Artwork* artwork){
    delete artwork;
}
Recommendation Visitor::leaveRecommendation(std::string text){
    return Recommendation(text, this);
}
Ticket* Visitor::purchaseTicket(const std::string& ticketNumber,
                                Exhibition* exhibition,
                                double price, const std::string& paymentMethod) {
    if (ticketNumber.empty() || !exhibition || price <= 0.0) {
        return nullptr;
    }
    if (price > cash){
        PaymentFailedError();
    }
    cash -= price;
    Ticket* ticket = new Ticket(ticketNumber, this, exhibition, price);

    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    int currentYear = now->tm_year + 1900;

    addTicket(ticket);
    incrementVisitCount();
    return ticket;
}

