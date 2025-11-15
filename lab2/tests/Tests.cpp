#include "UnitTest++/UnitTest++.h"
#include "../include/Ad.h"
#include <ctime>
#include <stdexcept>
#include <iostream>
#include "../include/Errors.h"
#include "../include/AirGrill.h"
#include "../include/Bike.h"
#include "../include/Bonus.h"
#include "../include/Car.h"
#include "../include/CEO.h"
#include "../include/ComboMeal.h"
#include "../include/Complaint.h"
#include "../include/ComplaintBook.h"
#include "../include/Cook.h"
#include "../include/Courier.h"
#include "../include/Customer.h"
#include "../include/Delivery.h"
#include "../include/DeliveryRoute.h"
#include "../include/DeliveryStatus.h"
#include "../include/DinningRoom.h"
#include "../include/DinningRoomRequirement.h"
#include "../include/Dishwasher.h"
#include "../include/Drink.h"
#include "../include/Eatable.h"
#include "../include/Food.h"
#include "../include/FoodPosition.h"
#include "../include/Freezer.h"
#include "../include/Fridge.h"
#include "../include/Kitchen.h"
#include "../include/KitchenAppliance.h"
#include "../include/KitchenRequirement.h"
#include "../include/LoyaltyProgram.h"
#include "../include/Manager.h"
#include "../include/Menu.h"
#include "../include/NotAuthorisedCustomer.h"
#include "../include/Order.h"
#include "../include/OrderPosition.h"
#include "../include/Oven.h"
#include "../include/Payment.h"
#include "../include/Place.h"
#include "../include/PlaceRequirement.h"
#include "../include/Product.h"
#include "../include/PushNotification.h"
#include "../include/PushService.h"
#include "../include/Rating.h"
#include "../include/Restaurant.h"
#include "../include/Scooter.h"
#include "../include/Stove.h"
#include "../include/Supplier.h"
#include "../include/SupportAgent.h"
#include "../include/User.h"
#include "../include/Vehicle.h"
#include "../include/VipCustomer.h"
#include "../include/Warehouse.h"
#include "../include/WarehouseRequirement.h"
#include "../include/Worker.h"
TEST(Constructor_InitializesFieldsCorrectly) {
    Ad ad("Promo", "Buy one get one free", false);
    CHECK_EQUAL("Promo", ad.getTitle());
    CHECK_EQUAL("Buy one get one free", ad.getText());
    CHECK_EQUAL(false, ad.getIsActive());
}

TEST(SetTitle_UpdatesTitle) {
    Ad ad("Old", "Text", true);
    ad.setTitle("New");
    CHECK_EQUAL("New", ad.getTitle());
}

TEST(SetText_UpdatesText) {
    Ad ad("Title", "OldText", true);
    ad.setText("NewText");
    CHECK_EQUAL("NewText", ad.getText());
}

TEST(SetIsActive_SetsTrue) {
    Ad ad("Title", "Text", false);
    Ad a;
    ad.setIsActive();
    CHECK_EQUAL(true, ad.getIsActive());
}

SUITE(AdressTests) {

TEST(DefaultConstructor_InitializesFields) {
    Adress a;
    CHECK_EQUAL("", a.getCity());
    CHECK_EQUAL("", a.getStreet());
    CHECK_EQUAL(0, a.getHouse());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Adress a("Минск", "Независимости", 10);
    CHECK_EQUAL("Минск", a.getCity());
    CHECK_EQUAL("Независимости", a.getStreet());
    CHECK_EQUAL(10, a.getHouse());
}

TEST(SetCity_UpdatesValue) {
    Adress a;
    a.setCity("Брест");
    CHECK_EQUAL("Брест", a.getCity());
}

TEST(SetStreet_UpdatesValue) {
    Adress a;
    a.setStreet("Советская");
    CHECK_EQUAL("Советская", a.getStreet());
}

TEST(SetHouse_UpdatesValue) {
    Adress a;
    a.setHouse(42);
    CHECK_EQUAL(42, a.getHouse());
}

}




SUITE(AirGrillTests) {

TEST(Constructor_SetsAllFieldsCorrectly) {
    AirGrill grill("GrillMaster 3000", true, 12, true);
    CHECK_EQUAL("GrillMaster 3000", grill.getName());
    CHECK_EQUAL(true, grill.getIsElectric());
    CHECK_EQUAL(true, grill.getIsAvailable());
    CHECK_EQUAL(12, grill.getVolumeLiters());
}

TEST(GetVolumeLiters_ReturnsCorrectValue) {
    AirGrill grill("CompactGrill", false, 8, false);
    CHECK_EQUAL(8, grill.getVolumeLiters());
}

TEST(SetVolumeLiters_UpdatesValue) {
    AirGrill grill("AdjustableGrill", true, 10, true);
    AirGrill g;
    grill.setVolumeLiters(15);
    CHECK_EQUAL(15, grill.getVolumeLiters());
}
}

SUITE(BikeTests) {

TEST(DefaultConstructor_InitializesFields) {
    Bike bike;
    CHECK_EQUAL("", bike.getModel());
    CHECK_EQUAL(0, bike.getCapacity());
    CHECK_EQUAL(false, bike.getIsElectric());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Bike bike("X-Trail", 1, true);
    CHECK_EQUAL("X-Trail", bike.getModel());
    CHECK_EQUAL(1, bike.getCapacity());
    CHECK_EQUAL(true, bike.getIsElectric());
}

TEST(GetIsElectric_ReturnsCorrectValue) {
    Bike bike("EcoRide", 1, false);
    CHECK_EQUAL(false, bike.getIsElectric());
}

TEST(SetIsElectric_UpdatesValue) {
    Bike bike("PowerBike", 1, false);
    bike.setIsElectric(true);
    CHECK_EQUAL(true, bike.getIsElectric());
}
TEST(SpeedUp){
    Bike bike("PowerBike", 1, false);
    Delivery d;
    d.setTime(100);
    bike.speedUp(d);
    CHECK_EQUAL(50, d.getTime());
}
    

}
SUITE(BonusTests) {

TEST(DefaultConstructor_InitializesFields) {
    Bonus b;
    CHECK_EQUAL("", b.getName());
    CHECK_EQUAL(0.0, b.getDiscount());
    CHECK_CLOSE(static_cast<double>(time(nullptr)), static_cast<double>(b.getExpirationTime()), 2.0);
}

TEST(ParameterizedConstructor_SetsValidFields) {
    time_t future = time(nullptr) + 3600;
    Bonus b("Holiday", 15.0, future, true);
    CHECK_EQUAL("Holiday", b.getName());
    CHECK_EQUAL(15.0, b.getDiscount());
    CHECK_EQUAL(future, b.getExpirationTime());
}

TEST(SetName_UpdatesName) {
    Bonus b;
    b.setName("Black Friday");
    CHECK_EQUAL("Black Friday", b.getName());
}

TEST(SetDiscount_ValidValue) {
    Bonus b;
    b.setDiscount(25.0);
    CHECK_EQUAL(25.0, b.getDiscount());
}

TEST(SetExpirationTime_UpdatesTime) {
    Bonus b;
    time_t t = time(nullptr) + 5000;
    b.setExpirationTime(t);
    CHECK_EQUAL(t, b.getExpirationTime());
}

TEST(IsExpired_ReturnsFalseForFuture) {
    Bonus b("Promo", 10.0, time(nullptr) + 1000, true);
    CHECK_EQUAL(false, b.isExpired());
}

TEST(IsExpired_ReturnsTrueForPast) {
    Bonus b("Old", 10.0, time(nullptr) - 1000, true);
    CHECK_EQUAL(true, b.isExpired());
}


}
SUITE(CarTests) {

TEST(DefaultConstructor_InitializesFields) {
    Car car;
    CHECK_EQUAL("", car.getModel());
    CHECK_EQUAL(0, car.getCapacity());
    CHECK_EQUAL(4, car.getSeatCount());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Car car("Sedan", 5, 5);
    CHECK_EQUAL("Sedan", car.getModel());
    CHECK_EQUAL(5, car.getCapacity());
    CHECK_EQUAL(5, car.getSeatCount());
}

TEST(GetSeatCount_ReturnsCorrectValue) {
    Car car("Coupe", 2, 2);
    CHECK_EQUAL(2, car.getSeatCount());
}

TEST(SetSeatCount_UpdatesValue) {
    Car car("Van", 7, 7);
    car.setSeatCount(9);
    CHECK_EQUAL(9, car.getSeatCount());
}
TEST(FarAway){
    Car car("Van", 7, 7);
    Delivery d;
    DeliveryRoute dr;
    d.setTime(100);
    dr.setTotalDistance(200);
    d.setDeliveryRoute(dr);
    car.farAway(d);
    CHECK_EQUAL(50, d.getTime());
}
}


SUITE(CEOTests) {

TEST(DefaultConstructor_InitializesAsWorker) {
    CEO ceo;
    CHECK_EQUAL("", ceo.getName());
    CHECK_EQUAL(0, ceo.getSalary());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    CEO ceo("Alice", 10000);
    CHECK_EQUAL("Alice", ceo.getName());
    CHECK_EQUAL(10000, ceo.getSalary());
}

TEST(HireManager_ThrowsWhenCEOIsNotManager) {
    CEO ceo("Bob", 12000);
    Restaurant restaurant;
    Manager someoneElse("NotBob", 5000);
    restaurant.setManager(someoneElse);

    Manager newManager("Charlie", 5000);
    CHECK_THROW(ceo.hireManager(newManager, restaurant), UnempolymentError);
}
TEST(FireManager_ThrowsWhenCEOIsNotManager) {
    CEO ceo("Bob", 12000);
    Restaurant restaurant;
    Manager someoneElse("NotBob", 5000);
    restaurant.setManager(someoneElse);

    CHECK_THROW(ceo.fireManager(restaurant), UnempolymentError);
}
}

