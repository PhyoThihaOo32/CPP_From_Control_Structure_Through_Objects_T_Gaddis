/*
This program compare the contents of two files to see if they are indentical.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    fstream file1("file1.txt", ios::in);
    fstream file2("file2.txt", ios::in);

    char c1, c2;

    if (!file1 || !file2)
    {
        cerr << "File Error." << endl;
        return 1;
    }

    while (file1.get(c1) && file2.get(c2))
    {
        if (c1 != c2)
        {
            cout << "Different contents." << endl;
            break;
        }
    }

    // if both file reach the same end
    if (file1.eof() && file2.eof())
    {
        cout << "Files are identical." << endl;
    }
    else
    {
        cout << "File are not identical." << endl;
    }

    return 0;
}