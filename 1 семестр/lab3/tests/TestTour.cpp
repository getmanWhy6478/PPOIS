#include "UnitTest++/UnitTest++.h"
#include "../include/Tour.h"
#include "../include/Guide.h"
#include "../include/Visitor.h"
#include "../include/Gallery.h"
#include "../include/Exhibition.h"

SUITE(TourTests)
{
    TEST(ConstructorInitializesFields)
    {
        Guide guide;
        Exhibition exhibition;
        Tour tour("TOUR-001", &guide, &exhibition);

        CHECK_EQUAL("TOUR-001", tour.getTourId());
        CHECK_EQUAL(&guide, tour.getGuide());
        CHECK_EQUAL(&exhibition, tour.getExhibition());

        CHECK_EQUAL(0, tour.getMaxParticipants());
        CHECK_EQUAL(0.0, tour.getPrice());
        CHECK_EQUAL(0.0, tour.getAverageRating());
        CHECK(tour.getVisitors().empty());
        CHECK(!tour.isFull());
    }

    TEST(SettersAndGettersWorkCorrectly)
    {
        Gallery gallery;
        Guide guide;
        Exhibition exhibition;
        Tour tour("TOUR-002", &guide, &exhibition);

        tour.setTourId("TOUR-NEW");
        tour.setMaxParticipants(10);
        tour.setPrice(25.5);
        tour.setTheme("Modern Art");
        tour.setAverageRating(4.7);

        CHECK_EQUAL("TOUR-NEW", tour.getTourId());
        CHECK_EQUAL(10, tour.getMaxParticipants());
        CHECK_CLOSE(25.5, tour.getPrice(), 1e-6);
        CHECK_EQUAL("Modern Art", tour.getTheme());
        CHECK_CLOSE(4.7, tour.getAverageRating(), 1e-6);
    }

    TEST(GuideAndExhibitionReferenceChange)
    {
        Guide guide1;
        Guide guide2;
        Exhibition exhibition1;
        Exhibition exhibition2;

        Tour tour("TOUR-003", &guide1, &exhibition1);
        CHECK_EQUAL(&guide1, tour.getGuide());
        CHECK_EQUAL(&exhibition1, tour.getExhibition());

        tour.setGuide(&guide2);
        tour.setExhibition(&exhibition2);

        CHECK_EQUAL(&guide2, tour.getGuide());
        CHECK_EQUAL(&exhibition2, tour.getExhibition());
    }

    TEST(VisitorManagementAndIsFullLogic)
    {
        Guide guide;
        Exhibition exhibition;
        Tour tour("TOUR-004", &guide, &exhibition);

        tour.setMaxParticipants(2);

        Visitor v1;
        Visitor v2;
        Visitor v3;

        tour.addVisitor(&v1);
        CHECK(!tour.isFull());
        CHECK_EQUAL(1, tour.getVisitors().size());

        tour.addVisitor(&v2);
        CHECK(tour.isFull());
        CHECK_EQUAL(2, tour.getVisitors().size());

        tour.addVisitor(&v3);
        CHECK(tour.isFull());
        CHECK_EQUAL(3, tour.getVisitors().size()); 
    }
}

