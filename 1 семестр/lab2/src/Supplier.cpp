#include "../include/Supplier.h"
#include "../include/Errors.h"
Supplier::Supplier()
    : Worker("", 0) {}

Supplier::Supplier(const string& name, int salary)
    : Worker(name, salary) {}
void Supplier::addProduct(FoodPosition food, Warehouse& warehouse){
    for (auto& i : warehouse.stored){
        if (i.getProduct() == food.getProduct()){
                i.setAmount(i.getAmount() + food.getAmount());
                return;
        }
    }
    warehouse.stored.push_back(food);
};