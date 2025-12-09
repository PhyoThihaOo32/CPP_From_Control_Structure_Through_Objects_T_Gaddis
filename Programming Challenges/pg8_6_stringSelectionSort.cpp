/*
This program sorts a string array using the Selection Sort algorithm
and allows the user to search for a name using Binary Search.
*/

#include <iostream>
#include <string>
using namespace std;

// Function prototypes
void selectionSort(string[], int);
void showArray(const string[], int);
int binarySearch(const string[], int, const string &);

int main()
{
    const int SIZE = 20;
    string actorNames[SIZE] = {
        "Leonardo DiCaprio",
        "Meryl Streep",
        "Tom Hanks",
        "Denzel Washington",
        "Scarlett Johansson",
        "Brad Pitt",
        "Morgan Freeman",
        "Natalie Portman",
        "Robert De Niro",
        "Jennifer Lawrence",
        "Johnny Depp",
        "Cate Blanchett",
        "Will Smith",
        "Emma Stone",
        "Christian Bale",
        "Julia Roberts",
        "Samuel L. Jackson",
        "Anne Hathaway",
        "Hugh Jackman",
        "Sandra Bullock"};

    string name;
    int searchIndex;

    // Sort the array alphabetically
    selectionSort(actorNames, SIZE);

    // Display sorted names
    cout << "=== Sorted Actor Names ===\n";
    showArray(actorNames, SIZE);

    // Input name to search
    cout << "\nEnter the actor's full name to search: ";

    getline(cin, name); // allows multi-word names

    // Binary search
    searchIndex = binarySearch(actorNames, SIZE, name);

    if (searchIndex == -1)
        cout << "\n❌ " << name << " was not found in the list.\n";
    else
        cout << "\n✅ Found: " << actorNames[searchIndex]
             << " (Position " << searchIndex + 1 << ")\n";

    return 0;
}

/*
Selection sort: Finds the smallest element in each pass and moves it to the front.
*/
void selectionSort(string array[], int size)
{
    int minIndex;
    string minValue;

    for (int start = 0; start < size - 1; start++)
    {
        minIndex = start;
        minValue = array[start];

        for (int index = start + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }

        array[minIndex] = array[start];
        array[start] = minValue;
    }
}

/*
Displays the contents of a string array.
*/
void showArray(const string array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << i + 1 << ". " << array[i] << endl;
}

/*
Binary search: Returns index of the found string or -1 if not found.
*/
int binarySearch(const string array[], int size, const string &value)
{
    int first = 0, last = size - 1, middle;
    int position = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2;

        if (array[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value)
            last = middle - 1;
        else
            first = middle + 1;
    }

    return position;
}