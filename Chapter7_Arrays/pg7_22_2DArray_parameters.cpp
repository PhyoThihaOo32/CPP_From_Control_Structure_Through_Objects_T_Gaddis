/*
This program demonstrates passing 2D arrays as function arguments
and declaring 2D arrays as function parameters.
Note: When 2D array is passed to a function, the parameter type must contain a size declarator for the
number of columns.
*/

#include <iostream>

using namespace std;

// global variables
const int COLS = 4;
const int TBL1_ROWS = 3;
const int TBL2_ROWS = 4;

void showArray(const int[][COLS], int);
double get_total(const int[][COLS], int);
void get_totalRows(const int[][COLS], int);
void get_totalCols(const int[][COLS], int);

int main()
{
    int table1[TBL1_ROWS][COLS] = {{1, 2, 3, 4},
                                   {5, 6, 7, 8},
                                   {9, 10, 11, 12}};
    int table2[TBL2_ROWS][COLS] = {{11, 22, 33, 44},
                                   {55, 66, 77, 88},
                                   {99, 100, 110, 120},
                                   {130, 140, 150, 160}};

    cout << "Table 1: " << endl;
    showArray(table1, TBL1_ROWS);

    cout << "Table 2: " << endl;
    showArray(table2, TBL2_ROWS);

    // getting the total of table1
    cout << get_total(table1, TBL1_ROWS) << endl;

    // getting the total of rows from table1
    get_totalRows(table1, TBL1_ROWS);

    // getting the total of columns from table1
    get_totalCols(table1, TBL1_ROWS);

    return 0;
}

void showArray(const int numbers[][COLS], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << numbers[i][j] << "\t";
        }
        cout << endl;
    }
}

// summing all the elements of a 2D array
double get_total(const int numbers[][COLS], int rows)
{
    double total = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            total += numbers[i][j];
        }
    }
    return total;
}

// summing the rows of 2D array
void get_totalRows(const int numbers[][COLS], int rows)
{

    for (int i = 0; i < rows; i++)
    {
        double total = 0;
        for (int j = 0; j < COLS; j++)
        {
            total += numbers[i][j];
        }
        cout << "Total of row " << (i + 1) << " : " << total << endl;
    }
}

// summing the columns of 2D array
void get_totalCols(const int numbers[][COLS], int rows)
{
    for (int col = 0; col < COLS; col++)
    {
        double total = 0;
        for (int row = 0; row < rows; row++)
        {
            total += numbers[row][col];
        }
        cout << "Total of column " << (col + 1) << " : " << total << endl;
    }
}
