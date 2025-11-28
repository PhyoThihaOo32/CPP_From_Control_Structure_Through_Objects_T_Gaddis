/*
This program demonstrates the C++ string class.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{

    string str1, str2, str3;

    str1 = "abc";
    str2 = "def";
    str3 = str1 + str2; // + operator return a string that is the concatenation of the two string operands

    str3 += "ghi"; // += appends a copy of the string on the right to the string object on the left

    // length member function returns the length of the string stored in the object.
    // the value is returned as an unsigned integer.

    unsigned int lenStr3 = str3.length();

    // use substripts to display str3 one chracter at a time
    for (int i = 0; i < str3.size(); i++)
    {
        cout << str3[i] << " ";
    }

    cout << endl;

    // compare str1 and str2
    if (str1 < str2)
        cout << "str1 is less than str2." << endl;
    else if (str1 > str2)
        cout << "str1 is greater than str2." << endl;
    else
        cout << "str1 and str2 are equal." << endl;

    return 0;
}