SUITE(ComboMealTests) {

TEST(Constructor_SetsFieldsCorrectly) {
    vector<Eatable> items = {
        Eatable("Burger", 5.0, 10, time(0) + 7200),
        Eatable("Fries", 2.5, 5, time(0) + 7200)
    };
    ComboMeal combo("Lunch Combo", items, 9.99);

    CHECK_EQUAL("Lunch Combo", combo.getName());
    CHECK_EQUAL(9.99, combo.getPrice());
    CHECK_EQUAL(true, combo.isAvailable());
    CHECK_EQUAL(2, combo.getIncludedItems().size());
    CHECK_EQUAL("Burger", combo.getIncludedItems()[0].getName());
    CHECK_EQUAL(5.0, combo.getIncludedItems()[0].getCost());
    CHECK_EQUAL(10, combo.getIncludedItems()[0].getTime());
}

TEST(SetName_UpdatesName) {
    ComboMeal combo("Old Name", {}, 5.0);
    combo.setName("New Name");
    CHECK_EQUAL("New Name", combo.getName());
}

TEST(SetPrice_UpdatesPrice) {
    ComboMeal combo("Combo", {}, 5.0);
    ComboMeal c;
    combo.setPrice(7.5);
    CHECK_EQUAL(7.5, combo.getPrice());
}

TEST(SetAvailability_UpdatesFlag) {
    ComboMeal combo("Combo", {}, 5.0);
    combo.setAvailability(false);
    CHECK_EQUAL(false, combo.isAvailable());
}

TEST(AddItem_AppendsToList) {
    ComboMeal combo("Combo", {}, 5.0);
    combo.addItem(Eatable("Drink", 1.5, 2, time(0) + 7200));
    CHECK_EQUAL(1, combo.getIncludedItems().size());
    CHECK_EQUAL("Drink", combo.getIncludedItems()[0].getName());
}

TEST(RemoveItem_RemovesMatchingItem) {
    vector<Eatable> items = {
        Eatable("Burger", 5.0, 10, time(0) + 7200),
        Eatable("Fries", 2.5, 5, time(0) + 7200),
        Eatable("Drink", 1.5, 2, time(0) + 7200)
    };
    ComboMeal combo("Combo", items, 10.0);
    combo.removeItem(Eatable("Fries", 2.5, 5, time(0) + 7200));
    CHECK_EQUAL("Burger", combo.getIncludedItems()[0].getName());
    CHECK_EQUAL("Drink", combo.getIncludedItems()[1].getName());
}

TEST(RemoveItem_NoMatch_DoesNothing) {
    vector<Eatable> items = {
        Eatable("Burger", 5.0, 10, time(0) + 7200),
        Eatable("Fries", 2.5, 5, time(0) + 7200)
    };
    ComboMeal combo("Combo", items, 10.0);
    combo.removeItem(Eatable("IceCream", 3.0, 0, time(0) + 7200));
    CHECK_EQUAL(2, combo.getIncludedItems().size());
}

TEST(ClearItems_RemovesAll) {
    vector<Eatable> items = {
        Eatable("Burger", 5.0, 10, time(0) + 7200),
        Eatable("Fries", 2.5, 5, time(0) + 7200)
    };
    ComboMeal combo("Combo", items, 10.0);
    combo.clearItems();
    CHECK_EQUAL(0, combo.getIncludedItems().size());
}

}

SUITE(ComplaintTests) {

TEST(DefaultBadWords_IsEmptyInitially) {
    Complaint complaint;
    CHECK_EQUAL("", complaint.getBadWords());
}

TEST(SetBadWords_StoresCorrectValue) {
    Complaint complaint;
    complaint.setBadWords("Terrible service, rude staff");
    CHECK_EQUAL("Terrible service, rude staff", complaint.getBadWords());
}

TEST(SetBadWords_OverwritesPreviousValue) {
    Complaint complaint;
    Complaint complaint1("saffa");
    complaint.setBadWords("Cold food");
    complaint.setBadWords("Late delivery");
    CHECK_EQUAL("Late delivery", complaint.getBadWords());
}

}

SUITE(ComplaintBookTests) {

TEST(DefaultConstructor_InitializesEmptyList) {
    ComplaintBook book;
    CHECK_EQUAL(0, book.getComplaints().size());
}

TEST(ParameterizedConstructor_SetsInitialComplaints) {
    Complaint c1; c1.setBadWords("Late delivery");
    Complaint c2; c2.setBadWords("Cold food");
    vector<Complaint> initial = {c1, c2};

    ComplaintBook book(initial);
    CHECK_EQUAL(2, book.getComplaints().size());
    CHECK_EQUAL("Late delivery", book.getComplaints()[0].getBadWords());
    CHECK_EQUAL("Cold food", book.getComplaints()[1].getBadWords());
}

TEST(AddComplaint_AppendsToList) {
    ComplaintBook book;
    Complaint c; c.setBadWords("Rude staff");
    book.addComplaint(c);

    CHECK_EQUAL(1, book.getComplaints().size());
    CHECK_EQUAL("Rude staff", book.getComplaints()[0].getBadWords());
}

TEST(ClearComplaints_RemovesAll) {
    Complaint c1; c1.setBadWords("Late delivery");
    Complaint c2; c2.setBadWords("Cold food");
    ComplaintBook book({c1, c2});

    book.clearComplaints();
    CHECK_EQUAL(0, book.getComplaints().size());
}

}

SUITE(CookTests) {

TEST(Constructor_DefaultValues) {
    Cook cook;
    CHECK_EQUAL("", cook.getName());
    CHECK_EQUAL(0, cook.getSalary());
    CHECK_EQUAL(true, cook.getActive());
}

TEST(Constructor_ParameterizedValues) {
    Cook cook("Ivan", 3000, false);
    CHECK_EQUAL("Ivan", cook.getName());
    CHECK_EQUAL(3000, cook.getSalary());
    CHECK_EQUAL(false, cook.getActive());
}

TEST(SetActive_ChangesStatus) {
    Cook cook("Ivan", 3000, true);
    cook.setActive(false);
    CHECK_EQUAL(false, cook.getActive());
}

TEST(Cooking_ThrowsIfInactive) {
    Cook cook("Ivan", 3000, false);
    Eatable eat("Burger", 5.0, 10, time(0) + 7200);
    OrderPosition pos(eat, 1);
    CHECK_THROW(cook.Cooking(pos), CookBusyError);
}

TEST(Cooking_SetsOrderDoneIfActive) {
    Cook cook("Ivan", 3000, true);
    Eatable eat("Burger", 5.0, 10, time(0) + 7200);
    OrderPosition pos(eat, 1);
    cook.Cooking(pos);
    CHECK_EQUAL(true, pos.isDone());
}

TEST(TakeProducts_ThrowsIfCookNotInRestaurant) {
    Cook cook("Ivan", 3000, true);
    Restaurant r;
    Product p("Tomato", 20);
    CHECK_THROW(cook.takeProducts(p, 1, r), UnempolymentError);
}
}

SUITE(CourierTests) {

TEST(DefaultConstructor_InitializesFields) {
    Courier courier;
    CHECK_EQUAL("", courier.getName());
    CHECK_EQUAL(0, courier.getSalary());
    CHECK_EQUAL("+0000000000", courier.getPhoneNumber());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Courier courier("Ivan", 25, "+375291234567");
    CHECK_EQUAL("Ivan", courier.getName());
    CHECK_EQUAL(25, courier.getSalary());
    CHECK_EQUAL("+375291234567", courier.getPhoneNumber());
}

TEST(SetPhoneNumber_ValidFormat_UpdatesValue) {
    Courier courier;
    courier.setPhoneNumber("+1234567890");
    CHECK_EQUAL("+1234567890", courier.getPhoneNumber());
}

TEST(SetPhoneNumber_InvalidFormat_Throws) {
    Courier courier;
    CHECK_THROW(courier.setPhoneNumber("1234567890"), InvalidNumberError);
}

}

