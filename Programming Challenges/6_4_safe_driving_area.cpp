/*
This program determines which of five geographic regions within a major city
has the fewest reported automobile accidents last year.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
int getNumAccidents(const string &);
void findLowest(int, int, int, int, int);

// Named constants for region names
const string REGION1 = "Queens",
             REGION2 = "Brooklyn",
             REGION3 = "Manhattan",
             REGION4 = "Bronx",
             REGION5 = "Staten Island";

int main()
{
    cout << "=== NYC Automobile Accident Report ===\n";

    // Get accident numbers for each region
    int acc1 = getNumAccidents(REGION1);
    int acc2 = getNumAccidents(REGION2);
    int acc3 = getNumAccidents(REGION3);
    int acc4 = getNumAccidents(REGION4);
    int acc5 = getNumAccidents(REGION5);

    // Determine and display the region with the fewest accidents
    findLowest(acc1, acc2, acc3, acc4, acc5);

    return 0;
}

/*
This function takes a region name, asks the user for the number of accidents,
validates that the number is not negative, and returns it.
*/
int getNumAccidents(const string &regionName)
{
    int numAccidents;

    do
    {
        cout << "Enter the number of accidents in " << regionName << " region: ";
        cin >> numAccidents;

        if (numAccidents < 0)
            cout << "Invalid input. Accident numbers cannot be negative. Please re-enter.\n";
    } while (numAccidents < 0);

    return numAccidents;
}

/*
This function receives the five accident totals and determines which region
had the fewest accidents. It prints that region's name and number of accidents.
*/
void findLowest(int acc1, int acc2, int acc3, int acc4, int acc5)
{
    int lowest = acc1;
    string lowestRegion = REGION1;

    if (acc2 < lowest)
    {
        lowest = acc2;
        lowestRegion = REGION2;
    }
    if (acc3 < lowest)
    {
        lowest = acc3;
        lowestRegion = REGION3;
    }
    if (acc4 < lowest)
    {
        lowest = acc4;
        lowestRegion = REGION4;
    }
    if (acc5 < lowest)
    {
        lowest = acc5;
        lowestRegion = REGION5;
    }

    cout << "\n=====================================\n";
    cout << "The safest region is: " << lowestRegion << endl;
    cout << "Number of accidents: " << lowest << endl;
    cout << "=====================================\n";
}