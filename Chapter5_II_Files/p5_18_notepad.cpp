/*
This program write user input[string] to the file.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ofstream outputFile; // creat ofstream object
    string user_input;

    // open the file
    outputFile.open("notepad.txt");

    // ask user to write anything
    cout << "You can write anything.\nEnter Q/q to quite.\n";
    getline(cin, user_input);

    while (user_input != "Q" && user_input != "q")
    {
        // write on the file
        outputFile << user_input << endl;
        getline(cin, user_input);
    }

    cout << "Alright. Finished Writing." << endl;

    // close the file
    outputFile.close();

    return 0;
}