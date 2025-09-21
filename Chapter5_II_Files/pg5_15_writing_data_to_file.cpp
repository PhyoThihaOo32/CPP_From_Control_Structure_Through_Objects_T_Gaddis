/*
This program demonstrate writing data to a file.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ofstream outputFile;
    outputFile.open("demofile.txt");

    cout << "Now writing data to the file." << endl;

    // writing data to the file
    outputFile << "Bart Simpson\n"
               << "Homer Simpson\n"
               << "Marge Simpson\n"
               << "Lisa Simpson\n"
               << "Meggie Simpson\n";

    // close the file
    outputFile.close();

    cout << "Always remember to close the file." << endl;

    return 0;
}