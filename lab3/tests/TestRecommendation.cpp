#include <UnitTest++/UnitTest++.h>
#include "../include/Recommendation.h"
#include "../include/Visitor.h"

SUITE(RecommendationTests) {

    TEST(ConstructorSetsText) {
        Recommendation rec("Отличная выставка!", nullptr);
        CHECK_EQUAL("Отличная выставка!", rec.getText());
        CHECK(rec.getAuthor() == nullptr);
    }

    TEST(SetTextUpdatesValue) {
        Recommendation rec;
        rec.setText("Новая рекомендация");
        CHECK_EQUAL("Новая рекомендация", rec.getText());
    }

    TEST(SetAuthorStoresPointer) {
        Recommendation rec("Совет", nullptr);
        Visitor visitor;

        rec.setAuthor(&visitor);
        CHECK(rec.getAuthor() == &visitor);
    }

    TEST(ChangeAuthorAndText) {
        Recommendation rec("Первый текст", nullptr);
        Visitor visitor1;
        Visitor visitor2;

        rec.setAuthor(&visitor1);
        rec.setText("Обновлённый текст");

        CHECK_EQUAL("Обновлённый текст", rec.getText());
        CHECK(rec.getAuthor() == &visitor1);

        rec.setAuthor(&visitor2);
        CHECK(rec.getAuthor() == &visitor2);
    }
}
