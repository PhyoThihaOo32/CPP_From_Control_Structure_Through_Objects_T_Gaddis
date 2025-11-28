/*
This program display a string stored in a char array.
*/

#include <iostream>

using namespace std;

int main()
{

    const int SIZE = 80;
    char line[SIZE];
    int count = 0;

    // get the user input
    cout << "Enter a sentence of no more than " << SIZE - 1 << " characters." << endl;
    cin.getline(line, SIZE);
    /*
    cin.getline(line, SIZE) reads an entire line (including spaces) up to 79 characters or until the user presses Enter.
    It automatically appends '\0' (null terminator) at the end.
    */

    // display the character at a time using while loop
    while (line[count] != '\0')
    {
        cout << line[count++];
    }
    cout << endl;

    // dispaly the charcter using for loop
    for (int i = 0; line[i] != '\0'; i++)
    {
        cout << line[i] << " ";
    }

    return 0;
}