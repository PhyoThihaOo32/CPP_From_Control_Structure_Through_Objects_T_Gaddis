/*
Retlation operator compare not only numeric value but also character and strings.
Character are actually stored in memory as integers - which are usually ASCII values.
When two characters are compared it is acutally their ASCII values that are being compared.
*/

#include <iostream>

using namespace std;

int main()
{

    char user_input;

    // get user input
    cout << "Enter a character or a digit." << endl;
    cin.get(user_input);

    // determine what the user entered
    if (user_input >= '0' && user_input <= '9') // 0 = 48 / 9 = 57
    {
        cout << "This is a digit." << endl;
    }
    else if (user_input >= 'A' && user_input <= 'Z') // A = 65 / Z = 90
    {
        cout << "This is a upper case letter." << endl;
    }
    else if (user_input >= 'a' && user_input <= 'z') // a = 97 / z = 122
    {
        cout << "This is lower case letter." << endl;
    }
    else
    {
        cout << "This is not a digit or a character." << endl;
    }

    return 0;
}