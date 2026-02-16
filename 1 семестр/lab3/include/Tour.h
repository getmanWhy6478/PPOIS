#pragma once

#include <string>
#include <vector>
#include "Guide.h"
#include "Visitor.h"
#include "Exhibition.h"

class Guide;

class Tour {
private:
    std::string tourId;
    Guide* guide;
    std::vector<Visitor*> visitors;
    Exhibition* exhibition;
    int maxParticipants;
    double price;
    std::string theme;
    double averageRating;

public:
    Tour() = default;
    Tour(const std::string& tourId, Guide* guide,
         Exhibition* exhibition);
    ~Tour() = default;
    
    std::string getTourId() const;
    void setTourId(const std::string& id);
    Guide* getGuide() const;
    void setGuide(Guide* guide);
    void addVisitor(Visitor* visitor);
    std::vector<Visitor*> getVisitors() const;
    Exhibition* getExhibition() const;
    void setExhibition(Exhibition* exhibition);
    int getMaxParticipants() const;
    void setMaxParticipants(int max);
    bool isFull() const;
    double getPrice() const;
    void setPrice(double price);
    std::string getTheme() const;
    void setTheme(const std::string& theme);
    double getAverageRating() const;
    void setAverageRating(double rating);
};

