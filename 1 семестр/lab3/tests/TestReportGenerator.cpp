#include "UnitTest++/UnitTest++.h"
#include "../include/ReportGenerator.h"
#include "../include/Exhibition.h"
#include "../include/Gallery.h"
#include "../include/Visitor.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"

SUITE(ReportGeneratorTests) {
    TEST(GenerateExhibitionReport) {
        Gallery* gallery = new Gallery("MoMA", "11 W 53rd St", "New York", "USA");
        Exhibition* exhibition = new Exhibition("Modern Art", gallery, 2024, 2024);
        exhibition->setTheme("Contemporary");
        exhibition->setVisitorCount(1000);
        
        std::string report = ReportGenerator::generateExhibitionReport(exhibition);
        CHECK(report.find("Modern Art") != std::string::npos);
        CHECK(report.find("1000") != std::string::npos);
        
        delete exhibition;
        delete gallery;
    }
    
    TEST(GenerateGalleryStatistics) {
        Gallery* gallery = new Gallery("Tate", "Bankside", "London", "UK");
        gallery->setMaxCapacity(5000);
        
        std::string stats = ReportGenerator::generateGalleryStatistics(gallery);
        CHECK(stats.find("Tate") != std::string::npos);
        CHECK(stats.find("5000") != std::string::npos);
        
        delete gallery;
    }
    
    TEST(GenerateVisitorReport) {
        Visitor* v1 = new Visitor("John", "Doe", "john@example.com");
        Visitor* v2 = new Visitor("Jane", "Smith", "jane@example.com");
        v1->setIsMember(true);
        v1->incrementVisitCount();
        v1->incrementVisitCount();
        v2->incrementVisitCount();
        
        std::vector<Visitor*> visitors = {v1, v2};
        std::string report = ReportGenerator::generateVisitorReport(visitors);
        
        CHECK(report.find("2") != std::string::npos);
        
        delete v1;
        delete v2;
    }
}

