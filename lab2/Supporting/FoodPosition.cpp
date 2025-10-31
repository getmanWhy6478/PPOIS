#pragma once
#include "FoodPosition.h"
#include <stdexcept>

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

    // Геттер для количества
int FoodPosition::getAmount() const {
        return amount;
    }

    // Сеттер для количества с проверкой
void FoodPosition::setAmount(int amount) {
        if (amount < 0) {
            throw std::invalid_argument("Количество не может быть отрицательным");
        }
        this->amount = amount;
    }

