#include "UnitTest++/UnitTest++.h"
#include "../include/Membership.h"
#include "../include/Visitor.h"

SUITE(MembershipTests) {
    TEST(MembershipConstructor) {
        Visitor* member = new Visitor("John", "Doe", "john@example.com");
        Membership* membership = new Membership("MEM001", member, "Premium");
        
        CHECK_EQUAL("MEM001", membership->getMembershipNumber());
        CHECK(membership->getMember() == member);
        CHECK_EQUAL("Premium", membership->getMembershipType());
        CHECK(membership->getIsActive());
        
        delete membership;
        delete member;
    }
    
    TEST(MembershipBenefits) {
        Visitor* member = new Visitor("Jane", "Smith", "jane@example.com");
        Membership* membership = new Membership("MEM002", member, "VIP");
        
        membership->addBenefit("Free admission");
        membership->addBenefit("Priority booking");
        membership->addBenefit("Exclusive events");
        
        std::vector<std::string> benefits = membership->getBenefits();
        CHECK_EQUAL(3, benefits.size());
        CHECK_EQUAL("Free admission", benefits[0]);
        
        delete membership;
        delete member;
    }
    
    TEST(MembershipDiscount) {
        Visitor* member = new Visitor("Bob", "Johnson", "bob@example.com");
        Membership* membership = new Membership("MEM003", member, "Basic");
        
        membership->setDiscountPercentage(10);
        CHECK_EQUAL(10, membership->getDiscountPercentage());
        
        membership->setAnnualFee(100.0);
        CHECK_CLOSE(100.0, membership->getAnnualFee(), 0.01);
        
        delete membership;
        delete member;
    }
}

