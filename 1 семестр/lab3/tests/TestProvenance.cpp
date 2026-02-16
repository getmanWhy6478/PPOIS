#include "UnitTest++/UnitTest++.h"
#include "../include/Provenance.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"
#include "../include/Collector.h"

SUITE(ProvenanceTests)
{
    TEST(ConstructorInitializesFields)
    {
        Artwork* artwork = new Painting("Test Artwork", 2020, nullptr);
        Provenance provenance(artwork);

        CHECK_EQUAL(artwork, provenance.getArtwork());
        CHECK_EQUAL(0, provenance.getAcquisitionYear());
        CHECK_EQUAL(0.0, provenance.getAcquisitionPrice());
        CHECK(provenance.getPreviousOwners().empty());
        CHECK(provenance.getOwnershipYears().empty());
        CHECK_EQUAL("", provenance.getCurrentOwner());

        delete artwork;
    }

    TEST(SettersAndGettersWorkCorrectly)
    {
        Artwork* artwork = new Painting("Painting", 2010, nullptr);
        Provenance provenance(artwork);

        Artwork* newArtwork = new Painting("Sculpture", 2015, nullptr);
        provenance.setArtwork(newArtwork);
        provenance.setAcquisitionYear(2022);
        provenance.setAcquisitionPrice(15000.0);
        provenance.setCurrentOwner("Ivan Petrov");

        CHECK_EQUAL(newArtwork, provenance.getArtwork());
        CHECK_EQUAL(2022, provenance.getAcquisitionYear());
        CHECK_CLOSE(15000.0, provenance.getAcquisitionPrice(), 1e-6);
        CHECK_EQUAL("Ivan Petrov", provenance.getCurrentOwner());

        delete artwork;
        delete newArtwork;
    }

    TEST(AddPreviousOwnersAndYears)
    {
        Artwork* artwork = new Painting("Test Artwork", 2020, nullptr);
        Provenance provenance(artwork);

        Collector c1;
        Collector c2;
        Collector c3;

        provenance.addPreviousOwner(&c1, 1950);
        provenance.addPreviousOwner(&c2, 1980);
        provenance.addPreviousOwner(&c3, 2000);

        std::vector<Collector*> owners = provenance.getPreviousOwners();
        std::vector<int> years = provenance.getOwnershipYears();

        CHECK_EQUAL(3, owners.size());
        CHECK_EQUAL(3, years.size());

        CHECK_EQUAL(&c1, owners[0]);
        CHECK_EQUAL(&c2, owners[1]);
        CHECK_EQUAL(&c3, owners[2]);

        CHECK_EQUAL(1950, years[0]);
        CHECK_EQUAL(1980, years[1]);
        CHECK_EQUAL(2000, years[2]);

        delete artwork;
    }
}

