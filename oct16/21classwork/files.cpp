#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ofstream outputFile;
    outputFile.open("myFile.txt");

    string input;
    cout << "You can start typing. And Enter 'Q' or 'q' to quit." << endl;

    while (cin >> input && !(input == "Q" || input == "q"))
    {
        outputFile << input << endl;
    }

    outputFile.close();

    ifstream inputFile("myFile.txt");

    while (inputFile >> input)
    {
        cout << input << endl;
    }

    inputFile.close();

    return 0;
}