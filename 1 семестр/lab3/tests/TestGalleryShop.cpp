#include "UnitTest++/UnitTest++.h"
#include "../include/GalleryShop.h"
#include "../include/Gallery.h"

SUITE(GalleryShopTests)
{
    TEST(ConstructorInitializesFields)
    {
        Gallery gallery("Louvre", "Rue de Rivoli", "Paris", "France");
        GalleryShop shop("SHOP-001", &gallery, "Main Shop");

        CHECK_EQUAL("SHOP-001", shop.getShopId());
        CHECK_EQUAL("Main Shop", shop.getShopName());
        CHECK_EQUAL(&gallery, shop.getGallery());

        CHECK_EQUAL(0.0, shop.getTotalRevenue());
        CHECK_EQUAL(0, shop.getTotalSales());
        CHECK_EQUAL(0, shop.getEmployeeCount());
    }

    TEST(SettersAndGettersWorkCorrectly)
    {
        Gallery gallery("Louvre", "Rue de Rivoli", "Paris", "France");
        GalleryShop shop("SHOP-002", &gallery, "Gift Shop");

        shop.setShopId("SHOP-NEW");
        shop.setShopName("Souvenir Shop");
        shop.setLocation("First Floor");
        shop.setTotalRevenue(5000.0);
        shop.setTotalSales(100);
        shop.setEmployeeCount(5);

        CHECK_EQUAL("SHOP-NEW", shop.getShopId());
        CHECK_EQUAL("Souvenir Shop", shop.getShopName());
        CHECK_EQUAL("First Floor", shop.getLocation());
        CHECK_CLOSE(5000.0, shop.getTotalRevenue(), 1e-6);
        CHECK_EQUAL(100, shop.getTotalSales());
        CHECK_EQUAL(5, shop.getEmployeeCount());
    }

    TEST(RevenueAndSalesOperations)
    {
        Gallery gallery("Louvre", "Rue de Rivoli", "Paris", "France");
        GalleryShop shop("SHOP-004", &gallery, "Merch Shop");

        shop.addRevenue(1000.0);
        shop.addRevenue(500.0);
        CHECK_CLOSE(1500.0, shop.getTotalRevenue(), 1e-6);

        shop.incrementSales();
        shop.incrementSales();
        shop.incrementSales();
        CHECK_EQUAL(3, shop.getTotalSales());
    }

    TEST(ChangeGalleryReference)
    {
        Gallery gallery2("Louvre2", "Rue de Rivoli2", "Paris2", "France2");

        GalleryShop shop("SHOP-005", &gallery2, "Gallery Shop");

        shop.setGallery(&gallery2);
        CHECK_EQUAL((&gallery2)->getAddress(), shop.getGallery()->getAddress());
    }
}
