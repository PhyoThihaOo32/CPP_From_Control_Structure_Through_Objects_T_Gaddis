#include <iostream>

using namespace std;

void print_rectangle();
void print_rectangle(int, int);
void print_rectangle(int, int, char);

int main()
{

    print_rectangle(3, 4);
    cout << endl;
    print_rectangle(5, 6, '|');
    cout << endl;
    print_rectangle();

    return 0;
}

void print_rectangle(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

void print_rectangle(int row, int col, char sym)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << sym << " ";
        }
        cout << endl;
    }
}
void print_rectangle()
{
    int rows, columns;
    char symbol;

    cout << "How many rows: ";
    cin >> rows;

    cout << "How many columns: ";
    cin >> columns;

    cout << "You favourite symbol: ";
    cin >> symbol;
    for (int i = 0; i < columns + 2; i++)
    {
        cout << '-' << " ";
    }
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << '-' << " ";
        for (int j = 0; j < columns; j++)
        {
            cout << symbol << " ";
        }
        cout << '-' << " ";
        cout << endl;
    }
    for (int i = 0; i < columns + 2; i++)
    {
        cout << '-' << " ";
    }
    cout << endl;
}