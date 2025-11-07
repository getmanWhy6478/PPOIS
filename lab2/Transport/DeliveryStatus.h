#pragma once
#include <string>
using namespace std;
class DeliveryStatus {
public:
    enum class Status {
        Pending,
        Accepted,
        Preparing,
        OutForDelivery,
        Delivered,
        Cancelled,
        Failed
    };
    DeliveryStatus();
    DeliveryStatus(Status status, const string& updatedBy, const string& comment = "");

    Status getStatus() const;
    const string& getLastUpdatedBy() const;
    const string& getComment() const;

    void updateStatus(Status newStatus, const string& updatedBy, const string& comment = "");
    string statusToString() const;
    static string statusToString(Status status);
private:
    Status currentStatus;
    string lastUpdatedBy;
    string comment;
};
