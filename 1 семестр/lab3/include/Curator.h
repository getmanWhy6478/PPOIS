#pragma once

#include "Employee.h"
#include <string>
#include <vector>
#include "Exhibition.h"

class Curator : public Employee {
private:
    std::string specialization;
    std::string education;
    std::vector<Exhibition*> exhibitions;

public:
    Curator() = default;
    Curator(const std::string& firstName, const std::string& lastName,
            const std::string& employeeId, Gallery* gallery);
    ~Curator() = default;
    
    std::string getPosition() const override;

    std::string getSpecialization() const;
    void setSpecialization(const std::string& specialization);

    std::string getEducation() const;
    void setEducation(const std::string& education);

    void addExhibition(Exhibition* exhibition);
    std::vector<Exhibition*> getExhibitions() const;

    bool curateExhibition(Exhibition* exhibition, const std::string& theme,
                          double admissionPrice);
};

