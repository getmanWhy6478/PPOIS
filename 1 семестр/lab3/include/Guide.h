#pragma once

#include "Employee.h"
#include <string>
#include <vector>
#include "Tour.h"

class Tour;

class Guide : public Employee {
private:
    std::vector<std::string> languages;
    std::vector<Tour*> tours;
    int totalToursConducted;
    double averageRating;

public:
    Guide() = default;
    Guide(const std::string& firstName, const std::string& lastName,
          const std::string& employeeId, Gallery* gallery);
    ~Guide() = default;
    
    std::string getPosition() const override;

    void addLanguage(const std::string& language);
    std::vector<std::string> getLanguages() const;

    void addTour(Tour* tour);
    std::vector<Tour*> getTours() const;

    int getTotalToursConducted() const;
    void incrementToursConducted();

    double getAverageRating() const;
    void setAverageRating(double rating);
    void updateAverageRating(double newRating);

    bool conductTour(Tour* tour, const std::string& languageUsed);
};

