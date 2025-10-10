/*
This program ask user input and stores them in array and then writes datas from the array to a files.
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    const int ARRAY_SIZE = 5;
    string cityName_array[ARRAY_SIZE]; // creating an array of 10 elements
    string city_name;

    int count = 0;                        // counter variable
    ofstream outputFile("cityNames.txt"); // creating and open outputFile

    // ask user to enter 10 city names
    for (count = 0; count < ARRAY_SIZE; count++)
    {
        cout << "Enter the city names" << (count + 1) << " : ";
        getline(cin, city_name);

        // store it in array
        cityName_array[count] = city_name;

        // write in to the file
        outputFile << cityName_array[count] << endl;
    }

      // close the outputFile
    outputFile.close();

    // read the data from file
    ifstream inputFile("cityNames.txt");

    while (inputFile >> city_name)
    {
        cout << city_name << endl;
    }

    inputFile.close();

    return 0;
}