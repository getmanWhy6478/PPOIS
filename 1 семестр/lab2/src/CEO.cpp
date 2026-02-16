#include "../include/CEO.h"
#include "../include/Errors.h"
// Конструктор по умолчанию
CEO::CEO()
    : Worker(){}

// Конструктор с параметрами
CEO::CEO(const string& name, int salary)
    : Worker(name, salary) {}

// Назначение менеджера
void CEO::hireManager(const Manager& manager, Restaurant restaurant) {
    if (restaurant.getManager() == *this) {
        restaurant.setManager(manager);
        return; 
    }
    throw UnempolymentError();
}

// Удаление менеджера
void CEO::fireManager(Restaurant restaurant) {
    if (restaurant.getManager() == *this) {
        Manager emptyManager;
        restaurant.setManager(emptyManager);
        return;     
    }
    throw UnempolymentError();
    
}
