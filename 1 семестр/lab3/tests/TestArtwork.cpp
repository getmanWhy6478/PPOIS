#include "UnitTest++/UnitTest++.h"
#include "../include/Artwork.h"
#include "../include/Artist.h"
#include "../include/Painting.h"

SUITE(ArtworkTests) {
    TEST(ConstructorInitializesFields) {
        Artist artist("Иван", "Иванов", "Беларусь", 1980);
        Artwork art("Мона Лиза", 1503, &artist);

        CHECK_EQUAL("Мона Лиза", art.getTitle());
        CHECK_EQUAL(1503, art.getYear());
        CHECK_EQUAL(&artist, art.getArtist());

        CHECK_EQUAL(0.0, art.getWidth());
        CHECK_EQUAL(0.0, art.getHeight());
        CHECK_EQUAL(0.0, art.getDepth());
        CHECK_EQUAL(0.0, art.getWeight());
        CHECK_EQUAL(0.0, art.getEstimatedValue());

        CHECK_EQUAL("", art.getDescription());
        CHECK_EQUAL("", art.getCondition());
        CHECK_EQUAL("", art.getMedium());
        CHECK_EQUAL("", art.getTechnique());
    }

    TEST(SettersUpdateStringFields) {
        Artist artist("Иван", "Иванов", "Беларусь", 1980);
        Artwork art("Картина", 2000, &artist);

        art.setTitle("Новый заголовок");
        art.setDescription("Описание картины");
        art.setCondition("Хорошее");
        art.setMedium("Масло");
        art.setTechnique("Импрессионизм");

        CHECK_EQUAL("Новый заголовок", art.getTitle());
        CHECK_EQUAL("Описание картины", art.getDescription());
        CHECK_EQUAL("Хорошее", art.getCondition());
        CHECK_EQUAL("Масло", art.getMedium());
        CHECK_EQUAL("Импрессионизм", art.getTechnique());
    }

    TEST(SettersUpdateNumericFields) {
        Artist artist("Иван", "Иванов", "Беларусь", 1980);
        Artwork art("Картина", 2000, &artist);

        art.setYear(2021);
        art.setWidth(50.5);
        art.setHeight(70.2);
        art.setDepth(10.0);
        art.setWeight(5.5);
        art.setEstimatedValue(1000000.0);

        CHECK_EQUAL(2021, art.getYear());
        CHECK_EQUAL(50.5, art.getWidth());
        CHECK_EQUAL(70.2, art.getHeight());
        CHECK_EQUAL(10.0, art.getDepth());
        CHECK_EQUAL(5.5, art.getWeight());
        CHECK_EQUAL(1000000.0, art.getEstimatedValue());
    }

    TEST(SetArtistChangesPointer) {
        Artist artist1("Иван", "Иванов", "Беларусь", 1980);
        Artist artist2("Пётр", "Петров", "Россия", 1975);

        Artwork art("Картина", 2000, &artist1);
        CHECK_EQUAL(&artist1, art.getArtist());

        art.setArtist(&artist2);
        CHECK_EQUAL(&artist2, art.getArtist());
    }
}