SUITE(CustomerTests) {
    TEST(AddBonusAndFind) {
        Customer c("Ivan", 30, "ivan@example.com", 100, Order());

        time_t tomorrow = time(nullptr) + 24*60*60;
        Bonus b("Welcome", 10.0, tomorrow, true);

        CHECK(!c.findBonus(b));
        c.addBonus(b);
        CHECK(c.findBonus(b));
    }

    TEST(UseBonusSuccess) {
        Customer c("Ivan", 30, "ivan@example.com", 100, Order());

        time_t tomorrow = time(nullptr) + 24*60*60;
        Bonus b("Discount10", 10.0, tomorrow, true);
        c.addBonus(b);

        int before = c.getCash();
        c.useBonus(b);
        CHECK_EQUAL(before + static_cast<int>(b.getDiscount()), c.getCash());
    }

    TEST(UseBonusExpiredThrows) {
        Customer c("Ivan", 30, "ivan@example.com", 100, Order());

        time_t yesterday = time(nullptr) - 24*60*60;
        Bonus expired("OldBonus", 15.0, yesterday, true);
        c.addBonus(expired);

        CHECK_THROW(c.useBonus(expired), BonusExpired);
    }

    TEST(UseBonusNotOwnedThrows) {
        Customer c("Ivan", 30, "ivan@example.com", 100, Order());

        time_t tomorrow = time(nullptr) + 24*60*60;
        Bonus b("AlienBonus", 5.0, tomorrow, true);

        CHECK_THROW(c.useBonus(b), BonusExpired);
    }

    TEST(LeaveRatingSuccess) {
        Customer c("Ivan", 30, "ivan@example.com", 100, Order());
        Restaurant r;
        Rating rating(5, "Excellent!");

        c.leaveRating(r, rating);
        CHECK_EQUAL(1, r.getRatings().size());
        CHECK_EQUAL(5, r.getRatings()[0].getStars());
    }

    TEST(LeaveComplaintSuccess) {
        Customer c("Ivan", 30, "ivan@example.com", 100, Order());
        ComplaintBook cb;
        Complaint complaint("Delivery was late");

        c.leaveComplaint(cb, complaint);
        CHECK_EQUAL(1, cb.getComplaints().size());
        CHECK_EQUAL("Delivery was late", cb.getComplaints()[0].getBadWords());
    }

    TEST(ClearBonuses) {
        Customer c("Ivan", 30, "ivan@example.com", 100, Order());

        time_t tomorrow = time(nullptr) + 24*60*60;
        Bonus b1("B1", 10.0, tomorrow, true);
        Bonus b2("B2", 20.0, tomorrow, true);

        c.addBonus(b1);
        c.addBonus(b2);
        CHECK_EQUAL(2, c.getBonuses().size());

        c.clearBonuses();
        CHECK_EQUAL(0, c.getBonuses().size());
    }
}

 SUITE(DeliveryTests) {

TEST(Constructor_SetsVehicleAndCourier) {
    Vehicle v("ModelX", 2); 
    Courier c("Ivan", 25, "+375291234567");
    Delivery d(v, c);

    CHECK_EQUAL(v, d.getVehicle());
    CHECK_EQUAL(c, d.getCourier());
}

TEST(SetVehicle_UpdatesVehicle) {
    Vehicle v1("Bike", 1);
    Vehicle v2("Car", 4);
    Courier c("Ivan", 25, "+375291234567");
    Delivery d(v1, c);
    Delivery d1;

    d.setVehicle(v2);
    CHECK_EQUAL(v2, d.getVehicle());
}

TEST(SetCourier_UpdatesCourier) {
    Courier c1("Ivan", 25, "+375291234567");
    Courier c2("Anna", 30, "+375291111111");
    Vehicle v("Car", 4);
    Delivery d(v, c1);

    d.setCourier(c2);
    CHECK_EQUAL(c2, d.getCourier());
}

TEST(SetOrder_UpdatesOrder) {
    Vehicle v("Car", 4);
    Courier c("Ivan", 25, "+375291234567");
    Delivery d(v, c);

    Eatable eat("Pizza", 10.0, 15, time(0) + 7200);
    OrderPosition pos(eat, 1);
    Order order;

    d.setOrder(order);
    CHECK_EQUAL(0, d.getOrder().getEatList().size());
}

TEST(SetDeliveryRoute_UpdatesRoute) {
    Vehicle v("Car", 4);
    Courier c("Ivan", 25, "+375291234567");
    Delivery d(v, c);

    DeliveryRoute route("Start", "End", 5.0);
    d.setDeliveryRoute(route);
    CHECK_EQUAL(true, route == d.getDeliveryRoute());
}

TEST(ConfirmDelivery_SetsOrderDeliveredTrue) {
    Vehicle v("Car", 4);
    Courier c("Ivan", 25, "+375291234567");
    Delivery d(v, c);

    Order order;
    order.setIsDelievered(false);
    d.setOrder(order);

    d.confirmDelivery();
    CHECK_EQUAL(true, d.getOrder().isDelievered());
}

}
SUITE(DeliveryRouteTests) {

TEST(DefaultConstructor_InitializesFields) {
    DeliveryRoute route;
    CHECK_EQUAL("", route.getStartPoint());
    CHECK_EQUAL("", route.getEndPoint());
    CHECK_EQUAL(0.0, route.getTotalDistance());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    DeliveryRoute route("Warehouse", "Customer", 12.5);
    CHECK_EQUAL("Warehouse", route.getStartPoint());
    CHECK_EQUAL("Customer", route.getEndPoint());
    CHECK_EQUAL(12.5, route.getTotalDistance());
}

TEST(SetStartPoint_UpdatesValue) {
    DeliveryRoute route;
    route.setStartPoint("Kitchen");
    CHECK_EQUAL("Kitchen", route.getStartPoint());
}

TEST(SetEndPoint_UpdatesValue) {
    DeliveryRoute route;
    route.setEndPoint("Table 5");
    CHECK_EQUAL("Table 5", route.getEndPoint());
}

TEST(SetTotalDistance_UpdatesValue) {
    DeliveryRoute route;
    route.setTotalDistance(8.75);
    CHECK_EQUAL(8.75, route.getTotalDistance());
}

TEST(EqualityOperator_ReturnsTrueForIdenticalRoutes) {
    DeliveryRoute r1("A", "B", 10.0);
    DeliveryRoute r2("A", "B", 10.0);
    CHECK(r1 == r2);
}

TEST(EqualityOperator_ReturnsFalseForDifferentRoutes) {
    DeliveryRoute r1("A", "B", 10.0);
    DeliveryRoute r2("A", "C", 10.0);
    CHECK(!(r1 == r2));
}
}
SUITE(DeliveryStatusTests) {

TEST(DefaultConstructor_InitializesFields) {
    DeliveryStatus status;
    CHECK_EQUAL("Pending", status.getStatus());
    CHECK_EQUAL("system", status.getLastUpdatedBy());
    CHECK_EQUAL("", status.getComment());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    DeliveryStatus status("Preparing", "Ivan", "Started cooking");
    CHECK_EQUAL("Preparing", status.getStatus());
    CHECK_EQUAL("Ivan", status.getLastUpdatedBy());
    CHECK_EQUAL("Started cooking", status.getComment());
}

TEST(UpdateStatus_ChangesAllFields) {
    DeliveryStatus status;
    status.updateStatus("Out for Delivery", "Courier", "Left the restaurant");
    CHECK_EQUAL("Out for Delivery", status.getStatus());
    CHECK_EQUAL("Courier", status.getLastUpdatedBy());
    CHECK_EQUAL("Left the restaurant", status.getComment());
}

TEST(EqualityOperator_ReturnsTrueForIdenticalStatuses) {
    DeliveryStatus s1("Delivered", "Courier", "Handed to customer");
    DeliveryStatus s2("Delivered", "Courier", "Handed to customer");
    CHECK(s1 == s2);
}

TEST(EqualityOperator_ReturnsFalseForDifferentStatuses) {
    DeliveryStatus s1("Delivered", "Courier", "Handed to customer");
    DeliveryStatus s2("Cancelled", "System", "User cancelled");
    CHECK(!(s1 == s2));
}

}

SUITE(DinningRoomTests) {

TEST(DefaultConstructor_InitializesFields) {
    DinningRoom dr;
    CHECK_EQUAL(0, dr.getArea());
    CHECK_EQUAL(0, dr.getTablesCount());
    CHECK_EQUAL(true, dr.getIsOpen());
    CHECK_EQUAL(0, dr.getRequirement().getMinArea());
    CHECK_EQUAL(false, dr.getRequirement().getRequiresElectricity());
    CHECK_EQUAL(false, dr.getRequirement().getMustBeAccessible());
    CHECK_EQUAL(0, dr.getRequirement().getMinTablesCount());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    DinningRoomRequirement req(50, true, true, 10, true);
    DinningRoom dr(80, req, 12, false);

    CHECK_EQUAL(80, dr.getArea());
    CHECK_EQUAL(12, dr.getTablesCount());
    CHECK_EQUAL(false, dr.getIsOpen());
    CHECK_EQUAL(50, dr.getRequirement().getMinArea());
    CHECK_EQUAL(true, dr.getRequirement().getRequiresElectricity());
    CHECK_EQUAL(true, dr.getRequirement().getMustBeAccessible());
    CHECK_EQUAL(10, dr.getRequirement().getMinTablesCount());
}

TEST(SetTablesCount_UpdatesValue) {
    DinningRoom dr;
    dr.setTablesCount(20);
    CHECK_EQUAL(20, dr.getTablesCount());
}

TEST(SetIsOpen_UpdatesValue) {
    DinningRoom dr;
    dr.setIsOpen(false);
    CHECK_EQUAL(false, dr.getIsOpen());
}

TEST(SetRequirement_UpdatesValue) {
    DinningRoom dr;
    DinningRoomRequirement req(60, true, false, 15, true);
    dr.setRequirement(req);

    CHECK_EQUAL(60, dr.getRequirement().getMinArea());
    CHECK_EQUAL(true, dr.getRequirement().getRequiresElectricity());
    CHECK_EQUAL(false, dr.getRequirement().getMustBeAccessible());
    CHECK_EQUAL(15, dr.getRequirement().getMinTablesCount());
    CHECK_EQUAL(true, dr.getRequirement().getMustBeOpen());
}

}

SUITE(DinningRoomRequirementTests) {

TEST(DefaultConstructor_InitializesFields) {
    DinningRoomRequirement req;
    CHECK_EQUAL(0, req.getMinArea());
    CHECK_EQUAL(false, req.getRequiresElectricity());
    CHECK_EQUAL(false, req.getMustBeAccessible());
    CHECK_EQUAL(0, req.getMinTablesCount());
    CHECK_EQUAL(false, req.getMustBeOpen());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    DinningRoomRequirement req(100, true, true, 20, true);
    CHECK_EQUAL(100, req.getMinArea());
    CHECK_EQUAL(true, req.getRequiresElectricity());
    CHECK_EQUAL(true, req.getMustBeAccessible());
    CHECK_EQUAL(20, req.getMinTablesCount());
    CHECK_EQUAL(true, req.getMustBeOpen());
}

TEST(SetMinTablesCount_UpdatesValue) {
    DinningRoomRequirement req;
    req.setMinTablesCount(15);
    CHECK_EQUAL(15, req.getMinTablesCount());
}

TEST(SetMustBeOpen_UpdatesValue) {
    DinningRoomRequirement req;
    req.setMustBeOpen(true);
    CHECK_EQUAL(true, req.getMustBeOpen());
}

TEST(IsDinningRoomSatisfiedBy_ReturnsTrueIfAllConditionsMet) {
    DinningRoomRequirement req(100, true, true, 10, true);
    CHECK(req.isDinningRoomSatisfiedBy(120, true, true, 8, true));
}

TEST(IsDinningRoomSatisfiedBy_ReturnsFalseIfAreaTooSmall) {
    DinningRoomRequirement req(100, true, true, 10, true);
    CHECK(!req.isDinningRoomSatisfiedBy(90, true, true, 8, true));
}

TEST(IsDinningRoomSatisfiedBy_ReturnsFalseIfNotOpenWhenRequired) {
    DinningRoomRequirement req(100, true, true, 10, true);
    CHECK(!req.isDinningRoomSatisfiedBy(120, true, true, 8, false));
}

TEST(IsDinningRoomSatisfiedBy_ReturnsTrueIfOpenNotRequired) {
    DinningRoomRequirement req(100, true, true, 10, false);
    CHECK(req.isDinningRoomSatisfiedBy(120, true, true, 8, false));
}

TEST(IsDinningRoomSatisfiedBy_ReturnsFalseIfTableCountTooHigh) {
    DinningRoomRequirement req(100, true, true, 5, true);
    CHECK(!req.isDinningRoomSatisfiedBy(120, true, true, 10, true));
}

}



SUITE(DishwasherTests) {

TEST(Constructor_SetsAllFieldsCorrectly) {
    Dishwasher dw("Bosch", true, 5, true);
    Dishwasher d;
    CHECK_EQUAL("Bosch", dw.getName());
    CHECK_EQUAL(true, dw.getIsElectric());
    CHECK_EQUAL(true, dw.getIsAvailable());
    CHECK_EQUAL(5, dw.getProgramCount());
}

TEST(GetProgramCount_ReturnsCorrectValue) {
    Dishwasher dw("LG", true, 3, false);
    CHECK_EQUAL(3, dw.getProgramCount());
}

TEST(SetProgramCount_UpdatesValue) {
    Dishwasher dw("Samsung", true, 4, true);
    dw.setProgramCount(7);
    CHECK_EQUAL(7, dw.getProgramCount());
}

}
SUITE(DrinkTests) {

TEST(DefaultConstructor_InitializesFields) {
    Drink d;
    CHECK_EQUAL("", d.getName());
    CHECK_EQUAL(0, d.getCost());
    CHECK_EQUAL(0, d.getTime());
    CHECK_EQUAL(0, d.getCalories());
    CHECK_EQUAL(false, d.isEighteenPlus());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Drink d("Cola", 3, 120);
    CHECK_EQUAL("Cola", d.getName());
    CHECK_EQUAL(3, d.getCost());
    CHECK_EQUAL(0, d.getTime());
    CHECK_EQUAL(120, d.getCalories());
    CHECK_EQUAL(false, d.isEighteenPlus());
}

TEST(SetCalories_UpdatesValue) {
    Drink d;
    d.setCalories(250);
    CHECK_EQUAL(250, d.getCalories());
}

TEST(SetIsEighteenPlus_UpdatesFlag) {
    Drink d;
    d.setIsEighteenPlus(true);
    CHECK_EQUAL(true, d.isEighteenPlus());
}
}


