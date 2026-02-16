#pragma once

#include <string>
#include <vector>
#include "Artwork.h"
#include "Gallery.h"

class Curator;

class Exhibition {
private:
    std::string title;
    std::string description;
    Gallery* gallery;
    std::vector<Artwork*> artworks;
    Curator* curator;
    std::string theme;
    double admissionPrice;
    int visitorCount;

public:
    Exhibition() = default;
    Exhibition(const std::string& title, Gallery* gallery,
               int startYear, int endYear);
    ~Exhibition() = default;
    
    std::string getTitle() const;
    void setTitle(const std::string& title);
    std::string getDescription() const;
    void setDescription(const std::string& description);
    Gallery* getGallery() const;
    void setGallery(Gallery* gallery);
    void addArtwork(Artwork* artwork);
    std::vector<Artwork*> getArtworks() const;
    Curator* getCurator() const;
    void setCurator(Curator* curator);
    std::string getTheme() const;
    void setTheme(const std::string& theme);
    double getAdmissionPrice() const;
    void setAdmissionPrice(double price);
    int getVisitorCount() const;
    void setVisitorCount(int count);
    void incrementVisitorCount();
};

