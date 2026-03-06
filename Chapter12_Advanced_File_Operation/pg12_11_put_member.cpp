/*
This program demonstates the put memeber function.
(put member function - writes a single character to the file.)
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    fstream ofile("put.txt", ios::out);
    char c;

    if (ofile)
    {
        cout << "Period(.) to stop Typing.";
        cin.get(c);
        while (c != '.')
        {
            ofile.put(c);
            cin.get(c);
        }
        ofile.put(c);
    }
    else
    {
        cerr << "Error opening the file." << endl;
    }
    ofile.close();

    return 0;
}