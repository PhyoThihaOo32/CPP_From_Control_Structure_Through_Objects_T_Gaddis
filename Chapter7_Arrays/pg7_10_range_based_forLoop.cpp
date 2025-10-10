/*
The range based for loop is a loop that iterates[automatically] one for each element in an array.
Each time the loop iterates, it copies an element from the array to a build-in variable called range variable.
Advantages: Range based for loop automatically know the number of elements of an array
            do not have to worry about stepping outside the bound of an array
*/

#include <iostream>

using namespace std;

int main()
{

    // implicit array sizing
    string viking_name[] = {"Ragnar", "Lagertha", "Bjorn", "Floki", "Ubbe", "Ivar", "Hvitserk", "Sigurd", "Torvi", "Aslaug"};

    // using range_based for loop
    for (auto name : viking_name)
    {
        cout << name << endl;
    }

    return 0;
}