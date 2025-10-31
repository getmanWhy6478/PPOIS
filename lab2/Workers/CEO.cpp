#include "CEO.h"

// Конструктор по умолчанию
CEO::CEO()
    : Worker(){}

// Конструктор с параметрами
CEO::CEO(const string& name, int salary, Restaurant* restaurant)
    : Worker(name, salary, restaurant) {}

// Назначение менеджера
void CEO::hireManager(Restaurant& restaurant, const Manager& manager) {
   restaurant.setManager(manager);
}

// Удаление менеджера
void CEO::fireManager(Restaurant& restaurant) {
    Manager emptyManager;
    restaurant.setManager(emptyManager);
}
