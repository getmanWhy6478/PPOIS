#pragma once
#include <string>
#include <iostream>
using namespace std;
class DeliveryStatus {
public:

    DeliveryStatus();
    DeliveryStatus(const string& status, const string& updatedBy, const string& comment = "");

    string getStatus() const;
    string getLastUpdatedBy() const;
    string getComment() const;

    void updateStatus(string newStatus, const string& updatedBy, const string& comment = "");
    bool operator==(const DeliveryStatus& other) const; 
    friend std::ostream& operator<<(std::ostream& os, const DeliveryStatus& v) {
        os << "Vehicle(model: " << v.comment;
        return os;
    }
private:
    string currentStatus;
    string lastUpdatedBy;
    string comment;
};
