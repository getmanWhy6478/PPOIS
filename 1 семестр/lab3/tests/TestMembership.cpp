#include "UnitTest++/UnitTest++.h"
#include "../include/Membership.h"
#include "../include/Visitor.h"

SUITE(MembershipTests) {

    TEST(ConstructorInitializesFields) {
        Visitor visitor;
        Membership m("M123", &visitor, "Premium");

        CHECK_EQUAL("M123", m.getMembershipNumber());
        CHECK_EQUAL(&visitor, m.getMember());
        CHECK_EQUAL("Premium", m.getMembershipType());

        CHECK_EQUAL(0.0, m.getAnnualFee());
        CHECK(m.getIsActive());
        CHECK_EQUAL(0, m.getDiscountPercentage());

        CHECK_EQUAL(m.getStartYear() + 1, m.getEndYear());
    }

    TEST(SettersUpdateFields) {
        Visitor visitor1;
        Visitor visitor2;

        Membership m("M123", &visitor1, "Standard");

        m.setMembershipNumber("M456");
        m.setMember(&visitor2);
        m.setMembershipType("VIP");
        m.setStartYear(2020);
        m.setEndYear(2025);
        m.setAnnualFee(150.0);
        m.setIsActive(false);
        m.setDiscountPercentage(20);

        CHECK_EQUAL("M456", m.getMembershipNumber());
        CHECK_EQUAL(&visitor2, m.getMember());
        CHECK_EQUAL("VIP", m.getMembershipType());
        CHECK_EQUAL(2020, m.getStartYear());
        CHECK_EQUAL(2025, m.getEndYear());
        CHECK_EQUAL(150.0, m.getAnnualFee());
        CHECK(!m.getIsActive());
        CHECK_EQUAL(20, m.getDiscountPercentage());
    }

    TEST(AddBenefitStoresStrings) {
        Visitor visitor;
        Membership m("M123", &visitor, "Standard");

        m.addBenefit("Free entry");
        m.addBenefit("Discount on souvenirs");

        auto benefits = m.getBenefits();
        CHECK_EQUAL(2, benefits.size());
        CHECK_EQUAL("Free entry", benefits[0]);
        CHECK_EQUAL("Discount on souvenirs", benefits[1]);
    }

    TEST(IsExpiredWhenInactive) {
        Visitor visitor;
        Membership m("M123", &visitor, "Standard");

        m.setIsActive(false);
        CHECK(m.isExpired());
    }

    TEST(IsExpiredWhenEndYearPassed) {
        Visitor visitor;
        Membership m("M123", &visitor, "Standard");

        m.setEndYear(2000);
        m.setIsActive(true);

        CHECK(m.isExpired());
    }

    TEST(IsNotExpiredWhenActiveAndValidYears) {
        Visitor visitor;
        Membership m("M123", &visitor, "Standard");

        m.setStartYear(2025);
        m.setEndYear(2026);
        m.setIsActive(true);

        CHECK(!m.isExpired());
    }
}

