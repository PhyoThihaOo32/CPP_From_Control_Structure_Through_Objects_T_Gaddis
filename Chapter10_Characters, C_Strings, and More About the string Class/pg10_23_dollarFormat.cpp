/*
This program lets the user enter a number.
The dollarFormat function formats the number as a dollar amount with commas and a '$' sign.
Example:
Input:  1234567.89
Output: $1,234,567.89
*/

#include <iostream>
#include <string>
using namespace std;

// Function prototype
void dollarFormat(string &);

int main()
{
    string input;

    // Get the dollar amount from the user
    cout << "Enter the dollar amount in the form nnnn.nn: ";
    cin >> input;

    // Format the number
    dollarFormat(input);

    // Display the formatted amount
    cout << "Formatted amount: " << input << endl;

    return 0;
}

/*
This function inserts commas in the proper positions
and adds a dollar sign at the beginning of the number string.
*/
void dollarFormat(string &currency)
{
    // Find the decimal point position (if any)
    size_t dp = currency.find('.');

    // If there's no decimal point, assume end of string
    if (dp == string::npos)
    {
        dp = currency.length();
    }

    // Insert commas every three digits before the decimal point
    for (int i = static_cast<int>(dp) - 3; i > 0; i -= 3)
    {
        currency.insert(i, ",");
    }

    // Insert $ at the beginning
    currency.insert(0, "$");
}