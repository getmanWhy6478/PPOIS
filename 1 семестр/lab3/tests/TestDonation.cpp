#include "UnitTest++/UnitTest++.h"
#include "../include/Donation.h"
#include "../include/Collector.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"

SUITE(DonationTests) {
    TEST(ConstructorInitializesFields) {
        Collector donor;
        Donation d("D123", &donor, "Национальный музей");

        CHECK_EQUAL("D123", d.getDonationId());
        CHECK_EQUAL(&donor, d.getDonor());
        CHECK_EQUAL("Национальный музей", d.getRecipientInstitution());
        CHECK_EQUAL(0.0, d.getEstimatedValue());
        CHECK_EQUAL(0, d.getDonatedArtworks().size());
    }

    TEST(SettersUpdateFields) {
        Collector donor1;
        Collector donor2;
        Donation d("D123", &donor1, "Музей");

        d.setDonationId("D456");
        d.setDonor(&donor2);
        d.setRecipientInstitution("Галерея");
        d.setEstimatedValue(5000.0);

        CHECK_EQUAL("D456", d.getDonationId());
        CHECK_EQUAL(&donor2, d.getDonor());
        CHECK_EQUAL("Галерея", d.getRecipientInstitution());
        CHECK_EQUAL(5000.0, d.getEstimatedValue());
    }

    TEST(AddDonatedArtworkUpdatesListAndValue) {
        Collector donor;
        Donation d("D123", &donor, "Музей");

        Artwork art1;
        Artwork art2;

        d.addDonatedArtwork(&art1);
        d.addDonatedArtwork(&art2);

        auto artworks = d.getDonatedArtworks();
        CHECK_EQUAL(2, artworks.size());
        d.setEstimatedValue(3000);
        CHECK(artworks[0] == &art1);
        CHECK(artworks[1] == &art2);

        CHECK_EQUAL(3000.0, d.getEstimatedValue());
    }

    TEST(AddNullArtworkDoesNotChangeValue) {
        Collector donor;
        Donation d("D123", &donor, "Музей");

        d.addDonatedArtwork(nullptr);

        auto artworks = d.getDonatedArtworks();
        CHECK_EQUAL(1, artworks.size());
        CHECK_EQUAL(0.0, d.getEstimatedValue()); 
    }
}