SUITE(EatableTests) {

TEST(DefaultConstructor_InitializesFields) {
    Eatable e;
    CHECK_EQUAL("", e.getName());
    CHECK_EQUAL(0.0, e.getCost());
    CHECK_EQUAL(0, e.getTime());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Eatable e("Burger", 5.99, 12, time(0) + 7200);
    CHECK_EQUAL("Burger", e.getName());
    CHECK_EQUAL(5.99, e.getCost());
    CHECK_EQUAL(12, e.getTime());
}

TEST(CopyConstructor_CopiesNameAndCostOnly) {
    Eatable original("Pizza", 7.5, 20, time(0) + 7200);
    Eatable copy(original);
    CHECK_EQUAL("Pizza", copy.getName());
    CHECK_EQUAL(7.5, copy.getCost());
    CHECK_EQUAL(20, copy.getTime());
}

TEST(SetName_UpdatesValue) {
    Eatable e;
    e.setName("Soup");
    CHECK_EQUAL("Soup", e.getName());
}

TEST(SetCost_UpdatesValue) {
    Eatable e;
    e.setCost(3.25);
    CHECK_EQUAL(3.25, e.getCost());
}

TEST(SetTime_UpdatesValue) {
    Eatable e;
    e.setTime(15);
    CHECK_EQUAL(15, e.getTime());
}

TEST(EqualityOperator_ReturnsTrueForIdenticalObjects) {
    Eatable e1("Salad", 4.0, 5, time(0) + 7200);
    Eatable e2("Salad", 4.0, 5, time(0) + 7200);
    CHECK(e1 == e2);
}

TEST(EqualityOperator_ReturnsFalseForDifferentObjects) {
    Eatable e1("Salad", 4.0, 5, time(0) + 7200);
    Eatable e2("Soup", 4.0, 5, time(0) + 7200);
    CHECK(!(e1 == e2));
}
TEST(GetTime_UpdatesValue) {
    Eatable e1("Salad", 4.0, 5, time(0) + 7200);
    Eatable e2("Soup", 4.0, 5, time(0) + 7200);
    e1.setExparationTime(time(0) + 3600);
    CHECK_EQUAL(e1.getExparationTime(), time(0) + 3600);
}
}


SUITE(FoodTests) {

TEST(Constructor_SetsFieldsCorrectly) {
    Product p1("Tomato", 20);
    Product p2("Cheese", 100);
    vector<FoodPosition> composition = {
        FoodPosition{p1, 2},
        FoodPosition{p2, 1}
    };

    Food food("Pizza", 10, composition, 15, time(0) + 7200);
    CHECK_EQUAL("Pizza", food.getName());
    CHECK_EQUAL(10, food.getCost());
    CHECK_EQUAL(2, food.getComposition().size());
    CHECK_EQUAL(time(0) + 7200, food.getExparationTime());
}

TEST(SetComposition_UpdatesComposition) {
    Food food("Soup", 5, {}, 10,time(0) + 7200);
    Food f;
    Product p("Salt", 0);
    vector<FoodPosition> comp = { FoodPosition{p, 1} };
    food.setComposition(comp);
    CHECK_EQUAL(1, food.getComposition().size());
}

TEST(GetCalories_ComputesTotalCorrectly) {
    Product p1("Tomato", 20);
    Product p2("Cheese", 100);
    Food f;
    vector<FoodPosition> composition = {
        FoodPosition{p1, 3},
        FoodPosition{p2, 2}
    };
    Food food("Salad", 8, composition, 5, time(0) + 7200);
    CHECK_EQUAL(260, food.getCalories());
}

}

SUITE(FoodPositionTests) {

TEST(DefaultConstructor_InitializesFields) {
    FoodPosition fp;
    CHECK_EQUAL("", fp.getProduct().getName());
    CHECK_EQUAL(0, fp.getProduct().getCalories());
    CHECK_EQUAL(0, fp.getAmount());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Product p("Tomato", 20);
    FoodPosition fp(p, 3);
    CHECK_EQUAL("Tomato", fp.getProduct().getName());
    CHECK_EQUAL(20, fp.getProduct().getCalories());
    CHECK_EQUAL(3, fp.getAmount());
}

TEST(SetProduct_UpdatesProduct) {
    Product p1("Cheese", 100);
    Product p2("Meat", 200);
    FoodPosition fp(p1, 2);
    fp.setProduct(p2);
    CHECK_EQUAL("Meat", fp.getProduct().getName());
    CHECK_EQUAL(200, fp.getProduct().getCalories());
}

TEST(SetAmount_ValidValue_UpdatesAmount) {
    Product p("Salt", 0);
    FoodPosition fp(p, 1);
    fp.setAmount(5);
    CHECK_EQUAL(5, fp.getAmount());
}

TEST(SetAmount_Negative_Throws) {
    Product p("Sugar", 0);
    FoodPosition fp(p, 1);
    CHECK_THROW(fp.setAmount(-2), InvalidNumberError);
}
}

SUITE(FreezerTests) {

TEST(Constructor_SetsAllFieldsCorrectly) {
    Freezer f("Arctic", true, -18, true);
    CHECK_EQUAL("Arctic", f.getName());
    CHECK_EQUAL(true, f.getIsElectric());
    CHECK_EQUAL(true, f.getIsAvailable());
    CHECK_EQUAL(-18, f.getMinTemperature());
}

TEST(GetMinTemperature_ReturnsCorrectValue) {
    Freezer f("Nord", true, -25, false);
    CHECK_EQUAL(-25, f.getMinTemperature());
}

TEST(SetMinTemperature_UpdatesValue) {
    Freezer f("Frosty", true, -20, true);
    f.setMinTemperature(-30);
    CHECK_EQUAL(-30, f.getMinTemperature());
}

}

SUITE(FridgeTests) {
TEST(Constructor_SetsAllFieldsCorrectly) {
    Fridge fridge("Samsung", true, 300, true);
    CHECK_EQUAL("Samsung", fridge.getName());
    CHECK_EQUAL(true, fridge.getIsElectric());
    CHECK_EQUAL(true, fridge.getIsAvailable());
    CHECK_EQUAL(300, fridge.getCapacityLiters());
}

TEST(GetCapacityLiters_ReturnsCorrectValue) {
    Fridge fridge("LG", true, 250, false);
    CHECK_EQUAL(250, fridge.getCapacityLiters());
}

TEST(SetCapacityLiters_UpdatesValue) {
    Fridge fridge("Bosch", true, 200, true);
    fridge.setCapacityLiters(350);
    CHECK_EQUAL(350, fridge.getCapacityLiters());
}

}

SUITE(KitchenTests) {

TEST(DefaultConstructor_InitializesFields) {
    Kitchen kitchen;
    CHECK_EQUAL(0, kitchen.getCooksAmount());

    KitchenRequirement req = kitchen.getRequierement();
    CHECK_EQUAL(0, req.getMinArea());
    CHECK_EQUAL(false, req.getRequiresElectricity());
    CHECK_EQUAL(false, req.getMustBeAccessible());
    CHECK_EQUAL(0, req.getMinCooksNeeded());
    CHECK_EQUAL(false, req.getNeedsAppliance());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Kitchen kitchen(120, 3, true, true);
    CHECK_EQUAL(3, kitchen.getCooksAmount());

    KitchenRequirement req = kitchen.getRequierement();
    CHECK_EQUAL(120, req.getMinArea());
    CHECK_EQUAL(true, req.getRequiresElectricity());
    CHECK_EQUAL(true, req.getMustBeAccessible());
    CHECK_EQUAL(3, req.getMinCooksNeeded());
    CHECK_EQUAL(true, req.getNeedsAppliance());
}

TEST(SetCooksAmount_UpdatesValue) {
    Kitchen kitchen;
    kitchen.setCooksAmount(5);
    CHECK_EQUAL(5, kitchen.getCooksAmount());
}

TEST(SetRequierement_UpdatesRequirement) {
    Kitchen kitchen;
    KitchenRequirement req(80, false, true, 2, true);
    kitchen.setRequierement(req);

    KitchenRequirement actual = kitchen.getRequierement();
    CHECK_EQUAL(80, actual.getMinArea());
    CHECK_EQUAL(false, actual.getRequiresElectricity());
    CHECK_EQUAL(true, actual.getMustBeAccessible());
    CHECK_EQUAL(2, actual.getMinCooksNeeded());
    CHECK_EQUAL(true, actual.getNeedsAppliance());
}
}

SUITE(KitchenApplianceTests) {

TEST(DefaultConstructor_InitializesFields) {
    KitchenAppliance appliance;
    CHECK_EQUAL("", appliance.getName());
    CHECK_EQUAL(false, appliance.getIsElectric());
    CHECK_EQUAL(true, appliance.getIsAvailable());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    KitchenAppliance appliance("Blender", true, false);
    CHECK_EQUAL("Blender", appliance.getName());
    CHECK_EQUAL(true, appliance.getIsElectric());
    CHECK_EQUAL(false, appliance.getIsAvailable());
}

TEST(SetName_UpdatesValue) {
    KitchenAppliance appliance;
    appliance.setName("Toaster");
    CHECK_EQUAL("Toaster", appliance.getName());
}

TEST(SetIsElectric_UpdatesValue) {
    KitchenAppliance appliance;
    appliance.setIsElectric(true);
    CHECK_EQUAL(true, appliance.getIsElectric());
}

TEST(SetIsAvailable_UpdatesValue) {
    KitchenAppliance appliance;
    appliance.setIsAvailable(false);
    CHECK_EQUAL(false, appliance.getIsAvailable());
}

}

