#pragma once

#include <string>
#include <vector>
#include "Exhibition.h"
#include "Gallery.h"

class Visitor;
class Artwork;

class ReportGenerator {
public:
    static std::string generateExhibitionReport(Exhibition* exhibition);
    static std::string generateGalleryStatistics(Gallery* gallery);
    static std::string generateVisitorReport(const std::vector<Visitor*>& visitors);
    static std::string generateFinancialReport(Gallery* gallery,
                                               int startYear, int endYear);
    static std::string generateArtworkInventory(const std::vector<Artwork*>& artworks);
};

