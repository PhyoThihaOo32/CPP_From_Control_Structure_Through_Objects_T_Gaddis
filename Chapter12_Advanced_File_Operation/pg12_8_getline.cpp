/*
getline(filename, str, '\n')
filename - name of the file
str - the date read from the file will be store here
'\n' - is the delimiter - can choose any character - optional - default is '\n'
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    fstream iFile;
    iFile.open("murphy.txt", ios::in);

    string input;

    // while (!iFile.fail() && iFile.good())
    // {
    //     getline(iFile, input);
    //     cout << input << endl;
    // }

    if (iFile) // if (!iFile.fail() && !iFile.bad())
    {
        getline(iFile, input);
        while (iFile /*iFile.good()*/)
        /*
        why not iFile.good()
        iFile.good() is stricter.
        if(iFile)           stream usable (no failbit or badbit)
        iFile.good()        no flags at all (eofbit, failbit, badbit)
        */
        {
            cout << input << endl;
            getline(iFile, input);
        }
        // cou << input << endl;
    }
    else
    {
        cout << "Cann't open the file." << endl;
    }
    iFile.close();

    return 0;
}