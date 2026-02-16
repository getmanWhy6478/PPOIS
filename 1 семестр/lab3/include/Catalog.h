#pragma once

#include <string>
#include <vector>
#include "Artwork.h"
#include "Exhibition.h"

class Catalog {
private:
    std::string isbn;
    std::string title;
    std::string publisher;
    int publicationYear;
    Exhibition* exhibition;
    std::vector<Artwork*> artworks;
    int pageCount;
    std::string language;
    double price;

public:
    Catalog() = default;
    Catalog(const std::string& isbn, const std::string& title,
            const std::string& publisher);
    ~Catalog() = default;
    
    std::string getIsbn() const;
    void setIsbn(const std::string& isbn);
    std::string getTitle() const;
    void setTitle(const std::string& title);
    std::string getPublisher() const;
    void setPublisher(const std::string& publisher);
    int getPublicationYear() const;
    void setPublicationYear(int year);
    Exhibition* getExhibition() const;
    void setExhibition(Exhibition* exhibition);
    void addArtwork(Artwork* artwork);
    std::vector<Artwork*> getArtworks() const;
    int getPageCount() const;
    void setPageCount(int pages);
    std::string getLanguage() const;
    void setLanguage(const std::string& language);
    double getPrice() const;
    void setPrice(double price);
};

