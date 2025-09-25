/*
Program need some way of knowing when the end of the file has been reached so it will not try to read beyond it.
The >> operator not only read data from a file, but also returns a true or false value indicating
whether the data was successfully read or not.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    // create ifsteam object
    ifstream inputFile;

    // variable to store number
    int number;

    // string object to pass as argument to open member function
    string file_name;

    // ask the user to enter the file name
    cout << "Enter the name of the file that you want to open: ";
    cin >> file_name;

    // open file
    inputFile.open(file_name);

    // check the file is successfully open or not
    if (!inputFile.fail())
    {

        // read the file till the end
        while (inputFile >> number)
        {
            cout << number << endl;
        }
    }
    else
    {
        cout << "File does not exist/ Error opening the file." << endl;
    }

    // close the file
    inputFile.close();

    return 0;
}