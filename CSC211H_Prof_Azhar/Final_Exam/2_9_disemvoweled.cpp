/*
9) Write a program that removes all vowels from a file (“disemvowels”). For example, Once upon a time! becomes nc pn tm!. Surprisingly often, the result will still readable, try it with your classmates.
*/

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

bool isVowel(char);

int main()
{

    char c;

    fstream iFile("vowels.txt", ios::in);
    fstream outFile("disemvoweled.txt", ios::out);

    if (!iFile || !outFile)
    {
        cout << "Error. Can't open the Files.";
        return 1;
    }

    while (iFile.get(c))
    {
        if (!isVowel(c))
        {
            outFile.put(c);
        }
    }

    return 0;
}

bool isVowel(char c)
{
    c = static_cast<char>(tolower(c));
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}