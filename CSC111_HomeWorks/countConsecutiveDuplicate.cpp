/*
Consider this data sequence: “3 11 5 5 5 2 4 6 6 7 3 -8”. Any value that is the same as the immediately preceding value is considered a CONSECUTIVE DUPLICATE. In this example, there are three such consecutive duplicates: the 2nd and 3rd 5s and the second 6. Note that the last 3 is not a consecutive duplicate because it was preceded by a 7.

Write some code that uses a loop to read such a sequence of non-negative integers, terminated by a negative number. When the code exits the loop it should print the number of consecutive duplicates encountered. In the above case, that value would be 3.

Additional Notes: Regarding your code’s standard output, CodeLab will check for case errors and will check whitespace (tabs, spaces, newlines) exactly
*/

#include <iostream>

using namespace std;

int main()
{

    int number1, number2;
    int count = 0;

    if (cin >> number1 && number1 > 0)
    {
        while (cin >> number2 && number2 > 0)
        {
            if (number2 == number1)
            {
                count++;
            }
            number1 = number2;
        }
    }

    cout << count;

    return 0;
}