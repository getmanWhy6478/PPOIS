#pragma once

#include <string>
#include "Gallery.h"

class Employee {
protected:
    std::string firstName;
    std::string lastName;
    std::string employeeId;
    std::string phone;
    int hireYear;
    double salary;
    Gallery* gallery;

public:
    Employee() = default;
    Employee(const std::string& firstName, const std::string& lastName,
             const std::string& employeeId, Gallery* gallery);
    virtual ~Employee() = default;
    
    virtual std::string getPosition() const = 0;
    std::string getFirstName() const;
    void setFirstName(const std::string& firstName);
    std::string getLastName() const;
    void setLastName(const std::string& lastName);
    std::string getFullName() const;
    std::string getEmployeeId() const;
    void setEmployeeId(const std::string& id);
    std::string getPhone() const;
    void setPhone(const std::string& phone);
    int getHireYear() const;
    void setHireYear(int year);
    double getSalary() const;
    void setSalary(double salary);
    Gallery* getGallery() const;
    void setGallery(Gallery* gallery);
    int getYearsOfService() const;
};

