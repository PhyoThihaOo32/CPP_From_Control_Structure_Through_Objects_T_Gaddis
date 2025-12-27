/*
To dynamically allocate memory mean that a program, while running, ask the computer to set aside a chuck of unused
memory large enough to hold a vairabe of specific data type.
The computer fullfill the request and give the program the starting address of the chunk of memory.
The program can only access the newly allocated memory through its address, so a pointer is required to use those bytes.

[When memory cannot be dynamically allocated, C++ throws an exception and terminates the program.]
When program is finished using a dynamically allocated chunk of memory, it should release it for future use.
Failure to do so can cause a program to have a memory leak.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    double *ptr_sales = nullptr; // pointer for double
    double total_sales = 0,      // acummulater for total sales
        avg_sales = 0;
    int numDays;

    // get the number of days from the user
    cout << "Enter the number of days: ";
    cin >> numDays;

    // dynamically allocate an array large enough to hold the man days of sales amount
    ptr_sales = new double[numDays];

    // get the sales data for each days
    for (int i = 0; i < numDays; i++)
    {
        cout << "Enter the sale amount for day " << (i + 1) << " :";
        cin >> *(ptr_sales + i); // dereferencing is critical
    }

    // calculat total sales
    for (int i = 0; i < numDays; i++)
    {
        total_sales += *(ptr_sales + i);
    }

    // calculate the average sales
    avg_sales = total_sales / numDays;

    // display the result
    cout << setprecision(2) << showpoint << fixed;
    cout << "Total Sales: " << total_sales << endl;
    cout << "Average Sales: " << avg_sales << endl;

    // free dynamically allocated memory
    delete[] ptr_sales;

    // set the pointer back to null
    ptr_sales = nullptr;

    return 0;
}