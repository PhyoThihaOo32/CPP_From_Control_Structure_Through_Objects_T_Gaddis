/*
This program write data to the file using user controlled loop.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    // create ofstream object
    ofstream outputFile;

    // variable for the program
    int number_days;
    double sales,
        total_sales, // accumulator
        average_sales;

    // open the file name sales.txt
    outputFile.open("Sales.txt");

    // get the number of days
    cout << "For how many days do you have sales? ";
    cin >> number_days;

    // get the sales amount and calculat average
    for (int count = 1; count <= number_days; count++)
    {
        cout << "Enter the sale amount for day " << count << " :";
        cin >> sales;

        // add up the sales
        total_sales += sales;

        // write the sales to the file
        outputFile << "For day " << count << " sales: " << sales << endl;
    }

    // calculate average sales
    average_sales = total_sales / number_days;

    outputFile << "Total sales: " << total_sales << endl;
    outputFile << "Average sales: " << average_sales << endl;

    // close the file
    outputFile.close();

    return 0;
}