SUITE(KitchenRequirementTests) {

TEST(DefaultConstructor_InitializesFields) {
    KitchenRequirement req;
    CHECK_EQUAL(0, req.getMinArea());
    CHECK_EQUAL(false, req.getRequiresElectricity());
    CHECK_EQUAL(false, req.getMustBeAccessible());
    CHECK_EQUAL(0, req.getMinCooksNeeded());
    CHECK_EQUAL(false, req.getNeedsAppliance());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    KitchenRequirement req(50, true, true, 3, true);
    CHECK_EQUAL(50, req.getMinArea());
    CHECK_EQUAL(true, req.getRequiresElectricity());
    CHECK_EQUAL(true, req.getMustBeAccessible());
    CHECK_EQUAL(3, req.getMinCooksNeeded());
    CHECK_EQUAL(true, req.getNeedsAppliance());
}

TEST(SetMinCooksNeeded_UpdatesValue) {
    KitchenRequirement req;
    req.setMinCooksNeeded(5);
    CHECK_EQUAL(5, req.getMinCooksNeeded());
}

TEST(SetNeedsAppliance_UpdatesValue) {
    KitchenRequirement req;
    req.setNeedsAppliance(true);
    CHECK_EQUAL(true, req.getNeedsAppliance());
}

TEST(IsKitchenSatisfiedBy_ReturnsTrueIfAllConditionsMet) {
    KitchenRequirement req(100, true, true, 4, true);
    CHECK(req.isKitchenSatisfiedBy(120, true, true, 5, true));
}

TEST(IsKitchenSatisfiedBy_ReturnsFalseIfAreaTooSmall) {
    KitchenRequirement req(100, true, true, 4, true);
    CHECK(!req.isKitchenSatisfiedBy(90, true, true, 5, true));
}

TEST(IsKitchenSatisfiedBy_ReturnsFalseIfNotEnoughCooks) {
    KitchenRequirement req(100, true, true, 4, true);
    CHECK(!req.isKitchenSatisfiedBy(120, true, true, 3, true));
}

TEST(IsKitchenSatisfiedBy_ReturnsFalseIfApplianceRequiredButMissing) {
    KitchenRequirement req(100, true, true, 4, true);
    CHECK(!req.isKitchenSatisfiedBy(120, true, true, 5, false));
}

TEST(IsKitchenSatisfiedBy_ReturnsTrueIfApplianceNotRequired) {
    KitchenRequirement req(100, true, true, 4, false);
    CHECK(req.isKitchenSatisfiedBy(120, true, true, 5, false));
}

}

SUITE(LoyaltyProgramTests) {

TEST(Constructor_SetsFieldsCorrectly) {
    LoyaltyProgram lp("Gold", 100, 5.0);
    CHECK_EQUAL("Gold", lp.getName());
    CHECK_EQUAL(100, lp.getMinPointsForReward());
    CHECK_EQUAL(5.0, lp.getRewardAmount());
    CHECK_EQUAL(true, lp.isActive());
}

TEST(Deactivate_SetsActiveFalse) {
    LoyaltyProgram lp("Silver", 50, 2.5);
    lp.deactivate();
    CHECK_EQUAL(false, lp.isActive());
}

TEST(Activate_SetsActiveTrue) {
    LoyaltyProgram lp("Silver", 50, 2.5);
    lp.deactivate();
    lp.activate();
    CHECK_EQUAL(true, lp.isActive());
}

TEST(IsEligible_ReturnsTrueIfActiveAndEnoughPoints) {
    LoyaltyProgram lp("Bronze", 30, 1.0);
    CHECK(lp.isEligible(35));
}

TEST(IsEligible_ReturnsFalseIfNotActive) {
    LoyaltyProgram lp("Bronze", 30, 1.0);
    lp.deactivate();
    CHECK(!lp.isEligible(35));
}

TEST(IsEligible_ReturnsFalseIfNotEnoughPoints) {
    LoyaltyProgram lp("Bronze", 30, 1.0);
    CHECK(!lp.isEligible(25));
}

TEST(ClaimReward_ReturnsRewardAndDeductsPoints) {
    LoyaltyProgram lp("Platinum", 100, 10.0);
    int points = 120;
    double reward = lp.claimReward(points);
    CHECK_EQUAL(10.0, reward);
    CHECK_EQUAL(20, points);
}

TEST(ClaimReward_ReturnsZeroIfNotEligible) {
    LoyaltyProgram lp("Platinum", 100, 10.0);
    int points = 80;
    double reward = lp.claimReward(points);
    CHECK_EQUAL(0.0, reward);
    CHECK_EQUAL(80, points); // не изменились
}
}

SUITE(ManagerTests) {

TEST(HireCourier_AddsCourierIfManagerMatches) {
    Manager m("Ivan", 5000);
    Restaurant r;
    r.setManager(m);

    Courier c("Alex", 3000, "+375291234567");
    CHECK_EQUAL(0, r.getCouriers().size());

    m.Hire(c, r);
    CHECK_EQUAL(1, r.getCouriers().size());

    CHECK_EQUAL("Alex", r.getCouriers()[0].getName());
    CHECK_EQUAL(3000, r.getCouriers()[0].getSalary());
    CHECK_EQUAL("+375291234567", r.getCouriers()[0].getPhoneNumber());
}

TEST(HireCourier_ThrowsIfManagerMismatch) {
    Manager m1("Ivan", 5000);
    Manager m2("Anna", 6000);
    Restaurant r;
    r.setManager(m2);

    Courier c("Alex", 25, "+375291234567");
    CHECK_THROW(m1.Hire(c, r), UnempolymentError);
}

TEST(FireCourier_RemovesCourierIfManagerMatches) {
    Manager m("Ivan", 5000);
    Restaurant r;
    r.setManager(m);

    Courier c("Alex", 25, "+375291234567");
    r.addCourier(c);
    CHECK_EQUAL(1, r.getCouriers().size());

    m.Fire(c, r);
    CHECK_EQUAL(0, r.getCouriers().size());
}

TEST(HireCook_AddsCookIfManagerMatches) {
    Manager m("Ivan", 5000);
    Restaurant r;
    r.setManager(m);

    Cook cook("Olga", 2000);
    CHECK_EQUAL(0, r.getCooks().size());

    m.Hire(cook, r);
    CHECK_EQUAL(1, r.getCooks().size());

    CHECK_EQUAL("Olga", r.getCooks()[0].getName());
    CHECK_EQUAL(2000, r.getCooks()[0].getSalary());
}

TEST(FireCook_RemovesCookIfManagerMatches) {
    Manager m("Ivan", 5000);
    Restaurant r;
    r.setManager(m);

    Cook cook("Olga", 2000);
    r.addCook(cook);
    CHECK_EQUAL(1, r.getCooks().size());

    m.Fire(cook, r);
    CHECK_EQUAL(0, r.getCooks().size());
}

TEST(AddEatable_AddsItemToMenuIfManagerMatches) {
    Manager m;
    Restaurant r;
    r.setManager(m);

    Eatable e("Burger", 5.0, 10, time(0) + 7200);
    CHECK_EQUAL(0, r.getMenu().getItems().size());

    m.addEatable(e, r);
    CHECK_EQUAL(1, r.getMenu().getItems().size());

    CHECK_EQUAL("Burger", r.getMenu().getItems()[0].getName());
    CHECK_EQUAL(5.0, r.getMenu().getItems()[0].getCost());
    CHECK_EQUAL(10, r.getMenu().getItems()[0].getTime());
}

TEST(DeleteEatable_RemovesItemFromMenuIfManagerMatches) {
    Manager m("Ivan", 5000);
    Restaurant r;
    r.setManager(m);

    Eatable e("Burger", 5.0, 10, time(0) + 7200);
    m.addEatable(e, r);
    CHECK_EQUAL(1, r.getMenu().getItems().size());

    m.deleteEatable(e, r);
    CHECK_EQUAL(0, r.getMenu().getItems().size());
}

TEST(DeleteEatable_ThrowsIfManagerMismatch) {
    Manager m1("Ivan", 5000);
    Manager m2("Anna", 6000);
    Restaurant r;
    r.setManager(m2);

    Eatable e("Burger", 5.0, 10, time(0) + 7200);
    r.getMenu().getItems().push_back(e);

    CHECK_THROW(m1.deleteEatable(e, r), UnempolymentError);
}
}

SUITE(MenuTests) {

TEST(DefaultConstructor_InitializesEmptyMenu) {
    Menu menu;
    CHECK_EQUAL(0, menu.getItems().size());
}

TEST(ParameterizedConstructor_SetsItemsCorrectly) {
    Eatable e1("Burger", 5.0, 10, time(0) + 7200);
    Eatable e2("Pizza", 7.5, 15, time(0) + 7200);
    vector<Eatable> items = {e1, e2};
    Menu menu(items);
    CHECK_EQUAL(2, menu.getItems().size());
    CHECK(menu.getItems()[0] == e1);
    CHECK(menu.getItems()[1] == e2);
}

TEST(AddItem_AppendsToMenu) {
    Menu menu;
    Eatable e("Soup", 3.0, 5, time(0) + 7200);
    menu.addItem(e);
    CHECK_EQUAL(1, menu.getItems().size());
    CHECK(menu.getItems()[0] == e);
}

TEST(RemoveItemByName_RemovesCorrectItem) {
    Eatable e1("Burger", 5.0, 10, time(0) + 7200);
    Eatable e2("Pizza", 7.5, 15, time(0) + 7200);
    Menu menu({e1, e2});
    menu.removeItemByName("Burger");
    CHECK_EQUAL(1, menu.getItems().size());
    CHECK(menu.getItems()[0] == e2);
}

TEST(RemoveItemByName_DoesNothingIfNotFound) {
    Eatable e("Burger", 5.0, 10, time(0) + 7200);
    Menu menu({e});
    menu.removeItemByName("Pizza");
    CHECK_EQUAL(1, menu.getItems().size());
    CHECK(menu.getItems()[0] == e);
}

TEST(FindItemByName_ReturnsCorrectItem) {
    Eatable e("Burger", 5.0, 10, time(0) + 7200);
    Menu menu({e});
    Eatable found = menu.findItemByName("Burger");
    CHECK(found == e);
}

TEST(FindItemByName_ThrowsIfNotFound) {
    Menu menu;
    CHECK_THROW(menu.findItemByName("Nonexistent"), EatableNotFoundError);
}

TEST(Clear_RemovesAllItems) {
    Eatable e1("Burger", 5.0, 10, time(0) + 7200);
    Eatable e2("Pizza", 7.5, 15, time(0) + 7200);
    Menu menu({e1, e2});
    menu.clear();
    CHECK_EQUAL(0, menu.getItems().size());
}

}

