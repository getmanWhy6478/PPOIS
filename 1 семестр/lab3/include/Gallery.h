#pragma once

#include <string>
#include <vector>
#include "Room.h"
#include "Exhibition.h"
#include "Collection.h"

class Artwork;
class Employee;
class Exhibition;
class Visitor;

class Gallery {
private:
    std::string name;
    std::string address;
    std::string city;
    std::string country;
    std::vector<Room*> rooms;
    std::vector<Exhibition*> exhibitions;
    std::vector<Collection*> collections;
    std::vector<Employee*> employees;
    double admissionPrice;
    int maxCapacity;

public:
    Gallery() = default;
    Gallery(const std::string& name, const std::string& address, 
            const std::string& city, const std::string& country);
    ~Gallery() = default;
    
    std::string getName() const;
    void setName(const std::string& name);
    std::string getAddress() const;
    void setAddress(const std::string& address);
    std::string getCity() const;
    void setCity(const std::string& city);
    std::string getCountry() const;
    void setCountry(const std::string& country);
    void addRoom(Room* room);
    std::vector<Room*> getRooms() const;
    void addExhibition(Exhibition* exhibition);
    std::vector<Exhibition*> getExhibitions() const;
    void addCollection(Collection* collection);
    std::vector<Collection*> getCollections() const;
    void addEmployee(Employee* employee);
    std::vector<Employee*> getEmployees() const;
    double getAdmissionPrice() const;
    void setAdmissionPrice(double price);
    int getMaxCapacity() const;
    void setMaxCapacity(int capacity);

    bool borrow(Collection& collection, Gallery& other);
};

