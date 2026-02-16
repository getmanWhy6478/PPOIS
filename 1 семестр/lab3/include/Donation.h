#pragma once

#include <string>
#include <vector>
#include "Artwork.h"
#include "Collector.h"

class Donation {
private:
    std::string donationId;
    std::vector<Artwork*> donatedArtworks;
    Collector* donor;
    std::string recipientInstitution;
    double estimatedValue;

public:
    Donation() = default;
    Donation(const std::string& donationId, Collector* donor,
             const std::string& recipientInstitution);
    ~Donation() = default;
    
    std::string getDonationId() const;
    void setDonationId(const std::string& id);
    void addDonatedArtwork(Artwork* artwork);
    std::vector<Artwork*> getDonatedArtworks() const;
    Collector* getDonor() const;
    void setDonor(Collector* donor);
    std::string getRecipientInstitution() const;
    void setRecipientInstitution(const std::string& institution);
    double getEstimatedValue() const;
    void setEstimatedValue(double value);
};