SUITE(NotAuthorisedCustomerTests) {

TEST(DefaultConstructor_InitializesFields) {
    Order o;
    NotAuthorisedCustomer customer;
    NotAuthorisedCustomer customer1(o, 1000);
    CHECK_EQUAL(0, customer.getCash());
    CHECK_EQUAL(0, customer.getOrder().getEatList().size());
}

TEST(SetCash_RejectsNegativeValues) {
    NotAuthorisedCustomer customer;
    customer.setCash(-50);
    CHECK_EQUAL(0, customer.getCash());
}

TEST(SetOrder_UpdatesOrder) {
    NotAuthorisedCustomer customer;
    Order order;
    customer.setOrder(order);
    CHECK_EQUAL(0, customer.getOrder().getEatList().size());
}

TEST(OrderSomething_AddsOrderToRestaurant) {
    NotAuthorisedCustomer customer;
    OrderPosition pos;
    customer.addToOrder(pos);
    customer.setCash(1000);

    Restaurant r;
    CHECK_EQUAL(0, r.getOrders().size());

    customer.orderSomething(r);
    CHECK_EQUAL(1, r.getOrders().size());
    CHECK_EQUAL(1, r.getOrders()[0].getEatList().size());
}

}

SUITE(OrderTests) {

TEST(DefaultValues_AreCorrect) {
    Order order;
    CHECK_EQUAL(0, order.getCost());
    CHECK_EQUAL(0, order.getTime());
    CHECK_EQUAL(0, order.getBonuses());
    CHECK_EQUAL(0, order.getID());
    CHECK_EQUAL("", order.getAdress());
    CHECK_EQUAL(false, order.isDone());
    CHECK_EQUAL(false, order.isDelievered());
    CHECK_EQUAL(0, order.getEatList().size());
}

TEST(SetEatList_UpdatesListAndCalculations) {
    Eatable e1("Burger", 5.0, 10, time(0) + 7200);
    Eatable e2("Pizza", 7.5, 15, time(0) + 7200);
    vector<OrderPosition> list = {
        OrderPosition{e1, 1},
        OrderPosition{e2, 1}
    };
    Order order;
    order.addEat(OrderPosition{e1, 1});
    order.addEat(OrderPosition{e2, 1});


    CHECK_EQUAL(2, order.getEatList().size());
    CHECK_EQUAL(12.5, order.getCost());
    CHECK_EQUAL(25, order.getTime()); 
    CHECK_EQUAL(6, order.getBonuses());
}

TEST(SetAdress_UpdatesValue) {
    Order order;
    order.setAdress("Main Street 42");
    CHECK_EQUAL("Main Street 42", order.getAdress());
}

TEST(SetIsDone_UpdatesFlag) {
    Order order;
    order.setIsDone(true);
    CHECK_EQUAL(true, order.isDone());
}

TEST(SetIsDelievered_UpdatesFlag) {
    Order order;
    order.setIsDelievered(true);
    CHECK_EQUAL(true, order.isDelievered());
}

TEST(SetID_UpdatesValue) {
    Order order;
    order.setID(123);
    CHECK_EQUAL(123, order.getID());
}

}

SUITE(OrderPositionTests) {

TEST(DefaultConstructor_InitializesFields) {
    OrderPosition pos;
    CHECK_EQUAL("", pos.getEatable().getName());
    CHECK_EQUAL(0, pos.getAmount());
    CHECK_EQUAL(false, pos.isDone());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Eatable e("Burger", 5.0, 10, time(0) + 7200);
    OrderPosition pos(e, 2);
    CHECK_EQUAL("Burger", pos.getEatable().getName());
    CHECK_EQUAL(2, pos.getAmount());
    CHECK_EQUAL(false, pos.isDone());
}

TEST(SetEatable_UpdatesValue) {
    Eatable e1("Soup", 3.0, 5, time(0) + 7200);
    Eatable e2("Pizza", 7.5, 15, time(0) + 7200);
    OrderPosition pos(e1, 1);
    pos.setEatable(e2);
    CHECK_EQUAL("Pizza", pos.getEatable().getName());
}

TEST(SetAmount_UpdatesValue) {
    Eatable e("Salad", 4.0, 7, time(0) + 7200);
    OrderPosition pos(e, 1);
    pos.setAmount(5);
    CHECK_EQUAL(5, pos.getAmount());
}

TEST(SetDone_UpdatesFlag) {
    Eatable e("Steak", 12.0, 20, time(0) + 7200);
    OrderPosition pos(e, 1);
    pos.setDone(true);
    CHECK_EQUAL(true, pos.isDone());
}

}

SUITE(OvenTests) {

TEST(Constructor_SetsAllFieldsCorrectly) {
    Oven oven("Electrolux", true, 250, true);
    Oven o;
    CHECK_EQUAL("Electrolux", oven.getName());
    CHECK_EQUAL(true, oven.getIsElectric());
    CHECK_EQUAL(true, oven.getIsAvailable());
    CHECK_EQUAL(250, oven.getMaxTemperature());
}

TEST(GetMaxTemperature_ReturnsCorrectValue) {
    Oven oven("Bosch", true, 300, false);
    CHECK_EQUAL(300, oven.getMaxTemperature());
}

TEST(SetMaxTemperature_UpdatesValue) {
    Oven oven("Samsung", true, 200, true);
    oven.setMaxTemperature(280);
    CHECK_EQUAL(280, oven.getMaxTemperature());
}

}

SUITE(PaymentTests) {

TEST(DefaultConstructor_InitializesFields) {
    Payment p;
    CHECK_EQUAL(0.0, p.getAmount());
    CHECK_EQUAL("unknown", p.getMethod());
    CHECK_EQUAL("BYN", p.getCurrency());
    CHECK_EQUAL(false, p.isConfirmed());

    time_t now = time(nullptr);
    CHECK(p.getTime() <= now); // время не позже текущего
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Payment p(25.5, "card", "USD");
    CHECK_EQUAL(25.5, p.getAmount());
    CHECK_EQUAL("card", p.getMethod());
    CHECK_EQUAL("USD", p.getCurrency());
    CHECK_EQUAL(false, p.isConfirmed());

    time_t now = time(nullptr);
    CHECK(p.getTime() <= now);
}

TEST(SetAmount_UpdatesValue) {
    Payment p;
    p.setAmount(99.99);
    CHECK_EQUAL(99.99, p.getAmount());
}

TEST(SetMethod_UpdatesValue) {
    Payment p;
    p.setMethod("cash");
    CHECK_EQUAL("cash", p.getMethod());
}

TEST(SetCurrency_UpdatesValue) {
    Payment p;
    p.setCurrency("EUR");
    CHECK_EQUAL("EUR", p.getCurrency());
}

TEST(Confirm_SetsConfirmedTrue) {
    Payment p;
    p.confirm();
    CHECK_EQUAL(true, p.isConfirmed());
}

}

SUITE(PlaceTests) {

TEST(DefaultConstructor_InitializesAreaToZero) {
    Place p;
    CHECK_EQUAL(0, p.getArea());
}

TEST(ParameterizedConstructor_SetsAreaCorrectly) {
    Place p(120);
    CHECK_EQUAL(120, p.getArea());
}

TEST(CopyConstructor_CopiesArea) {
    Place original(75);
    Place copy(original);
    CHECK_EQUAL(75, copy.getArea());
}

TEST(SetArea_UpdatesValue) {
    Place p;
    p.setArea(200);
    CHECK_EQUAL(200, p.getArea());
}

}

SUITE(PlaceRequirementTests) {

TEST(DefaultConstructor_InitializesFields) {
    PlaceRequirement req;
    CHECK_EQUAL(0, req.getMinArea());
    CHECK_EQUAL(false, req.getRequiresElectricity());
    CHECK_EQUAL(false, req.getMustBeAccessible());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    PlaceRequirement req(100, true, true);
    CHECK_EQUAL(100, req.getMinArea());
    CHECK_EQUAL(true, req.getRequiresElectricity());
    CHECK_EQUAL(true, req.getMustBeAccessible());
}

TEST(SetMinArea_UpdatesValue) {
    PlaceRequirement req;
    req.setMinArea(150);
    CHECK_EQUAL(150, req.getMinArea());
}

TEST(SetRequiresElectricity_UpdatesValue) {
    PlaceRequirement req;
    req.setRequiresElectricity(true);
    CHECK_EQUAL(true, req.getRequiresElectricity());
}

TEST(SetMustBeAccessible_UpdatesValue) {
    PlaceRequirement req;
    req.setMustBeAccessible(true);
    CHECK_EQUAL(true, req.getMustBeAccessible());
}

TEST(IsSatisfiedBy_ReturnsTrueIfAreaIsEnough) {
    PlaceRequirement req(80, true, true);
    CHECK(req.isSatisfiedBy(100, false, false)); 
}

TEST(IsSatisfiedBy_ReturnsFalseIfAreaIsTooSmall) {
    PlaceRequirement req(80, true, true);
    CHECK(!req.isSatisfiedBy(50, true, true));
}

TEST(IsSatisfiedBy_BorderCaseAreaEqualToMin) {
    PlaceRequirement req(80, false, false);
    CHECK(req.isSatisfiedBy(80, false, false));
}

}

SUITE(ProductTests) {

TEST(DefaultConstructor_InitializesFields) {
    Product p;
    CHECK_EQUAL("", p.getName());
    CHECK_EQUAL(0, p.getCalories());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Product p("Tomato", 20);
    CHECK_EQUAL("Tomato", p.getName());
    CHECK_EQUAL(20, p.getCalories());
}

TEST(CopyConstructor_CopiesNameAndCalories) {
    Product original("Cheese", 100);
    Product copy(original);
    CHECK_EQUAL("Cheese", copy.getName());
    CHECK_EQUAL(100, copy.getCalories());
}

TEST(SetName_UpdatesValue) {
    Product p;
    p.setName("Meat");
    CHECK_EQUAL("Meat", p.getName());
}

TEST(SetCalories_UpdatesValue) {
    Product p;
    p.setCalories(150);
    CHECK_EQUAL(150, p.getCalories());
}

TEST(EqualityOperator_ReturnsTrueForIdenticalProducts) {
    Product p1("Salt", 0);
    Product p2("Salt", 0);
    CHECK(p1 == p2);
}

TEST(EqualityOperator_ReturnsFalseForDifferentProducts) {
    Product p1("Salt", 0);
    Product p2("Sugar", 0);
    CHECK(!(p1 == p2));
}

}


