#include <iostream>
#include <string>

using namespace std;

// recursive algorithm to reverse string
string reverseString(string str)
{
    if (str.length() <= 1)
        return str;
    else
        return str[str.length() - 1] + reverseString(str.substr(0, str.length() - 1));
}

int main()
{

    string str("Hello");

    cout << reverseString(str) << endl;

    /*
    reverseString("Hello")
    str[4] -> "o" + reverseString(str.substr(0, 4) ->reverseString("Hell") <- o + l + l +  e + H
    str[3] -> "l" + reverseString(str,substr(0,3)) ->reverseString("Hel") <- l + l + e +  H
    str[2] -> "l" + reverseString(str.substr(0,2)) ->reverseString("He") <- l + e + H
    str[1] -> "e" + reverseString(str.substr(0,1)) ->reverseString("H") -> e + "H"
    */

    return 0;
}