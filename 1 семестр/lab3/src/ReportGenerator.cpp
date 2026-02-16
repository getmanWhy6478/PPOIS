#include "../include/ReportGenerator.h"
#include "../include/Exhibition.h"
#include "../include/Gallery.h"
#include "../include/Visitor.h"
#include "../include/Artwork.h"
#include <sstream>

std::string ReportGenerator::generateExhibitionReport(Exhibition* exhibition) {
    if (!exhibition) return "Exhibition is null";
    
    std::ostringstream oss;
    oss << "=== Exhibition Report ===\n";
    oss << "Title: " << exhibition->getTitle() << "\n";
    oss << "Theme: " << exhibition->getTheme() << "\n";
    oss << "Visitor Count: " << exhibition->getVisitorCount() << "\n";
    oss << "Admission Price: " << exhibition->getAdmissionPrice() << "\n";
    oss << "Artworks Count: " << exhibition->getArtworks().size() << "\n";
    
    return oss.str();
}

std::string ReportGenerator::generateGalleryStatistics(Gallery* gallery) {
    if (!gallery) return "Gallery is null";
    
    std::ostringstream oss;
    oss << "=== Gallery Statistics ===\n";
    oss << "Name: " << gallery->getName() << "\n";
    oss << "Location: " << gallery->getCity() << ", " << gallery->getCountry() << "\n";
    oss << "Rooms: " << gallery->getRooms().size() << "\n";
    oss << "Exhibitions: " << gallery->getExhibitions().size() << "\n";
    oss << "Collections: " << gallery->getCollections().size() << "\n";
    oss << "Employees: " << gallery->getEmployees().size() << "\n";
    oss << "Max Capacity: " << gallery->getMaxCapacity() << "\n";
    oss << "Admission Price: " << gallery->getAdmissionPrice() << "\n";
    
    return oss.str();
}

std::string ReportGenerator::generateVisitorReport(const std::vector<Visitor*>& visitors) {
    std::ostringstream oss;
    oss << "=== Visitor Report ===\n";
    oss << "Total Visitors: " << visitors.size() << "\n";
    
    int members = 0;
    int totalVisits = 0;
    
    for (auto* visitor : visitors) {
        if (visitor) {
            if (visitor->getIsMember()) {
                members++;
            }
            totalVisits += visitor->getVisitCount();
        }
    }
    
    oss << "Members: " << members << "\n";
    oss << "Non-members: " << (visitors.size() - members) << "\n";
    oss << "Total Visits: " << totalVisits << "\n";
    
    if (!visitors.empty()) {
        oss << "Average Visits per Visitor: " 
            << (static_cast<double>(totalVisits) / visitors.size()) << "\n";
    }
    
    return oss.str();
}

std::string ReportGenerator::generateFinancialReport(Gallery* gallery,
                                                      int startYear, int endYear) {
    if (!gallery) return "Gallery is null";
    
    std::ostringstream oss;
    oss << "=== Financial Report ===\n";
    oss << "Gallery: " << gallery->getName() << "\n";
    oss << "Period: " << startYear << " - " << endYear << "\n";
    oss << "Admission Price: " << gallery->getAdmissionPrice() << "\n";
    oss << "Note: Detailed financial calculations require additional data.\n";
    
    return oss.str();
}

std::string ReportGenerator::generateArtworkInventory(const std::vector<Artwork*>& artworks) {
    std::ostringstream oss;
    oss << "=== Artwork Inventory ===\n";
    oss << "Total Artworks: " << artworks.size() << "\n\n";
    
    double totalValue = 0.0;
    int onDisplay = 0;
    
    for (auto* artwork : artworks) {
        if (artwork) {
            totalValue += artwork->getEstimatedValue();
            }
        }
    oss << "On Display: " << onDisplay << "\n";
    oss << "In Storage: " << (artworks.size() - onDisplay) << "\n";
    oss << "Total Estimated Value: " << totalValue << "\n";
    
    return oss.str();
}