SUITE(PushNotificationTests) {

TEST(DefaultConstructor_InitializesFields) {
    PushNotification pn;
    CHECK_EQUAL("", pn.getWords());
    CHECK_EQUAL(0, pn.getBonuses());
    CHECK_EQUAL(0, pn.getPromo());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    PushNotification pn("Get 10% off!", 5, 1234);
    CHECK_EQUAL("Get 10% off!", pn.getWords());
    CHECK_EQUAL(5, pn.getBonuses());
    CHECK_EQUAL(1234, pn.getPromo());
}

TEST(SetWords_UpdatesValue) {
    PushNotification pn;
    pn.setWords("Limited offer!");
    CHECK_EQUAL("Limited offer!", pn.getWords());
}

TEST(SetBonuses_UpdatesValue) {
    PushNotification pn;
    pn.setBonuses(10);
    CHECK_EQUAL(10, pn.getBonuses());
}

TEST(SetPromo_UpdatesValue) {
    PushNotification pn;
    pn.setPromo(2025);
    CHECK_EQUAL(2025, pn.getPromo());
}

}

SUITE(PushServiceTests) {

TEST(DefaultConstructor_SetsLanguageToRu) {
    PushService service;
    CHECK_EQUAL("ru", service.getLanguage());
}

TEST(ParameterizedConstructor_SetsLanguageCorrectly) {
    PushService service("en");
    CHECK_EQUAL("en", service.getLanguage());
}

TEST(SetLanguage_UpdatesValue) {
    PushService service;
    service.setLanguage("de");
    CHECK_EQUAL("de", service.getLanguage());
}

TEST(CreatePushNotification_ReturnsCorrectNotification) {
    PushService service;
    PushNotification pn = service.createPushNotification("Welcome!", 10, 2025);
    CHECK_EQUAL("Welcome!", pn.getWords());
    CHECK_EQUAL(10, pn.getBonuses());
    CHECK_EQUAL(2025, pn.getPromo());
}
}


SUITE(RatingTests) {

TEST(DefaultConstructor_InitializesFields) {
    Rating r;
    CHECK_EQUAL(0, r.getStars());
    CHECK_EQUAL("", r.getWords());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Rating r(4, "Great service!");
    CHECK_EQUAL(4, r.getStars());
    CHECK_EQUAL("Great service!", r.getWords());
}

TEST(SetStars_UpdatesValue) {
    Rating r;
    r.setStars(5);
    CHECK_EQUAL(5, r.getStars());
}

TEST(SetWords_UpdatesValue) {
    Rating r;
    r.setWords("Excellent food");
    CHECK_EQUAL("Excellent food", r.getWords());
}

TEST(EqualityOperator_ReturnsTrueForEqualRatings) {
    Rating r1(5, "Perfect");
    Rating r2(5, "Perfect");
    CHECK(r1 == r2);
}

TEST(EqualityOperator_ReturnsFalseForDifferentRatings) {
    Rating r1(5, "Perfect");
    Rating r2(4, "Perfect");
    Rating r3(5, "Good");
    CHECK(!(r1 == r2));
    CHECK(!(r1 == r3));
}

}

SUITE(RestaurantTests) {

TEST(DefaultConstructor_InitializesEmptyFields) {
    Restaurant r;
    CHECK_EQUAL(0, r.getCooks().size());
    CHECK_EQUAL(0, r.getCouriers().size());
    CHECK_EQUAL(0, r.getOrders().size());
    CHECK_EQUAL(0, r.getMenu().getItems().size());
    CHECK_EQUAL(0, r.getRatings().size());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Adress a("Smolevichi", "Lenin", 42);
    Manager m("Ivan", 5000);
    DinningRoom dr;
    Warehouse w;
    Kitchen k(100, 3, true, true);

    Restaurant r(a, m, dr, w, k);
    CHECK_EQUAL("Lenin", r.getAdress().getStreet());
    CHECK_EQUAL(42, r.getAdress().getHouse());
    CHECK_EQUAL("Ivan", r.getManager().getName());
    CHECK_EQUAL(0, r.getDinningRoom().getTablesCount());
    CHECK_EQUAL(100, r.getKitchen().getArea());
}

TEST(Setters_UpdateFieldsCorrectly) {
    Restaurant r;
    Adress a("Smolevichi", "Lenin", 10);
    Manager m("Anna", 6000);
    DinningRoom dr;
    Warehouse w;
    Kitchen k(80, 2, false, true);

    r.setAdress(a);
    r.setManager(m);
    r.setDinningRoom(dr);
    r.setWarehouse(w);
    r.setKitchen(k);

    CHECK_EQUAL("Lenin", r.getAdress().getStreet());
    CHECK_EQUAL("Smolevichi", r.getAdress().getCity());
    CHECK_EQUAL("Anna", r.getManager().getName());
    CHECK_EQUAL(0, r.getDinningRoom().getTablesCount());
    CHECK_EQUAL(80, r.getKitchen().getArea());
}

TEST(SetCooksAndFindCook_WorksCorrectly) {
    Restaurant r;
    Cook c1("Olga", 30, "Grill");
    Cook c2("Max", 25, "Oven");

    r.addCook(c1);
    CHECK(r.findCook(c1));
    CHECK(!r.findCook(c2));
}

TEST(SetCouriersAndFindCourier_WorksCorrectly) {
    Restaurant r;
    Courier cr1("Alex", 22, "+375291234567");
    Courier cr2("Nina", 28, "+375291111111");

    r.addCourier(cr1);
    CHECK(r.findCourier(cr1));
    CHECK(!r.findCourier(cr2));
}

TEST(SetOrdersAndMenu_WorksCorrectly) {
    Restaurant r;
    Order o;
    o.setID(101);
    Menu m;
    Eatable e("Burger", 5.0, 10, time(0) + 7200);
    m.addItem(e);

    r.addOrder(o);
    r.setMenu(m);

    CHECK_EQUAL(1, r.getOrders().size());
    CHECK_EQUAL(101, r.getOrders()[0].getID());
    CHECK_EQUAL(1, r.getMenu().getItems().size());
    CHECK_EQUAL("Burger", r.getMenu().getItems()[0].getName());
}

}


SUITE(ScooterTests) {

TEST(DefaultConstructor_InitializesFields) {
    Scooter s;
    CHECK_EQUAL("", s.getModel());
    CHECK_EQUAL(0, s.getCapacity());
    CHECK_EQUAL(100.0, s.getBatteryLevel());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Scooter s("Xiaomi M365", 1, 85.5);
    CHECK_EQUAL("Xiaomi M365", s.getModel());
    CHECK_EQUAL(1, s.getCapacity());
    CHECK_EQUAL(85.5, s.getBatteryLevel());
}

TEST(SetBatteryLevel_UpdatesValue) {
    Scooter s;
    s.setBatteryLevel(42.0);
    CHECK_EQUAL(42.0, s.getBatteryLevel());
}
TEST(ShortDistance){
    Scooter s;
    s.setBatteryLevel(42.0);
    DeliveryRoute dr;
    dr.setTotalDistance(200);
    s.shortDistance(dr);
    CHECK_EQUAL(100, dr.getTotalDistance());
}
}

SUITE(StoveTests) {

TEST(Constructor_SetsAllFieldsCorrectly) {
    Stove stove("Gorenje", true, 4, true);
    Stove s;
    CHECK_EQUAL("Gorenje", stove.getName());
    CHECK_EQUAL(true, stove.getIsElectric());
    CHECK_EQUAL(true, stove.getIsAvailable());
    CHECK_EQUAL(4, stove.getBurnerCount());
}

TEST(GetBurnerCount_ReturnsCorrectValue) {
    Stove stove("Bosch", false, 2, false);
    CHECK_EQUAL(2, stove.getBurnerCount());
}

TEST(SetBurnerCount_UpdatesValue) {
    Stove stove("Electrolux", true, 3, true);
    stove.setBurnerCount(5);
    CHECK_EQUAL(5, stove.getBurnerCount());
}

}

SUITE(SupplierTests) {

TEST(AddProduct_AddsNewItemToWarehouse) {
    Supplier a;
    Supplier s("Ivan", 1000);
    Warehouse w;
    Product p("Tomato", 20);
    FoodPosition f(p, 5);

    s.addProduct(f, w);
    CHECK_EQUAL(1, w.getStored().size());
    CHECK_EQUAL(5, w.getStored()[0].getAmount());
}

TEST(AddProduct_UpdatesExistingItemAmount) {
    Supplier s("Ivan", 1000);
    Warehouse w;
    Product p("Tomato", 20);
    FoodPosition f1(p, 5);
    FoodPosition f2(p, 3);

    s.addProduct(f1, w);
    s.addProduct(f2, w);
    CHECK_EQUAL(1, w.getStored().size());
    CHECK_EQUAL(8, w.getStored()[0].getAmount());
}

}

SUITE(SupportAgentTests) {

TEST(DefaultConstructor_InitializesAsUser) {
    SupportAgent agent;
    CHECK_EQUAL("", agent.getName());
    CHECK_EQUAL(0, agent.getAge());
    CHECK_EQUAL("", agent.getEmail());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    SupportAgent agent("Alice", 30, "alice@example.com");
    CHECK_EQUAL("Alice", agent.getName());
    CHECK_EQUAL(30, agent.getAge());
    CHECK_EQUAL("alice@example.com", agent.getEmail());
}

TEST(BanUser_SetsUserAsBanned) {
    SupportAgent agent;
    User user("Bob", 25, "bob@example.com", false);
    CHECK_EQUAL(false, user.getBanned());

    agent.banUser(user);
    CHECK_EQUAL(true, user.getBanned());
}

TEST(DeleteRating_RemovesCorrectRating) {
    SupportAgent agent;
    Restaurant r;
    Rating r1(5, "Excellent");
    Rating r2(3, "Okay");
    Rating r3(1, "Terrible");
    Customer c;
    c.leaveRating(r, r1);
    c.leaveRating(r, r2);
    c.leaveRating(r, r3);
    agent.deleteRating(r2, r);

    CHECK_EQUAL(2, r.getRatings().size());

    CHECK_EQUAL(5, r.getRatings()[0].getStars());
    CHECK_EQUAL("Excellent", r.getRatings()[0].getWords());

    CHECK_EQUAL(1, r.getRatings()[1].getStars());
    CHECK_EQUAL("Terrible", r.getRatings()[1].getWords());
}

TEST(DeleteRating_DoesNothingIfNotFound) {
    SupportAgent agent;
    Restaurant r;
    Rating r1(5, "Excellent");
    Rating r2(3, "Okay");
    Customer c;
    c.leaveRating(r, r1);
    agent.deleteRating(r2, r);

    CHECK_EQUAL(1, r.getRatings().size());
    CHECK_EQUAL(5, r.getRatings()[0].getStars());
    CHECK_EQUAL("Excellent", r.getRatings()[0].getWords());
}

}

