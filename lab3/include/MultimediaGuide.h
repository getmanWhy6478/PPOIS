#pragma once

#include <string>
#include <vector>
#include "Artwork.h"
#include "Exhibition.h"

// Класс для мультимедийного гида
class MultimediaGuide {
private:
    std::string guideId;
    std::string guideName;
    std::string language;
    std::vector<Artwork*> coveredArtworks;
    Exhibition* exhibition;
    int durationMinutes;
    bool isAvailable;
    int totalRentals;
    double averageRating;

public:
    MultimediaGuide() = default;
    MultimediaGuide(const std::string& guideId, const std::string& guideName,
                    const std::string& language);
    ~MultimediaGuide() = default;
    
    std::string getGuideId() const;
    void setGuideId(const std::string& id);
    std::string getGuideName() const;
    void setGuideName(const std::string& name);
    std::string getLanguage() const;
    void setLanguage(const std::string& language);
    void addCoveredArtwork(Artwork* artwork);
    std::vector<Artwork*> getCoveredArtworks() const;
    Exhibition* getExhibition() const;
    void setExhibition(Exhibition* exhibition);
    int getDurationMinutes() const;
    void setDurationMinutes(int minutes);
    bool getIsAvailable() const;
    void setIsAvailable(bool available);
    int getTotalRentals() const;
    void incrementTotalRentals();
    double getAverageRating() const;
    void setAverageRating(double rating);
};

