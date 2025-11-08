#pragma once
#include <string>
using namespace std;
class Worker {
public:
    Worker();
    Worker(const string& name, int salary);

    int getSalary() const;
    void setSalary(int salary);

    string getName() const;
    void setName(const string& name);

    bool operator==(const Worker& other) const;

protected:
    string name;
    int salary;
};