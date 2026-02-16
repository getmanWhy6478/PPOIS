#pragma once

#include "Employee.h"
#include <string>
#include <vector>
#include "Artwork.h"
#include "Restoration.h"

class Restoration;

class Restorer : public Employee {
private:
    std::string specialization;
    std::string education;
    int yearsOfExperience;
    std::vector<Restoration*> restorations;

public:
    Restorer() = default;
    Restorer(const std::string& firstName, const std::string& lastName,
             const std::string& employeeId, Gallery* gallery);
    ~Restorer() = default;
    
    std::string getPosition() const override;

    std::string getSpecialization() const;
    void setSpecialization(const std::string& specialization);

    std::string getEducation() const;
    void setEducation(const std::string& education);

    int getYearsOfExperience() const;
    void setYearsOfExperience(int years);

    void addRestoration(Restoration* restoration);
    std::vector<Restoration*> getRestorations() const;

    Restoration* startRestoration(const std::string& restorationId,
                                  Artwork* artwork,
                                  const std::string& conditionBefore);
    void endRestoration(Restoration* restoration, const std::string& conditionAfter);
};

