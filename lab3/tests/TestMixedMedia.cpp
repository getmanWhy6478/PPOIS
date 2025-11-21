#include "UnitTest++/UnitTest++.h"
#include "../include/MixedMedia.h"
#include "../include/Artist.h"

SUITE(MixedMediaTests) {
    TEST(MixedMediaConstructor) {
        Artist* artist = new Artist("Robert", "Rauschenberg", "American", 1925);
        MixedMedia* mixed = new MixedMedia("Combines", 1954, artist);
        
        CHECK_EQUAL("MixedMedia", mixed->getType());
        
        delete mixed;
        delete artist;
    }
    
    TEST(MixedMediaProperties) {
        Artist* artist = new Artist("Jasper", "Johns", "American", 1930);
        MixedMedia* mixed = new MixedMedia("Flag", 1955, artist);
        
        mixed->addMediaType("Oil");
        mixed->addMediaType("Canvas");
        mixed->addMediaType("Newspaper");
        
        std::vector<std::string> mediaTypes = mixed->getMediaTypes();
        CHECK_EQUAL(3, mediaTypes.size());
        
        delete mixed;
        delete artist;
    }
}

