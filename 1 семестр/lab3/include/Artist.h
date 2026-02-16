#pragma once

#include <string>
#include <vector>

class Artwork;
class ArtMovement;

class Artist {
private:
    std::string firstName;
    std::string lastName;
    std::string nationality;
    int birthYear;
    int deathYear;
    std::string biography;
    std::vector<ArtMovement*> movements;
    std::vector<Artwork*> artworks;
    std::string style;
    bool isAlive;

public:
    Artist() = default;
    Artist(const std::string& firstName, const std::string& lastName, 
           const std::string& nationality, int birthYear);
    ~Artist() = default;
    
    std::string getFirstName() const;
    void setFirstName(const std::string& firstName);
    std::string getLastName() const;
    void setLastName(const std::string& lastName);
    std::string getFullName() const;
    std::string getNationality() const;
    void setNationality(const std::string& nationality);
    int getBirthYear() const;
    void setBirthYear(int year);
    int getDeathYear() const;
    void setDeathYear(int year);
    std::string getBiography() const;
    void setBiography(const std::string& biography);
    void addMovement(ArtMovement* movement);
    std::vector<ArtMovement*> getMovements() const;
    void addArtwork(Artwork* artwork);
    std::vector<Artwork*> getArtworks() const;
    std::string getStyle() const;
    void setStyle(const std::string& style);
    bool getIsAlive() const;
    void setIsAlive(bool alive);
    int getAge() const;

    Artwork createMasterpiece(const std::string& title, int age);
};

