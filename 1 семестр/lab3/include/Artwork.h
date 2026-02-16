#pragma once

#include <string>
#include <vector>

class Artist;
class Gallery;

class Artwork {
protected:
    std::string title;
    std::string description;
    int year;
    double width;
    double height;
    double depth;
    double weight;
    std::string condition;
    double estimatedValue;
    Artist* artist;
    std::string medium;
    std::string technique;

public:
    Artwork() = default;
    Artwork(const std::string& title, int year, Artist* artist);
    ~Artwork() = default;
    
    std::string getTitle() const;
    void setTitle(const std::string& title);
    std::string getDescription() const;
    void setDescription(const std::string& description);
    int getYear() const;
    void setYear(int year);
    double getWidth() const;
    void setWidth(double width);
    double getHeight() const;
    void setHeight(double height);
    double getDepth() const;
    void setDepth(double depth);
    double getWeight() const;
    void setWeight(double weight);
    std::string getCondition() const;
    void setCondition(const std::string& condition);
    double getEstimatedValue() const;
    void setEstimatedValue(double value);
    Artist* getArtist() const;
    void setArtist(Artist* artist);
    std::string getMedium() const;
    void setMedium(const std::string& medium);
    std::string getTechnique() const;
    void setTechnique(const std::string& technique);
};

