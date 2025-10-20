/*
The data type that are defined in the STL library are called containers - because they stored and organized data.
There are two types of containers - sequence and associative containers.
Sequence container organized data in a sequential fashion, similar to array.
Associative containers organized data with keys, which allow rapid, random access to elements stored in the container.


Defining a Vector

#include <vector>

vector<int> names;      defined (names) as a vector of int
vecotr<int> names(10);  defined names as a vector of 10 ints
vector<int> names(10,2);defined (names) as a vector of 10 ints - each elements is initialized to value of 2
vector<int> names(othernames);  othernames will be a copy of names

vector<int> names {1,2,3,4,5};
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{

    const int NUM_EMPLOYEES = 5;
    vector<int> hours(NUM_EMPLOYEES);
    vector<double> payrate(NUM_EMPLOYEES);
    vector<double> salary(NUM_EMPLOYEES);
    int index;

    // get the hours and payrate for each employee
    for (index = 0; index < NUM_EMPLOYEES; index++)
    {
        cout << "Enter the information for employee " << (index + 1) << endl;
        cout << "Enter the working hour: ";
        cin >> hours[index];
        cout << "Enter the pay rate: ";
        cin >> payrate[index];
    }

    // set the numeric output format
    cout << setprecision(2) << showpoint << fixed;

    // calculate and display the salary for each employee
    for (index = 0; index < NUM_EMPLOYEES; index++)
    {
        salary[index] = hours[index] * payrate[index];
        cout << "Salary for employee " << (index + 1) << " : " << salary[index] << endl;
    }
}