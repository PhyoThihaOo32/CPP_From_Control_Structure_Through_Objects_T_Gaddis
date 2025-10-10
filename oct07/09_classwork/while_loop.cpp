/*
This program demonstrate the while loop.
This program will ask the user to type and character - the program stop when user type capital Q.
*/

#include <iostream>

using namespace std;

int main()
{

    char user_input;

    cout << "Type any character. Q to quite the program. ";
    cin >> user_input;

    while (user_input != 'Q')
    {

        cout << "Type any character. Q to quite the program. ";
        cin >> user_input;
    }
    return 0;
}
