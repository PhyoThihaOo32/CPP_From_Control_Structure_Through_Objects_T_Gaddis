/*
break statement causes a loop to terminate early.
continue statement causes a loop to stop its current iteration and begin the next one.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    double number,
        power_number,
        result;
    char user_option;

    cout << "This program calculate the desired square of any number user enter." << endl;

    do
    {
        cout << "Enter a number: ";
        cin >> number;
        cout << "Enter the power number: ";
        cin >> power_number;

        // calculate the power of the number
        result = pow(number, power_number);

        // print out the result and ask user option
        cout << power_number << " power of " << number << " is: " << result << endl;

        cout << "Enter q to quite.";
        cin >> user_option;

        if (user_option == 'q' || user_option == 'Q')
        {
            break;
        }

    } while (1);
}