#include "ComplaintBook.h"

ComplaintBook::ComplaintBook() = default;

ComplaintBook::ComplaintBook(const std::vector<Complaint>& initialComplaints)
    : complaints(initialComplaints) {}

std::vector<Complaint> ComplaintBook::getComplaints() const {
    return complaints;
}

void ComplaintBook::addComplaint(const Complaint& complaint) {
    complaints.push_back(complaint);
}

void ComplaintBook::clearComplaints() {
    complaints.clear();
}