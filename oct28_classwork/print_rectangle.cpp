#include <iostream>

using namespace std;

void print_rectangle(int, int, char); // you can omit the parameter names here
void print_rectangle();
void print_dashLines(int);

int main()
{

    print_rectangle(10, 15, '*'); // in arguments list you are putting the actual values

    print_rectangle();

    print_dashLines(10);

    return 0;
}

void print_rectangle(int heigth, int width, char symbol) // parameter list are like place holders
{
    for (int i = 0; i < width + 2; i++)
    {
        cout << '-' << " ";
    }
    cout << endl;
    for (int i = 0; i < heigth; i++)
    {
        cout << '-' << " ";
        for (int j = 0; j < width; j++)
        {
            cout << symbol << " ";
        }
        cout << '-' << " ";
        cout << endl;
    }
    for (int i = 0; i < width + 2; i++)
    {
        cout << '-' << " ";
    }
    cout << endl;
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

void print_dashLines(int num)
{
    if (num < 1)
        ;
    else
    {
        for (int i = 0; i < num; i++)
        {
            cout << '-';
        }
        cout << endl;
    }
}