/*
expression ? expression : expression
conditional operator - takes thress operand - considered ternary operator.
all expressions have a value - therefore
if the first sub-expression is true - the value of conditional expression is the value of the second sub-expression
otherwise - the value of the third sub-expression.
a = x > 100 ? 0 : 1;
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    const double PAY_RATE = 50.0; // hourly pay rate
    const int MIN_HOUR = 5;       // minium billable hour
    double hours, charges;

    // get the working hour
    cout << "How many hours were worked?\n";
    cin >> hours;

    // determin the hours to charge for
    hours = hours < MIN_HOUR ? MIN_HOUR : hours;

    // calculate the charges
    charges = hours * PAY_RATE;

    // set the numeric output format
    cout << setprecision(2) << fixed << showpoint
         << "The charges are $: " << charges << endl;

    return 0;
}