SUITE(UserTests) {

TEST(DefaultConstructor_InitializesFields) {
    User u;
    CHECK_EQUAL("", u.getName());
    CHECK_EQUAL(0, u.getAge());
    CHECK_EQUAL("", u.getEmail());
    CHECK_EQUAL(false, u.getBanned());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    User u("Ivan", 35, "ivan@example.com", false);
    CHECK_EQUAL("Ivan", u.getName());
    CHECK_EQUAL(35, u.getAge());
    CHECK_EQUAL("ivan@example.com", u.getEmail());
    CHECK_EQUAL(false, u.getBanned());
}

TEST(SetName_UpdatesValue) {
    User u;
    u.setName("Anna");
    CHECK_EQUAL("Anna", u.getName());
}

TEST(SetAge_UpdatesValue) {
    User u;
    u.setAge(28);
    CHECK_EQUAL(28, u.getAge());
}

TEST(SetEmail_UpdatesValue) {
    User u;
    u.setEmail("anna@example.com");
    CHECK_EQUAL("anna@example.com", u.getEmail());
}

TEST(SetBanned_UpdatesFlag) {
    User u;
    u.setBanned(true);
    CHECK_EQUAL(true, u.getBanned());
}

}

SUITE(VehicleTests) {

TEST(DefaultConstructor_InitializesFields) {
    Vehicle v;
    CHECK_EQUAL("", v.getModel());
    CHECK_EQUAL(0, v.getCapacity());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Vehicle v("Toyota", 4);
    CHECK_EQUAL("Toyota", v.getModel());
    CHECK_EQUAL(4, v.getCapacity());
}

TEST(SetModel_UpdatesValue) {
    Vehicle v;
    v.setModel("Honda");
    CHECK_EQUAL("Honda", v.getModel());
}

TEST(SetCapacity_UpdatesValue) {
    Vehicle v;
    v.setCapacity(2);
    CHECK_EQUAL(2, v.getCapacity());
}

TEST(SetCapacity_NegativeValueSetsZero) {
    Vehicle v;
    v.setCapacity(-5);
    CHECK_EQUAL(0, v.getCapacity());
}

TEST(EqualityOperator_ReturnsTrueForEqualVehicles) {
    Vehicle v1("Tesla", 5);
    Vehicle v2("Tesla", 5);
    CHECK(v1 == v2);
}

TEST(EqualityOperator_ReturnsFalseForDifferentVehicles) {
    Vehicle v1("Tesla", 5);
    Vehicle v2("Tesla", 4);
    Vehicle v3("BMW", 5);
    CHECK(!(v1 == v2));
    CHECK(!(v1 == v3));
}

}

SUITE(VipCustomerTests) {

TEST(DefaultConstructor_InitializesFields) {
    Vip_Customer vip;
    CHECK_EQUAL(0, vip.getVipDays());
    CHECK_EQUAL(0, vip.getVipCategory());
    CHECK_EQUAL("", vip.getName());
    CHECK_EQUAL(0, vip.getAge());
    CHECK_EQUAL("", vip.getEmail());
    CHECK_EQUAL(0, vip.getCash());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Order o;
    Vip_Customer vip("Ivan", 40, "ivan@example.com", 500, 30, 2, o);
    CHECK_EQUAL("Ivan", vip.getName());
    CHECK_EQUAL(40, vip.getAge());
    CHECK_EQUAL("ivan@example.com", vip.getEmail());
    CHECK_EQUAL(500, vip.getCash());
    CHECK_EQUAL(30, vip.getVipDays());
    CHECK_EQUAL(2, vip.getVipCategory());
}

TEST(SetVipDays_UpdatesValue) {
    Vip_Customer vip;
    vip.setVipDays(15);
    CHECK_EQUAL(15, vip.getVipDays());
}

TEST(SetVipCategory_UpdatesValue) {
    Vip_Customer vip;
    vip.setVipCategory(3);
    CHECK_EQUAL(3, vip.getVipCategory());
}

TEST(FastDelivery_PrintsCorrectMessage) {
    Vip_Customer vip;
    Order order;
    order.setID(101);

    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());

    vip.fastDelivery(order);

    cout.rdbuf(old);
    CHECK_EQUAL("VIP клиент запросил быструю доставку заказа #101\n", buffer.str());
}

}

SUITE(WarehouseTests) {

TEST(DefaultConstructor_InitializesFields) {
    Warehouse w;
    CHECK_EQUAL(0, w.getCapacity());
    CHECK_EQUAL(0, w.getArea());
    CHECK_EQUAL(0, w.getStored().size());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Product p("Tomato", 20);
    FoodPosition f(p, 5);
    WarehouseRequirement req;
    Warehouse w(100, 50, req, {f});

    CHECK_EQUAL(100, w.getCapacity());
    CHECK_EQUAL(50, w.getArea());
    CHECK_EQUAL(1, w.getStored().size());
    CHECK_EQUAL("Tomato", w.getStored()[0].getProduct().getName());
    CHECK_EQUAL(5, w.getStored()[0].getAmount());
    CHECK_EQUAL(0, w.getRequirement().getMinCapacity());
    CHECK_EQUAL(false, w.getRequirement().getRequiresCooling());
}

TEST(SetCapacity_UpdatesValue) {
    Warehouse w;
    w.setCapacity(200);
    CHECK_EQUAL(200, w.getCapacity());
}

TEST(SetRequirement_UpdatesValue) {
    Warehouse w;
    WarehouseRequirement req;
    w.setRequirement(req);
    CHECK_EQUAL(0, w.getRequirement().getMinArea());
    CHECK_EQUAL(false, w.getRequirement().getRequiresCooling());
}

TEST(SetStored_AddsNewProduct) {
    Warehouse w;
    Product p("Apple", 50);
    FoodPosition f(p, 10);
    w.setStored(f);

    CHECK_EQUAL(1, w.getStored().size());
    CHECK_EQUAL("Apple", w.getStored()[0].getProduct().getName());
    CHECK_EQUAL(10, w.getStored()[0].getAmount());
}

TEST(SetStored_UpdatesExistingProductAmount) {
    Warehouse w;
    Product p("Milk", 100);
    FoodPosition f1(p, 5);
    FoodPosition f2(p, 3);
    w.setStored(f1);
    w.setStored(f2);

    CHECK_EQUAL(1, w.getStored().size());
    CHECK_EQUAL(8, w.getStored()[0].getAmount());
}

TEST(IsFull_ReturnsTrueIfCapacityExceeded) {
    Product p("Water", 0);
    FoodPosition f(p, 10);
    Warehouse w(10, 20, WarehouseRequirement(), {});
    w.setStored(f);

    CHECK(w.isFull());
}

TEST(IsFull_ReturnsFalseIfCapacityNotReached) {
    Product p("Juice", 0);
    FoodPosition f(p, 5);
    Warehouse w(10, 20, WarehouseRequirement(), {});
    w.setStored(f);

    CHECK(!w.isFull());
}

}

SUITE(WarehouseRequirementTests) {

TEST(DefaultConstructor_InitializesFields) {
    WarehouseRequirement req;
    CHECK_EQUAL(0, req.getMinArea());
    CHECK_EQUAL(false, req.getRequiresElectricity());
    CHECK_EQUAL(false, req.getMustBeAccessible());
    CHECK_EQUAL(0.0, req.getMinCapacity());
    CHECK_EQUAL(false, req.getRequiresCooling());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    WarehouseRequirement req(100, true, true, 50, true);
    CHECK_EQUAL(100, req.getMinArea());
    CHECK_EQUAL(true, req.getRequiresElectricity());
    CHECK_EQUAL(true, req.getMustBeAccessible());
    CHECK_EQUAL(50, req.getMinCapacity());
    CHECK_EQUAL(true, req.getRequiresCooling());
}

TEST(SetMinCapacity_UpdatesValue) {
    WarehouseRequirement req;
    req.setMinCapacity(75);
    CHECK_EQUAL(75, req.getMinCapacity());
}

TEST(SetRequiresCooling_UpdatesValue) {
    WarehouseRequirement req;
    req.setRequiresCooling(true);
    CHECK_EQUAL(true, req.getRequiresCooling());
}

TEST(IsWarehouseSatisfiedBy_ReturnsTrueIfAllConditionsMet) {
    WarehouseRequirement req(100, true, true, 50.0, true);
    CHECK(req.isWarehouseSatisfiedBy(120, true, true, 60.0, true));
}

TEST(IsWarehouseSatisfiedBy_ReturnsFalseIfAreaTooSmall) {
    WarehouseRequirement req(100, true, true, 50.0, true);
    CHECK(!req.isWarehouseSatisfiedBy(90, true, true, 60.0, true));
}

TEST(IsWarehouseSatisfiedBy_ReturnsFalseIfVolumeTooSmall) {
    WarehouseRequirement req(100, true, true, 50.0, true);
    CHECK(!req.isWarehouseSatisfiedBy(120, true, true, 40.0, true));
}

TEST(IsWarehouseSatisfiedBy_ReturnsFalseIfCoolingRequiredButMissing) {
    WarehouseRequirement req(100, true, true, 50.0, true);
    CHECK(!req.isWarehouseSatisfiedBy(120, true, true, 60.0, false));
}

TEST(IsWarehouseSatisfiedBy_ReturnsTrueIfCoolingNotRequired) {
    WarehouseRequirement req(100, true, true, 50.0, false);
    CHECK(req.isWarehouseSatisfiedBy(120, true, true, 60.0, false));
}

}

SUITE(WorkerTests) {

TEST(DefaultConstructor_InitializesFields) {
    Worker w;
    CHECK_EQUAL("", w.getName());
    CHECK_EQUAL(0, w.getSalary());
}

TEST(ParameterizedConstructor_SetsFieldsCorrectly) {
    Worker w("Ivan", 1200);
    CHECK_EQUAL("Ivan", w.getName());
    CHECK_EQUAL(1200, w.getSalary());
}

TEST(SetName_UpdatesValue) {
    Worker w;
    w.setName("Anna");
    CHECK_EQUAL("Anna", w.getName());
}

TEST(SetSalary_UpdatesValue) {
    Worker w;
    w.setSalary(1500);
    CHECK_EQUAL(1500, w.getSalary());
}

TEST(EqualityOperator_ReturnsTrueForSameNameAndSalary) {
    Worker w1("Max", 1000);
    Worker w2("Max", 1000);
    CHECK_EQUAL(w1.getName(), w2.getName());
    CHECK_EQUAL(w1.getSalary(), w2.getSalary());
    CHECK(w1 == w2);
}

TEST(EqualityOperator_ReturnsFalseForDifferentFields) {
    Worker w1("Max", 1000);
    Worker w2("Max", 900);
    Worker w3("Leo", 1000);
    CHECK(!(w1 == w2));
    CHECK(!(w1 == w3));
}

}







int main() {
    return UnitTest::RunAllTests();
}
