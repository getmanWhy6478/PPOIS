#include "UnitTest++/UnitTest++.h"
#include "../include/Period.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"

SUITE(PeriodTests) {
    TEST(ConstructorInitializesFields) {
        Period p("Ренессанс", 1400, 1600);

        CHECK_EQUAL("Ренессанс", p.getName());
        CHECK_EQUAL(1400, p.getStartYear());
        CHECK_EQUAL(1600, p.getEndYear());
        CHECK_EQUAL("", p.getDescription());
        CHECK_EQUAL(200, p.getDuration()); 
    }

    TEST(SettersUpdateFields) {
        Period p("Барокко", 1600, 1750);

        p.setName("Классицизм");
        p.setDescription("Эпоха строгих форм");
        p.setStartYear(1650);
        p.setEndYear(1800);

        CHECK_EQUAL("Классицизм", p.getName());
        CHECK_EQUAL("Эпоха строгих форм", p.getDescription());
        CHECK_EQUAL(1650, p.getStartYear());
        CHECK_EQUAL(1800, p.getEndYear());
        CHECK_EQUAL(150, p.getDuration());
    }

    TEST(AddArtworkStoresPointer) {
        Period p("Модерн", 1890, 1910);
        Artwork art1;
        Artwork art2;

        p.addArtwork(&art1);
        p.addArtwork(&art2);

        auto artworks = p.getArtworks();
        CHECK_EQUAL(2, artworks.size());
        CHECK(artworks[0] == &art1);
        CHECK(artworks[1] == &art2);
    }

    TEST(AddKeyEventStoresString) {
        Period p("Импрессионизм", 1870, 1900);

        p.addKeyEvent("Выставка в Париже");
        p.addKeyEvent("Появление термина 'импрессионизм'");

        auto events = p.getKeyEvents();
        CHECK_EQUAL(2, events.size());
        CHECK_EQUAL("Выставка в Париже", events[0]);
        CHECK_EQUAL("Появление термина 'импрессионизм'", events[1]);
    }

    TEST(DurationZeroWhenEndBeforeStart) {
        Period p("Ошибочный период", 2000, 1900);
        CHECK_EQUAL(0, p.getDuration());
    }

    TEST(DurationZeroWhenEqualYears) {
        Period p("Мгновение", 2020, 2020);
        CHECK_EQUAL(0, p.getDuration());
    }
}

