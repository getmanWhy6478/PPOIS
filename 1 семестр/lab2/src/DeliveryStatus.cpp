#include "../include/DeliveryStatus.h"

DeliveryStatus::DeliveryStatus()
    : currentStatus("Pending"), lastUpdatedBy("system"), comment("") {}

DeliveryStatus::DeliveryStatus(const string& status, const string& updatedBy, const string& comment)
    : currentStatus(status), lastUpdatedBy(updatedBy), comment(comment) {}

string DeliveryStatus::getStatus() const {
    return currentStatus;
}

string DeliveryStatus::getLastUpdatedBy() const {
    return lastUpdatedBy;
}

string DeliveryStatus::getComment() const {
    return comment;
}

void DeliveryStatus::updateStatus(string newStatus, const string& updatedBy, const string& comment) {
    currentStatus = newStatus;
    lastUpdatedBy = updatedBy;
    this->comment = comment;
}
bool DeliveryStatus::operator==(const DeliveryStatus& other) const {
    return currentStatus == other.currentStatus &&
           lastUpdatedBy == other.lastUpdatedBy &&
           comment == other.comment;
}