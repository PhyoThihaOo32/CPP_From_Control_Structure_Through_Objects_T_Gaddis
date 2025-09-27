#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // for setprecision
#include <limits>  // for numeric_limits

using namespace std;

int main()
{
    ifstream inputFile;
    string filename;
    double number;
    double minValue = numeric_limits<double>::max();
    double maxValue = numeric_limits<double>::lowest();
    double total = 0.0;
    int count = 0;

    // Keep prompting until file opens
    while (true)
    {
        cout << "Enter the filename: ";
        cin >> filename;

        inputFile.open(filename);
        if (inputFile)
        {
            break;
        }
        else
        {
            cout << "Error opening the file: " << filename << endl;
            inputFile.clear();
        }
    }

    // Process file
    while (inputFile >> number)
    {
        if (number < minValue)
            minValue = number;
        if (number > maxValue)
            maxValue = number;
        total += number;
        count++;
    }
    inputFile.close();

    // Check if file was empty
    if (count == 0)
    {
        cout << "The file contained no valid numbers.\n";
        return 0;
    }

    // Output results
    cout << fixed << setprecision(2);
    cout << "\nMinimum: " << minValue << endl;
    cout << "Maximum: " << maxValue << endl;
    cout << "Total: " << total << endl;
    cout << "Average: " << total / count << endl;
    cout << "Number of records: " << count << endl;

    return 0;
}