#include <iostream>

using namespace std;

void showMenu();
void quadratic(double, double, double);
int signOf(float);
bool is_Even(int);
int absolue_value(int);

int main()
{
    char option;
    double x, y, z;
    float fnumber;
    int num, abs;
    bool isEven;

    do
    {
        showMenu();
        cin >> option;

        switch (option)
        {
        case 'A':
            cout << "Enter your number. This function will return the absolute value." << endl;
            cin >> abs;
            cout << "The absolute value is : " << absolue_value(abs) << endl;
            break;
        case 'E':
            cout << "Enter the number. This function will check if the number is even or odd." << endl;
            cin >> num;
            isEven = is_Even(num);
            if (isEven)
            {
                cout << num << " is an even number" << endl;
            }
            else
            {
                cout << num << " is an odd number" << endl;
            }

            break;
        case 'S':
            cout << "Type a number: The program print -1 for negative and 1 for postitve and 0 for 0." << endl;
            cin >> fnumber;
            cout << "Sign of the number is : " << signOf(fnumber) << endl;

            break;
        case 'Q':
            cout << "Type 3 values for the quadratic function: " << endl;
            cin >> x >> y >> z;
            quadratic(x, y, z);
            cout << endl;
            break;
        case 'X':
            cout << "Thank you for using our program! Goodbye." << endl;
            break;
        default:
            cout << option << " is not a valid input." << endl;
            break;
        }

    } while (option != 'X');
    return 0;
}

void showMenu()
{
    char user_option;
    cout << "A- absolute value." << endl;
    cout << "E- checks if your number is even." << endl;
    cout << "S- sign of a number." << endl;
    cout << "Q- solution for quadratic equation." << endl;
    cout << "X -exit" << endl;
    cout << "Type your choice: ";
}

void quadratic(double a, double b, double c)
{
    if (a == 0)
    {
        cout << "no solution for a=0" << endl;
    }
    else if ((b * b) - (4 * a * c) < 0)
    {
        cout << "no real solutions" << endl;
    }
    else
    {
        cout << ((-b + sqrt(b * b - (4 * a * c))) / (2 * a)) << endl;
    }
}

int signOf(float num)
{
    int sign;
    if (num < 0)
        sign = -1;
    else if (num > 0)
        sign = 1;
    else
        sign = 0;
    return sign;
}

bool is_Even(int num)
{

    return num % 2 == 0;
}

int absolue_value(int num)
{
    return num < 0 ? -num : num;
}