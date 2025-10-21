/*
This program ask the user for length(height)(rows) and width(columns),ask the user for the character
for the rectangle and print out the rectangle.
*/

#include <iostream>

using namespace std;

int main()
{

    char user_char;
    int length,
        width;

    cout << "Enter the charcter that you want to print: ";
    cin >> user_char;

    // rows
    cout << "Enter the length of the rectangle: ";
    cin >> length;

    // columns
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    for (int i = 1; i <= length + 2; i++)
    {
        cout << '-';
    }
    cout << endl;
    for (int i = 1; i <= length; i++)
    {

        cout << '-';
        for (int j = 1; j <= width; j++)
        {

            cout << user_char;
        }
        cout << '-';
        cout << endl;
    }

    for (int i = 1; i <= length + 2; i++)
    {
        cout << '-';
    }
    cout << endl;

    return 0;
}