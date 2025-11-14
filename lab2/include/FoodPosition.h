#pragma once
#include "Product.h"

class FoodPosition{
public:
    FoodPosition();
    FoodPosition(const Product& product, int amount);

    Product getProduct() const;
    void setProduct(const Product& product);
    
    int getAmount() const;
    void setAmount(int amount);
private:
    Product product;
    int amount;
friend class Warehouse;
};