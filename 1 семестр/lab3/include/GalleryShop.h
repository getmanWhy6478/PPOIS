#pragma once

#include <string>
#include <vector>
#include "Gallery.h"

class GalleryShop {
private:
    std::string shopId;
    Gallery* gallery;
    std::string shopName;
    std::string location;
    double totalRevenue;
    int totalSales;
    int employeeCount;

public:
    GalleryShop() = default;
    GalleryShop(const std::string& shopId, Gallery* gallery,
                const std::string& shopName);
    ~GalleryShop() = default;
    
    std::string getShopId() const;
    void setShopId(const std::string& id);
    Gallery* getGallery() const;
    void setGallery(Gallery* gallery);
    std::string getShopName() const;
    void setShopName(const std::string& name);
    std::string getLocation() const;
    void setLocation(const std::string& location);
    double getTotalRevenue() const;
    void setTotalRevenue(double revenue);
    void addRevenue(double amount);
    int getTotalSales() const;
    void setTotalSales(int sales);
    void incrementSales();
    int getEmployeeCount() const;
    void setEmployeeCount(int count);
};

