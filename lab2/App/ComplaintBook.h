#pragma once
#include <string>
#include <vector>
#include "Complaint.h"
using namespace std;
class ComplaintBook{
public:
    vector<Complaint> getComplaints();
private:
    vector<Complaint> complaints;
friend class Customer;
};