#include "../include/GalleryShop.h"
#include "../include/Gallery.h"

GalleryShop::GalleryShop(const std::string& shopId, Gallery* gallery,
                         const std::string& shopName)
    : shopId(shopId), gallery(gallery), shopName(shopName),
      totalRevenue(0.0), totalSales(0), employeeCount(0) {
}

std::string GalleryShop::getShopId() const {
    return shopId;
}

void GalleryShop::setShopId(const std::string& id) {
    this->shopId = id;
}

Gallery* GalleryShop::getGallery() const {
    return gallery;
}

void GalleryShop::setGallery(Gallery* gallery) {
    this->gallery = gallery;
}

std::string GalleryShop::getShopName() const {
    return shopName;
}

void GalleryShop::setShopName(const std::string& name) {
    this->shopName = name;
}

std::string GalleryShop::getLocation() const {
    return location;
}

void GalleryShop::setLocation(const std::string& location) {
    this->location = location;
}

double GalleryShop::getTotalRevenue() const {
    return totalRevenue;
}

void GalleryShop::setTotalRevenue(double revenue) {
    this->totalRevenue = revenue;
}

void GalleryShop::addRevenue(double amount) {
    totalRevenue += amount;
}

int GalleryShop::getTotalSales() const {
    return totalSales;
}

void GalleryShop::setTotalSales(int sales) {
    this->totalSales = sales;
}

void GalleryShop::incrementSales() {
    totalSales++;
}

int GalleryShop::getEmployeeCount() const {
    return employeeCount;
}

void GalleryShop::setEmployeeCount(int count) {
    this->employeeCount = count;
}

