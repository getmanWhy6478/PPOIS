#include "../include/Catalog.h"
#include "../include/Artwork.h"
#include "../include/Exhibition.h"

Catalog::Catalog(const std::string& isbn, const std::string& title,
                 const std::string& publisher)
    : isbn(isbn), title(title), publisher(publisher), pageCount(0),
      price(0.0), publicationYear(0), exhibition(nullptr) {
}

std::string Catalog::getIsbn() const {
    return isbn;
}

void Catalog::setIsbn(const std::string& isbn) {
    this->isbn = isbn;
}

std::string Catalog::getTitle() const {
    return title;
}

void Catalog::setTitle(const std::string& title) {
    this->title = title;
}

std::string Catalog::getPublisher() const {
    return publisher;
}

void Catalog::setPublisher(const std::string& publisher) {
    this->publisher = publisher;
}

int Catalog::getPublicationYear() const {
    return publicationYear;
}

void Catalog::setPublicationYear(int year) {
    this->publicationYear = year;
}

Exhibition* Catalog::getExhibition() const {
    return exhibition;
}

void Catalog::setExhibition(Exhibition* exhibition) {
    this->exhibition = exhibition;
}

void Catalog::addArtwork(Artwork* artwork) {
    artworks.push_back(artwork);
}

std::vector<Artwork*> Catalog::getArtworks() const {
    return artworks;
}

int Catalog::getPageCount() const {
    return pageCount;
}

void Catalog::setPageCount(int pages) {
    this->pageCount = pages;
}

std::string Catalog::getLanguage() const {
    return language;
}

void Catalog::setLanguage(const std::string& language) {
    this->language = language;
}

double Catalog::getPrice() const {
    return price;
}

void Catalog::setPrice(double price) {
    this->price = price;
}

