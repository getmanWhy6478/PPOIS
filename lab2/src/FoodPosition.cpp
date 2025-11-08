
#include "../include/FoodPosition.h"
#include "Errors.h"

FoodPosition::FoodPosition() : product(), amount(0) {}

FoodPosition::FoodPosition(const Product& product, int amount) : product(product) {
        setAmount(amount);
    }

Product FoodPosition::getProduct() const {
        return product;
    }

void FoodPosition::setProduct(const Product& product) {
        this->product = product;
    }


int FoodPosition::getAmount() const {
        return amount;
    }


void FoodPosition::setAmount(int amount) {
        if (amount < 0) {
            throw InvalidNumberError();
        }
        this->amount = amount;
}

