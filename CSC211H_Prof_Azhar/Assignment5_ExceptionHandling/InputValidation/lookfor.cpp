/*
Program: look-for
Unit Test (main function purpose):
The main() function is used for unit testing to verify:

1. Correct number of command-line arguments (argc validation)
2. Proper conversion from string to integer using atoi()
3. Range validation of coordinates [0, 9]
4. Correct instantiation of Point objects
5. Proper storage and echoing of validated inputs
6. Added exception handling for input validation.

If validation fails, the program prints an error message and exits.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include "point.h"

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> coordinates; // to store int(from cml args)
    int temp;                // for input validation(range check)
    int numPoints = 3;
    point points[3]; // array of points

    try{

    // added exception handling for input validation
    // - throw 1 - if the number of input is less than 1
    // - throw 2 - if the input if not a digit
    // - throw 3 - if the input is not in range [0,9]
    // check if the user has entered 2 command-line arguments
    if (argc < 2)
    {
        throw 1;
        // cout << "You didn't enter the co-ordinates. "
        //      << "Please enter three (x,y) coordinates in range [0,9] (inclusive)." << endl
        //      << "Program Terminated." << endl;
        // exit(EXIT_FAILURE);
    }

    // check the input numbers(not char)
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            if (!isdigit(argv[i][j])) // check each elements
            {
                throw 2;
                // cout << "Invalid Input.\n"
                //      << argv[i][j] << " is not a number."
                //      << "Program Terminated." << endl;
                // exit(EXIT_FAILURE);
            }
        }
    }

    // Check that the arguments are within the range [0, 9],
    // and convert into integers
    for (int i = 1; i < 7; i++)
    {
        temp = atoi(*(argv + i)); // convert c-string into integer
        if (temp < 0 || temp > 9)
        {
            throw 3;
            // cout << "Please enter coordinates in range [0,9] (inclusive)." << endl
            //      << "Program Terminated." << endl;
            // exit(EXIT_FAILURE);
        }
        else
        {
            // store the valid inputs into vector of coordinates
            coordinates.push_back(temp);
        }
    }

     int pointIndex = 0; // index for point
    for (int i = 0, j = 1; i < coordinates.size(); i += 2, j += 2)
    {
        // set x and y values to three points objects
        int x = coordinates.at(i);
        int y = coordinates.at(j);
        points[pointIndex++].set(x, y);
    }

    // echo the values
    cout << "Hidden coins locations." << endl;
    for (int i = 0; i < numPoints; i++)
    {
        points[i].print();
    }

    }
    catch(int error){
        if(error == 1)cout << "Input is less than 2." << endl;
        else if(error == 2) cout << "Input is not a digit." << endl;
        else if(error == 3) cout << "Input is not in range." << endl;
    }

    return 0;
}