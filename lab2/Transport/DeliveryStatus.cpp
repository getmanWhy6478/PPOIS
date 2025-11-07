#include "DeliveryStatus.h"

DeliveryStatus::DeliveryStatus()
    : currentStatus(Status::Pending), lastUpdatedBy("system"), comment("") {}

DeliveryStatus::DeliveryStatus(Status status, const string& updatedBy, const string& comment)
    : currentStatus(status), lastUpdatedBy(updatedBy), comment(comment) {}

DeliveryStatus::Status DeliveryStatus::getStatus() const {
    return currentStatus;
}

const string& DeliveryStatus::getLastUpdatedBy() const {
    return lastUpdatedBy;
}

const string& DeliveryStatus::getComment() const {
    return comment;
}

void DeliveryStatus::updateStatus(Status newStatus, const string& updatedBy, const string& comment) {
    currentStatus = newStatus;
    lastUpdatedBy = updatedBy;
    this->comment = comment;
}

string DeliveryStatus::statusToString() const {
    return statusToString(currentStatus);
}

string DeliveryStatus::statusToString(Status status) {
    switch (status) {
        case Status::Pending: return "Pending";
        case Status::Accepted: return "Accepted";
        case Status::Preparing: return "Preparing";
        case Status::OutForDelivery: return "Out for Delivery";
        case Status::Delivered: return "Delivered";
        case Status::Cancelled: return "Cancelled";
        case Status::Failed: return "Failed";
        default: return "Unknown";
    }
}
