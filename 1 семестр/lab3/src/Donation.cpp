#include "../include/Donation.h"
#include "../include/Artwork.h"
#include "../include/Collector.h"
#include <ctime>

Donation::Donation(const std::string& donationId, Collector* donor,
                   const std::string& recipientInstitution)
    : donationId(donationId), donor(donor), recipientInstitution(recipientInstitution),
      estimatedValue(0.0) {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
}

std::string Donation::getDonationId() const {
    return donationId;
}

void Donation::setDonationId(const std::string& id) {
    this->donationId = id;
}

void Donation::addDonatedArtwork(Artwork* artwork) {
    donatedArtworks.push_back(artwork);
    if (artwork) {
        estimatedValue += artwork->getEstimatedValue();
    }
}

std::vector<Artwork*> Donation::getDonatedArtworks() const {
    return donatedArtworks;
}

Collector* Donation::getDonor() const {
    return donor;
}

void Donation::setDonor(Collector* donor) {
    this->donor = donor;
}

std::string Donation::getRecipientInstitution() const {
    return recipientInstitution;
}

void Donation::setRecipientInstitution(const std::string& institution) {
    this->recipientInstitution = institution;
}

double Donation::getEstimatedValue() const {
    return estimatedValue;
}

void Donation::setEstimatedValue(double value) {
    this->estimatedValue = value;
}

