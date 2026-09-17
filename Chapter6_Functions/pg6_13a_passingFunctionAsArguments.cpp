#include <iostream>

using namespace std;

// Function prototypes
int add(int, int);
int multiply(int, int);

// Template function prototype
// calc takes:
// 1. two values of the same generic data type T
// 2. a pointer to a function that takes two T values and returns T
template <typename T>
T calc(T, T, T (*)(T, T));

int main()
{
    // Call add function directly
    cout << "Calling Add Function: "
         << add(2, 2) << endl;

    // Pass the add function as an argument to calc
    cout << "Calling Calc Function(Add): "
         << calc(2, 2, add) << endl;

    // Pass the multiply function as an argument to calc
    cout << "Calling Calc Function(Multiply): "
         << calc(2, 3, multiply) << endl;

    return 0;
}

// This function takes two integers
// and returns their sum
int add(int num1, int num2)
{
    return num1 + num2;
}

// This function takes two integers
// and returns their product
int multiply(int num1, int num2)
{
    return num1 * num2;
}

// Template calc function
// T represents a generic data type
//
// num1 and num2 are values of type T
//
// funPtr is a pointer to a function that:
// - takes two arguments of type T
// - returns a value of type T
//
// calc calls the function stored in funPtr
// and passes num1 and num2 to it
template <typename T>
T calc(T num1, T num2, T (*funPtr)(T, T))
{
    return funPtr(num1, num2);
}