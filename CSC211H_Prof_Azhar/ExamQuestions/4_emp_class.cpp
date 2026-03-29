/*
4) Write the header and implementation files for a class, and a simple program to test it, according to the following specifications:
(Sample solution)
a)	Your class has 3 member data: an integer pointer that will be used to create a dynamic variable to represent the number of employees,
    an integer pointer that will be used to create a dynamic array representing employees' ids,
    and a double pointer that will be used to create a dynamic array to represent the total
    number of hours worked by each employee from Monday through Friday.

b)	 Your class has the following member functions:

i)	 a constructor with an int parameter representing the number of employees; the constructor creates the dynamic variable and
     sets it to the int parameter, creates the two dynamic arrays and sets everything to zero.

ii)	 a function that reads in all the ids and the hours into the appropriate arrays.

iii) a function called print_info which, for each employee, does all of the
                following:

     It prints the employee’s id and the hours worked.
     If the employee’ s total hours are greater than or equal to 40, it prints
     “FULL TIME EMPLOYEE”, otherwise it prints “PART TIME EMPLOYEE”.

iv)	 a destructor.

*/

#ifndef EMP_H
#define EMP_H

#include <iostream>

using namespace std;

class Employee
{
private:
    int *num_emp;
    int *emp_id;
    double *hours;

public:
    Employee(int num);
    ~Employee();
    void readInfo();
    void printInfo();
};

#endif

Employee::Employee(int num)
{
    num_emp = new int; // create dynamic int
    *num_emp = num;

    emp_id = new int[num];
    hours = new double[num];

    for (int i = 0; i < num; i++)
    {
        *(emp_id + i) = 0;
        *(hours + i) = 0;
    }
}

void Employee::readInfo()
{
    for (int i = 0; i < *num_emp; i++)
    {
        cout << "Enter Employee_ID" << endl;
        cin >> emp_id[i];
        cout << "Enter Hours: " << endl;
        cin >> hours[i];
    }
}

void Employee::printInfo()
{
    for (int i = 0; i < *num_emp; i++)
    {
        cout << "ID: " << emp_id[i] << endl;
        cout << "Hours: " << hours[i] << endl;
        if (hours[i] >= 40)
        {
            cout << "Full Time." << endl;
        }
        else
        {
            cout << "Part Time." << endl;
        }
    }
}

Employee::~Employee()
{
    delete num_emp;
    delete[] emp_id;
    delete[] hours;
}

int main()
{

    Employee e1(5);

    e1.readInfo();
    e1.printInfo();

    return 0;
}