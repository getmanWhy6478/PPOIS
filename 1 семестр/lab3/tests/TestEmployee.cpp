#include "UnitTest++/UnitTest++.h"
#include "../include/Employee.h"
#include "../include/Curator.h"
#include "../include/Gallery.h"

SUITE(EmployeeTests) {
    TEST(EmployeeConstructor) {
        Gallery* gallery = new Gallery("MoMA", "11 W 53rd St", "New York", "USA");
        Curator* curator = new Curator("Alice", "Brown", "EMP001", gallery);
        
        CHECK_EQUAL("Alice", curator->getFirstName());
        CHECK_EQUAL("Brown", curator->getLastName());
        CHECK_EQUAL("EMP001", curator->getEmployeeId());
        CHECK(curator->getGallery() == gallery);
        CHECK_EQUAL("Curator", curator->getPosition());
        
        delete curator;
        delete gallery;
    }
    
    TEST(EmployeeSetters) {
        Gallery* gallery = new Gallery("Tate", "Bankside", "London", "UK");
        Curator* employee = new Curator("Charlie", "Wilson", "EMP002", gallery);
        
        employee->setPhone("+44-20-7887-8888");
        employee->setHireYear(2020);
        employee->setSalary(50000.0);
        
        CHECK_EQUAL("+44-20-7887-8888", employee->getPhone());
        CHECK_EQUAL(2020, employee->getHireYear());
        CHECK_CLOSE(50000.0, employee->getSalary(), 0.01);
        
        delete employee;
        delete gallery;
    }
}

