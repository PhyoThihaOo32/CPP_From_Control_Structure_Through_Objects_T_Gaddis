#include <iostream>

using namespace std;

int main()
{

    const int SIZE = 5;
    char healthOption[SIZE] = {'A', 'B', 'C', 'D', 'E'};
    int annualCost[SIZE] = {1800, 19000, 1700, 2100, 2500};

    int lowest_index = 0,
        lowestPrice = annualCost[0];
    for (int i = 1; i < SIZE; i++)
    {
        if (annualCost[i] < lowestPrice)
        {
            lowest_index = i;
        }
    }

    // print out the lowest health option
    cout << "Lowest Health Option: " << healthOption[lowest_index] << endl;

    return 0;
}