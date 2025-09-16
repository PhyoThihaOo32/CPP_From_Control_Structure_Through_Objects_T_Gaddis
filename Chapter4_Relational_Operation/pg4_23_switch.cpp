/*
swith statment test the value of the integer expression and then use that value to determine
which set of statement to branch to.
swtich(integer expression) - a variable of any integer data type (including char)
                          - an expression who value is any of the integer data types.
case ConstantExpression: (aslo integer data type - integer literal or constant)
*/

#include <iostream>

using namespace std;

int main()
{

    char choice;

    cout << "Enter A, B, C or D: ";
    cin.get(choice);

    switch (choice)
    {         // integer expression
    case 'A': // unique constant expression
        cout << "You entered A.\n";
        break;
    case 'B': // character variable and literal are considered integers
        cout << "You entered B.\n";
        break;
    case 'C':
        cout << "You entered C.\n";
        break;
    case 'D':
        cout << "You entered D.\n";
        break;
    default: // no need break statment - you can put break for consistency
        cout << "What else?" << endl;
    }

    return 0;
}