#include "../include/Payment.h"

Payment::Payment()
    : amount(0.0), method("unknown"), currency("BYN"), times(time(nullptr)), confirmed(false) {}

Payment::Payment(double amount, const string& method, const string& currency)
    : amount(amount), method(method), currency(currency), times(time(nullptr)), confirmed(false) {}

double Payment::getAmount() const {
    return amount;
}

string Payment::getMethod() const {
    return method;
}

string Payment::getCurrency() const {
    return currency;
}

time_t Payment::getTime() const {
    return times;
}

bool Payment::isConfirmed() const {
    return confirmed;
}

void Payment::setAmount(double amount) {
    this->amount = amount;
}

void Payment::setMethod(const string& method) {
    this->method = method;
}

void Payment::setCurrency(const string& currency) {
    this->currency = currency;
}

void Payment::confirm() {
    confirmed = true;
}
