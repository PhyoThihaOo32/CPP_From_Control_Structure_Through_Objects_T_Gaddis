/*
Default arguments are passed into function automatically if no argument is provided in the function call.
The value of default args must be literal value or a named constant.
When an argument is left out of a function call(because it has a default value), all the arguments that come
after it must be left out too.
When a function has a mixture of parameters both with and without default arguments, the parameters with
default arguments must be declared last.
*/

#include <iostream>

using namespace std;

// function prototype
void printAsterisks(int = 5, int = 5);

int main()
{
    int user_columns,
        user_rows;

    // ask user input
    cout << "How many columns? How many rows?" << endl;
    cin >> user_columns >> user_rows;

    printAsterisks(user_columns, user_rows);
    cout << endl;
    printAsterisks();

    return 0;
}

// function print asterisks in rows and columns [ default row = 5, column = 5]
void printAsterisks(int columns, int rows)
{

    // nested loops: outloop controls the rows/ inner loops control the column
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << " * ";
        }
        cout << "\n";
    }
}