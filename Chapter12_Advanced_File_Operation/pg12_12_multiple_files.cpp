#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    fstream iFile;
    fstream oFile("ofile.txt", ios::out);
    string fileName;
    char c;

    cout << "Enter the file name: "; // ifile.txt
    cin >> fileName;

    iFile.open(fileName, ios::in);

    if (iFile)
    {
        while (iFile)
        {
            iFile.get(c);
            oFile.put(c);
            cout << c;
        }
        cout << "Done." << endl;
    }

    iFile.close();
    oFile.close();

    return 0;
}