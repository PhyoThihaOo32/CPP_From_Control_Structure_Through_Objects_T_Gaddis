/*
fstream objects may be passed by reference to functions.
The internal state of file stream objects changes with most every operation.
They should always be passed to functions by reference to ensure internal consistency.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool openFile(fstream &, string);
void readFile(fstream &);

int main()
{
    fstream dataFile;

    if (openFile(dataFile, "dataFile.txt"))
    {
        cout << "File opened successfully." << endl;
        cout << "Reading File contents ..... " << endl;
        readFile(dataFile);
        dataFile.close();
    }
    else
    {
        cout << "Error opening the file." << endl;
    }

    return 0;
}

bool openFile(fstream &file, string fileName)
{

    file.open(fileName, ios::in);
    return file.fail() ? false : true;
}

void readFile(fstream &file)
{
    string str;
    while (file >> str)
    {
        cout << str << endl;
    }
}
