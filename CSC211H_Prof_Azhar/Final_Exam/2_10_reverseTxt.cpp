/*
Reverse the order of characters in a text file. For example, computer becomes
retupmoc
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    fstream iFile("vowels.txt", ios::in);
    fstream oFile("reverse.txt", ios::out);

    long endIndex;
    char c;

    // get the last index from the file
    iFile.seekg(0L, ios::end);
    endIndex = iFile.tellg();
    // cout << endIndex;

    // reverse the text in store it in the file
    for (int i = endIndex - 1; i >= 0; i--)
    {
        iFile.seekg(i, ios::beg);
        iFile.get(c);
        cout << c;
        oFile.put(c);
    }

    return 0;
}