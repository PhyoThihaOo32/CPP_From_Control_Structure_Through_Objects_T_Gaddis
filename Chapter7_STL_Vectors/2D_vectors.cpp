/*
=========================================================
2D VECTOR VISUAL REPRESENTATION
=========================================================

Example:
vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

---------------------------------------------------------

Structure (Vector of Vectors):

matrix
  ↓
+--------+--------+--------+
| Row 0  | Row 1  | Row 2  |
+--------+--------+--------+
    ↓        ↓        ↓

 [1,2,3]  [4,5,6]  [7,8,9]

---------------------------------------------------------

Table View:

Row\Col   0   1   2
        +---+---+---+
Row 0   | 1 | 2 | 3 |
        +---+---+---+
Row 1   | 4 | 5 | 6 |
        +---+---+---+
Row 2   | 7 | 8 | 9 |
        +---+---+---+

---------------------------------------------------------

Access Pattern:

matrix[row][col]

Examples:
matrix[0][0] → 1
matrix[1][2] → 6
matrix[2][1] → 8

---------------------------------------------------------

Traversal Order:

(0,0) → (0,1) → (0,2)
   ↓
(1,0) → (1,1) → (1,2)
   ↓
(2,0) → (2,1) → (2,2)

---------------------------------------------------------

Important Notes:

- Each row is a separate vector
- Rows can have different sizes (jagged array)

Example:
{ {1,2}, {3,4,5}, {6} }

=========================================================
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    // create 3x3 matrix
    vector<vector<int>> matrix(3, vector<int>(3));

    // input values
    cout << "Enter values: " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cin >> matrix[i][j];
        }
    }

    // print matrix
    cout << "Matrix: " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}