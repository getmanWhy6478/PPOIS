#include "UnitTest++/UnitTest++.h"
#include "../include/Installation.h"
#include "../include/Artist.h"
#include "../include/Painting.h"

SUITE(InstallationTests) {
    TEST(InstallationConstructor) {
        Artist* artist = new Artist("Yayoi", "Kusama", "Japanese", 1929);
        Installation* installation = new Installation("Infinity Room", 2013, artist);
        
        CHECK_EQUAL("Infinity Room", installation->getTitle());
        
        delete installation;
        delete artist;
    }
    
    TEST(InstallationProperties) {
        Artist* artist = new Artist("Damien", "Hirst", "British", 1965);
        Installation* installation = new Installation("The Physical Impossibility", 1991, artist);
        
        installation->setSetupInstructions("Requires special lighting and climate control");
        installation->setSpaceRequirements("Large gallery space");
        CHECK_EQUAL("Large gallery space", installation->getSpaceRequirements());
        CHECK_EQUAL("Requires special lighting and climate control", installation->getSetupInstructions());
        
        delete installation;
        delete artist;
    }
}

