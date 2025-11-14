#pragma once
#include <string>
#include <vector>
#include "Complaint.h"
using namespace std;
class ComplaintBook{
public:
    ComplaintBook();
    ComplaintBook(const std::vector<Complaint>& initialComplaints);

    void addComplaint(const Complaint& complaint);
    vector<Complaint> getComplaints() const;
    void clearComplaints();
private:
    vector<Complaint> complaints;
};