/*
This program is for solving (right) triangles problems.
1.The program can check if the triangle is a right triangle or not.
2.The program can print isoceles right triangle with user choice symbols and leg size.
3.The program can calculate the length of hypotenuse.
*/

#include <iostream>
#include <cmath>

using namespace std;

// function prototypes
bool is_right_triangle(float, float, float);
float findHypotenuse(float, float);
void show_iso_right(int);
void show_iso_right(int, char); // function overloading with different parameters

int main()
{

    float hypotenuse, user_leg1, user_leg2; // to calculate hypotenuse
    bool is_right_tri;                      // to check for right triangle
    int user_leg;                           // to print iso triangles
    float user_angle1,
        user_angle2,
        user_angle3;
    char user_choice, user_symbol;

    cout << "This program can draw right isoceles triangles.\nHere's examples with leg length 3: " << endl;
    // printing triangle with leg 3, default symbol is #
    show_iso_right(3);

    cout << "Here's examples with leg length 3, printed with dollar signs:" << endl;
    show_iso_right(3, '$');

    cout << endl;
    // getting user input
    cout << "Type a whole number for the leg length: ";
    cin >> user_leg;

    cout << "Would you like to choose your own symbol for drawing? (Type Y for yes)";
    cin >> user_choice;
    if (user_choice == 'Y' || user_choice == 'y')
    {
        cout << "Type a symbol: ";
        cin >> user_symbol;
        // printing triagnle with user choice of leg and symbol
        show_iso_right(user_leg, user_symbol);
    }
    else
    {
        // print triangle with user choice of leg and default symbol #
        show_iso_right(user_leg);
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "This program can find a hypotenuse.\n";
    // calculate length of hypotenuse using leg 3 and 4 and cast to int and print the return value
    cout << "Ex: With leg lengths 3 and 4, the hypotenuse is ";
    hypotenuse = static_cast<int>(findHypotenuse(3, 4));
    cout << hypotenuse << endl;

    // getting user input: leg1 and leg2
    cout << "Type two leg length: ";
    cin >> user_leg1 >> user_leg2;
    cout << "The hypotenuse is " << findHypotenuse(user_leg1, user_leg2) << endl;
    cout << "-----------------------------------------------------------" << endl;

    cout << "The program will tell you if you have a valid right triangle." << endl;
    // getting user input for three angles
    cout << "Type three angles: ";
    cin >> user_angle1 >> user_angle2 >> user_angle3;

    // checking for right triangle
    is_right_tri = is_right_triangle(user_angle1, user_angle2, user_angle3);

    // print out the result
    cout << "The rectangle with angles "
         << user_angle1 << " " << user_angle2 << " " << user_angle3;
    is_right_tri ? cout << " is a right triangle." << endl
                 : cout << " is not a right triangle." << endl;

    // optional part - checking right triangle without using boolean vairable
    cout << "\n-----------------------------------------------------------" << endl;
    cout << "Optional: Checking right triangle without using a boolean variable.\n";
    cout << "Please type three angles: ";
    cin >> user_angle1 >> user_angle2 >> user_angle3;

    cout << "The rectangle with angles "
         << user_angle1 << " " << user_angle2 << " " << user_angle3;

    is_right_triangle(user_angle1, user_angle2, user_angle3)
        ? cout << " is a right triangle.\n"
        : cout << " is not a right triangle.\n";

    return 0;
}

/*
This function takes 3 floating point parameters for 3 angles.
It checks if the angles can be the angles of a valid right triangle.
If it is a valid right triangle, it returns true. Otherwise, false.
*/

bool is_right_triangle(float angle1, float angle2, float angle3)
{
    bool is_right_triangle = false;
    float sum_angels = angle1 + angle2 + angle3;
    if ((sum_angels == 180) && (angle1 > 0 && angle2 > 0 && angle3 > 0) && (angle1 == 90 || angle2 == 90 || angle3 == 90))
    {
        is_right_triangle = true;
    }
    return is_right_triangle;
}

/*
This function take two parameters of double data types,
calculate and return the length of the hypotenuse of the right triangle.
*/

float findHypotenuse(float leg1, float leg2)
{
    return sqrt(pow(leg1, 2) + pow(leg2, 2));
}

/*
This function takes 1 parameter, a integer called leg, and prints an isoceles right triangle using default symbol #.
*/

void show_iso_right(int leg)
{
    for (int i = 0; i < leg; i++)
    {
        for (int j = 0; j < (i + 1); j++)
        {
            cout << '#' << " ";
        }
        cout << endl;
    }
}

/*
This function takes 2 parameter, a character called symbol and a integer called leg_length and
print a right triangle using the symbol.
*/

void show_iso_right(int leg, char symbol)
{
    for (int i = 0; i < leg; i++)
    {
        for (int j = 0; j < (i + 1); j++)
        {
            cout << symbol << " ";
        }
        cout << endl;
    }
}