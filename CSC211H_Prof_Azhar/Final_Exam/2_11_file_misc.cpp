/*
>> operator and getline() and get and put
-The >> operator reads data word by word or value by value. It skips whitespace such as spaces, tabs and newlines.
-getline() reads the whole line, including spaces until it reaches the newline character.
-get() reads one character at a time.
-put() writes one character to an output stream or file.
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    string name = "Hello World";
    string input;

    fstream outputFile("test.txt", ios::out);
    char c;

    cout << name << endl;

    cout << "Type anything." << endl;
    getline(cin, input);
    cout << input << endl;

    do
    {
        cout << "One Character at a time. Enter 0 to stop. ";
        cin.get(c);

        cout << c;
        if (c == '0')
            continue;
        // writing a character at a time to the file
        outputFile.put(c);

    } while (c != '0');

    return 0;
}