#include "../include/ComplaintBook.h"

ComplaintBook::ComplaintBook() = default;

ComplaintBook::ComplaintBook(const vector<Complaint>& initialComplaints)
    : complaints(initialComplaints) {}

vector<Complaint> ComplaintBook::getComplaints() const {
    return complaints;
}

void ComplaintBook::addComplaint(const Complaint& complaint) {
    complaints.push_back(complaint);
}

void ComplaintBook::clearComplaints() {
    complaints.clear();
}