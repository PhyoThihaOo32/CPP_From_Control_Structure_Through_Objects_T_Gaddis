// Specification file for the employee class

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee
{
private:
    string name;
    int idNumber;
    string department;
    string position; // job position
public:
    Employee(string, int, string, string);
    Employee(string, int); // employeeName and idNumber
    Employee();

    // accessor function
    string getName() const { return name; } // inline function
    int getIdNumber() const { return idNumber; }
    string getDepartment() const { return department; }
    string getPosition() const { return position; }

    // mutator function
    void setName(string s) { name = s; }
    void setIdNumber(int n) { idNumber = n; }
    void setDepartment(string dep) { department = dep; }
    void setPosition(string pos) { position = pos; }

    // display employee info
    void displayInfo() const;
};

#endif