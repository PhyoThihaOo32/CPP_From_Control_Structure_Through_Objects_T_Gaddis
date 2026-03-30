/*
9) Write a program that removes all vowels from a file (“disemvowels”).
For example, Once upon a time! becomes nc pn tm!.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    fstream fileIn("withVowels.txt", ios::in);
    fstream fileOut("withoutVowels.txt", ios::out);
    char ch, chv;

    if (fileIn)
    {
        fileIn.get(ch);
        while (fileIn)
        {

            if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' && ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U')
            {
                fileOut << ch;
                cout << ch;
            }

            fileIn.get(ch);
        }
    }

    fileIn.close();
    fileOut.close();

    return 0;
}