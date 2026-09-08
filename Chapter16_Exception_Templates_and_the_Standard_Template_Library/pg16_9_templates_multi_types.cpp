/*
This program demonstrates using a function template with multiple types.
-----------------------------------------------------------------------
• Templates can have more than one type parameter (e.g., <class T, class Y>).
• Each type parameter may represent a different data type.
• Here, the function compares the sizes (in bytes) of two variables
  and returns the size of the larger one.
*/

#include <iostream>
using namespace std;

// Function template with two different type parameters
template <class T, class Y>
int largest(const T &var1, const Y &var2)
{
    // Each type parameter (T and Y) must appear in the function definition
    // The function compares sizes using sizeof operator
    if (sizeof(var1) > sizeof(var2))
        return sizeof(var1);
    else
        return sizeof(var2);
}

int main()
{
    int i;
    char c;
    float f;
    double d;

    cout << "Comparing int and char — larger type size: "
         << largest(i, c) << " bytes." << endl;

    cout << "Comparing float and double — larger type size: "
         << largest(f, d) << " bytes." << endl;

    return 0;
}

/*
Summary:
--------
• Multiple-type templates allow flexibility with parameters of different types.
• The compiler creates a version of the function for each unique combination.
  Example:
     largest<int, char>(i, c);
     largest<float, double>(f, d);
• Demonstrates compile-time template instantiation using two type parameters.
*/