#include "UnitTest++/UnitTest++.h"
#include "../include/Archive.h"
#include "../include/Artwork.h"
#include "../include/Painting.h"
#include "../include/Artist.h"

SUITE(ArchiveTests) {
    TEST(ArchiveConstructor) {
        Archive* archive = new Archive("ARCH001", "Main Archive", "Basement");
        
        CHECK_EQUAL("ARCH001", archive->getArchiveId());
        CHECK_EQUAL("Main Archive", archive->getArchiveName());
        CHECK_EQUAL("Basement", archive->getLocation());
        
        delete archive;
    }
    
    TEST(ArchiveProperties) {
        Archive* archive = new Archive("ARCH001", "Archive", "Storage Room");
        archive->setArchiveName("Document Archive");
        archive->setLocation("Smolevichi");
        archive->setArchiveId("ARCH002");
        archive->setEstablishedYear(1950);
        archive->setTotalItems(1000);
        
        CHECK_EQUAL(1950, archive->getEstablishedYear());
        CHECK_EQUAL(1000, archive->getTotalItems());
        
        delete archive;
    }
}

