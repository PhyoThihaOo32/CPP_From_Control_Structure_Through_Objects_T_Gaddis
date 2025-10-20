/*
This program demonstrates the vector empty member function.
*/

#include <iostream>
#include <vector>

using namespace std;

double avgVector(vector<int>);

int main()
{

    vector<int> values;

    int numValues;

    // get the number of elements to be stored in the vector
    cout << "How many number of values to be stored?" << endl;
    cin >> numValues;

    // stored the values into the vector
    for (int i = 0; i < numValues; i++)
    {
        int temp_values;
        cout << "Enter the values: ";
        cin >> temp_values;
        values.push_back(temp_values);
    }

    // display the values from the vector
    cout << "Display the values from the vector." << endl;
    for (int num : values)
    {
        cout << num << " ";
    }

    cout << endl;

    // get the average
    cout << "This is the average: " << avgVector(values) << endl;

    return 0;
}

double avgVector(vector<int> values)
{
    double avg,
        total = 0;
    if (values.empty())
    {
        cout << "There is no values inside the vector." << endl;
        avg = 0;
    }
    else
    {
        for (int i = 0; i < values.size(); i++)
        {
            total += values[i];
        }
        avg = total / (values.size());
    }

    return avg;
}