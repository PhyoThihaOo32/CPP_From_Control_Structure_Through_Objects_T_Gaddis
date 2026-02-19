/*
5. Monkey Business

A local zoo wants to keep track of how many pounds of food each of its three monkeys eats each day during a typical week. Write a program that stores this information in a two-dimensional 3 × 5 array, where each row represents a different monkey and each column represents a different day of the week. The program should first have the user input the data for each monkey. Then it should create a report that includes the following information:
• Average amount of food eaten per day by the whole family of monkeys.
• The least amount of food eaten during the week by any one monkey.
• The greatest amount of food eaten during the week by any one monkey.

Input Validation: Do not accept negative numbers for pounds of food eaten.
*/

#include <iostream>

using namespace std;

class MonkeyBussiness
{
private:
    int rows;
    int cols;
    int **ptr; // pointer to 2D dynamic array

public:
    // constructor: allocate 2D array
    MonkeyBussiness(int r, int c) : rows(r), cols(c)
    {
        ptr = new int *[rows]; // array of row pointers
        for (int i = 0; i < rows; i++)
        {
            ptr[i] = new int[cols]; // each row has cols elements
        }
    }

    // destructor: free all allocated memory
    ~MonkeyBussiness()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] ptr[i]; // delete each row
        }
        delete[] ptr; // delete pointer array
    }

    void getFoodConsumption();
    void displayFoodConsumption() const;

    double getAvgConsumption() const; // average should be double
    int getLeastAmount() const;
    int getGreatestAmount() const;
};

// input with validation (no negatives)
void MonkeyBussiness::getFoodConsumption()
{
    cout << "Enter Food Consumption:\n";

    for (int r = 0; r < rows; r++)
    {
        cout << "Monkey " << r + 1 << endl;

        for (int c = 0; c < cols; c++)
        {
            int value;
            do
            {
                cout << "Day " << c + 1 << ": ";
                cin >> value;

                if (value < 0)
                    cout << "Negative not allowed. Try again.\n";

            } while (value < 0);

            ptr[r][c] = value;
        }
    }
}

// display table
void MonkeyBussiness::displayFoodConsumption() const
{
    cout << "\nFood Consumption Table:\n";

    for (int r = 0; r < rows; r++)
    {
        cout << "Monkey " << r + 1 << ": ";
        for (int c = 0; c < cols; c++)
        {
            cout << ptr[r][c] << " ";
        }
        cout << endl;
    }
}

// average of all cells
double MonkeyBussiness::getAvgConsumption() const
{
    int total = 0;

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            total += ptr[r][c];

    return static_cast<double>(total) / (rows * cols);
}

// find minimum
int MonkeyBussiness::getLeastAmount() const
{
    int least = ptr[0][0];

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (ptr[r][c] < least)
                least = ptr[r][c];

    return least;
}

// find maximum
int MonkeyBussiness::getGreatestAmount() const
{
    int greatest = ptr[0][0];

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (ptr[r][c] > greatest)
                greatest = ptr[r][c];

    return greatest;
}

int main()
{
    MonkeyBussiness mb(3, 5); // (3 monkeys, 5 days)

    mb.getFoodConsumption();
    mb.displayFoodConsumption();

    cout << "\nAverage Food: " << mb.getAvgConsumption() << endl;
    cout << "Least Amount: " << mb.getLeastAmount() << endl;
    cout << "Greatest Amount: " << mb.getGreatestAmount() << endl;

    return 0;
}

/*
DETAILED COMMENT (for your notes)

CLASS PURPOSE
-------------
MonkeyBusiness dynamically creates a 2D array of ints with:
- 3 rows
- 5 columns per row
using "int**" (pointer-to-pointer).

WHY int** ?
-----------
A 2D dynamic array is built as:
1) A dynamic array of row pointers (int*)
2) Each row pointer points to a dynamic array of ints (the columns)

So memory is NOT one big contiguous 3x5 block.
Instead, each row is allocated separately.

MEMORY SHAPE AFTER CONSTRUCTOR
------------------------------
ptr
 ↓
+---------+---------+---------+
| ptr[0]  | ptr[1]  | ptr[2]  |   <-- allocated by: new int*[3]
+----•----+----•----+----•----+
     |         |         |
     ↓         ↓         ↓
 [0][1][2][3][4]   [0][1][2][3][4]   [0][1][2][3][4]
   row 0             row 1             row 2
(each row allocated by: new int[5])

TOTAL ALLOCATIONS
-----------------
- 1 allocation for the row pointer array: new int*[3]
- 3 allocations for the rows: ptr[i] = new int[5]
Total = 4 separate allocations.

CONSTRUCTOR STEP-BY-STEP
------------------------
Step 1:
ptr = new int*[3];
- allocates space for 3 pointers (rows)
- ptr now points to an array of 3 int* slots, uninitialized

Step 2:
for i = 0..2:
    ptr[i] = new int[5];
- allocates 5 ints for each row
- ptr[i] now points to a valid int array (columns)

DESTRUCTOR PURPOSE
------------------
The destructor must free ALL memory allocated in the constructor.
If we do not free it, we create a MEMORY LEAK.

DESTRUCTOR STEP-BY-STEP
-----------------------
Step 1: Delete each row first
for i = 0..2:
    delete[] ptr[i];
Reason:
- each ptr[i] was allocated using new int[5]
- so it MUST be freed using delete[] (not delete)

Step 2: Delete the row pointer array
delete[] ptr;
Reason:
- ptr was allocated using new int*[3]
- so it MUST be freed using delete[]

IMPORTANT DELETION RULE
-----------------------
Always delete "children" before "parent".
- If you delete ptr first, you lose access to ptr[i] addresses,
  so you cannot delete the rows anymore => memory leak.

WHY delete[] INSTEAD OF delete ?
--------------------------------
new[] must match delete[]
new must match delete

Since we used:
- new int*[3]
- new int[5]
we must use:
- delete[] ptr
- delete[] ptr[i]

WHAT ptr[i][j] MEANS
--------------------
ptr[i][j] is equivalent to:
- go to row i (ptr[i] gives the address of row i array)
- then index into that row at column j

Example:
ptr[1][3] = 10;
means:
- 2nd row (index 1), 4th column (index 3) becomes 10

COMMON MISTAKES
---------------
1) Forget destructor => memory leak
2) Use delete instead of delete[] => undefined behavior
3) Delete ptr before rows => memory leak
4) Not allocating rows => crash when accessing ptr[i][j]
*/