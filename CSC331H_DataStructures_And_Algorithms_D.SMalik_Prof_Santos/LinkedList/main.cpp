#include "unorderedLinkedList.h"
#include "orderedLinkedList.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    ifstream inputFile("cars.txt"); // create the file obj and open the text file to read car brands
    orderedLinkedList<string> carBrandList;
    string carBrands;

    // reading car brands from the file
    while (inputFile >> carBrands)
    {
        // inserting into the list
        carBrandList.insert(carBrands);
    }

    // print the list
    cout << "\n========================================" << endl;
    cout << "          ORDERED CAR BRAND LIST" << endl;
    cout << "========================================" << endl;

    cout << "Car Brands: ";
    carBrandList.print();
    cout << "Count: " << carBrandList.length() << endl;
    cout << endl;

    // delete one the car brand from the list
    cout << "\n========================================" << endl;
    cout << "             DELETE A BRAND" << endl;
    cout << "========================================" << endl;

    cout << "Deleting: Kia" << endl;
    carBrandList.deleteNode("Kia");

    // print the list
    cout << "\n========================================" << endl;
    cout << "        LIST AFTER DELETING KIA" << endl;
    cout << "========================================" << endl;

    cout << "Car Brands: ";
    carBrandList.print();
    cout << "Count: " << carBrandList.length() << endl;
    cout << endl;

    // signature
    cout << "\n========================================" << endl;
    cout << "              SUBMISSION" << endl;
    cout << "========================================" << endl;

    cout << "Submitted by: Phyo T. Oo" << endl;
    cout << "ID:           24492624" << endl;
    cout << "========================================" << endl;

    return 0;
}

/*
unorderedLinkedList<double> numbersList;
    linkedListIterator<double> ite;
    double input;
    ifstream inputFile("numbers.txt");
    double totalA = 0.0, totalB = 0.0;
    int count = 0; // to count the node list

    cout << fixed << setprecision(2);

    // inserting the numbers to the list from the file
    while (inputFile >> input)
    {
        numbersList.insertLast(input);
        count++;
    }

    // printing the list
    cout << "\n========================================" << endl;
    cout << "           ORIGINAL LIST" << endl;
    cout << "========================================" << endl;

    cout << "Values:      ";
    numbersList.print();

    cout << "\nTotal Nodes: " << count << endl;

    // iterate the list
    for (ite = numbersList.begin(); ite != numbersList.end(); ++ite)
    {
        // cout << *ite << " ";
        totalA += *ite;
    }

    // print total
    cout << "Total Value: " << totalA << endl;

    // delete the node with values 0.01
    while (numbersList.search(0.01))
    {
        numbersList.deleteNode(0.01);
        count--;
    }

    cout << "\n========================================" << endl;
    cout << "       AFTER DELETING 0.01 NODES" << endl;
    cout << "========================================" << endl;

    cout << "Values:      ";
    numbersList.print();

    cout << "\nTotal Nodes: " << count << endl;

    // calculating total again
    for (ite = numbersList.begin(); ite != numbersList.end(); ++ite)
    {
        totalB += *ite;
    }

    cout << "Total Value: " << totalB << endl;

    // diff in total
    cout << "\n========================================" << endl;
    cout << "              SUMMARY" << endl;
    cout << "========================================" << endl;

    cout << "Original Total:        " << totalA << endl;
    cout << "Total After Deletion:  " << totalB << endl;
    cout << "Difference:            " << totalA - totalB << endl;
    cout << "========================================" << endl;

*/