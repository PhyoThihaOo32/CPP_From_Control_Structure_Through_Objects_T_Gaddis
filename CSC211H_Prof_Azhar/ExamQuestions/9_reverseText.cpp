/*
This Program reverse the order of characters in a text file. For example, computer becomes
retupmoc
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    fstream fileIn("withVowels.txt", ios::in);
    fstream fileOut("reverse.txt", ios::out);
    char ch;

    long end;
    fileIn.seekg(0L, ios::end);
    end = fileIn.tellg(); // get the last byte of the file and store it in end

    for (int i = end - 1; i >= 0; i--) // but for index start with 0
    {
        fileIn.seekg(i, ios::beg);
        fileIn.get(ch);
        cout << ch;
        fileOut << ch;
    }

    fileIn.close();
    fileOut.close();

    return 0;
}
