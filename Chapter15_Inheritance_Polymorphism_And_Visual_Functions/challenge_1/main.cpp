#include <iostream>
#include <vector>
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"

using namespace std;

int main()
{
    // Create objects
    ProductionWorker pw("Alice", 101, 20220101, 1, 25.5);
    ShiftSupervisor ss("Bob", 102, 20210101, 80000, 5000);
    TeamLeader tl("Charlie", 103, 20230101, 2, 30.0, 1000, 40, 35);

    // Polymorphism using base class pointers
    vector<Employee*> employees;

    employees.push_back(&pw);
    employees.push_back(&ss);
    employees.push_back(&tl);

    cout << "=== Employee Information ===" << endl;

    for (Employee* emp : employees)
    {
        cout << "------------------------" << endl;
        emp->printInfo();   // 🔥 dynamic binding
    }

    return 0;
}