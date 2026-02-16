#include "UnitTest++/UnitTest++.h"
#include "../include/Loan.h"
#include "../include/Gallery.h"
#include "../include/Collection.h"
#include "../include/Painting.h"
#include "../include/Artist.h"

SUITE(LoanTests) {
    TEST(LoanConstructor) {
        Gallery* lender = new Gallery("Louvre", "Rue de Rivoli", "Paris", "France");
        Gallery* borrower = new Gallery("Met", "1000 5th Ave", "New York", "USA");
        Loan* loan = new Loan("LOAN001", lender, borrower);
        
        CHECK_EQUAL("LOAN001", loan->getLoanId());
        CHECK(loan->getLenderGallery() == lender);
        CHECK(loan->getBorrowerGallery() == borrower);
        CHECK_EQUAL("requested", loan->getStatus());
        
        delete loan;
        delete borrower;
        delete lender;
    }
    
    TEST(LoanProperties) {
        Gallery* lender = new Gallery("Tate", "Bankside", "London", "UK");
        Gallery* borrower = new Gallery("MoMA", "11 W 53rd St", "New York", "USA");
        Loan* loan = new Loan("LOAN002", lender, borrower);
        
        loan->setStartYear(2024);
        loan->setEndYear(2025);
        loan->setInsuranceAmount(5000000.0);
        loan->setStatus("approved");
        
        CHECK_EQUAL(2024, loan->getStartYear());
        CHECK_EQUAL(2025, loan->getEndYear());
        CHECK_CLOSE(5000000.0, loan->getInsuranceAmount(), 0.01);
        CHECK_EQUAL("approved", loan->getStatus());
        
        delete loan;
        delete borrower;
        delete lender;
    }
}

