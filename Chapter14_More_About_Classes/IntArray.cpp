#include "IntArray.h"
#include <iostream>
#include <cstdlib> // for exit
using namespace std;

// ======================================================
// Constructor
// Allocates memory for an array of given size and initializes to 0
// ======================================================
IntArray::IntArray(int s)
{
    if (s <= 0)
        throw invalid_argument("Array size must be positive.");

    arraySize = s;
    aptr = new int[arraySize];
    for (int i = 0; i < arraySize; i++)
        aptr[i] = 0;
}

// ======================================================
// Copy Constructor — Performs deep copy
// ======================================================
IntArray::IntArray(const IntArray &obj)
{
    arraySize = obj.arraySize;
    aptr = new int[arraySize];

    for (int i = 0; i < arraySize; i++)
        aptr[i] = obj.aptr[i];
}

// ======================================================
// Destructor — Frees allocated memory
// ======================================================
IntArray::~IntArray()
{
    delete[] aptr;
    aptr = nullptr;
    arraySize = 0;
}

// ======================================================
// Private Helper — Handles invalid subscript access
// ======================================================
void IntArray::subscriptError() const
{
    cerr << "❌ ERROR: Subscript out of range." << endl;
    exit(EXIT_FAILURE);
}

// ======================================================
// Overloaded [] Operator — Non-const version
// Returns reference so it can be used for assignment
// ======================================================
int &IntArray::operator[](int sub)
{
    if (sub < 0 || sub >= arraySize)
        subscriptError();

    return aptr[sub];
}

// ======================================================
// Overloaded [] Operator — Const version
// Used when accessing const objects
// ======================================================
const int &IntArray::operator[](int sub) const
{
    if (sub < 0 || sub >= arraySize)
        subscriptError();

    return aptr[sub];
}

// ======================================================
// Overloaded = Operator — Deep copy assignment
// Handles self-assignment safely
// ======================================================
IntArray &IntArray::operator=(const IntArray &rhs)
{
    if (this == &rhs)
        return *this; // Handle self-assignment

    // Reallocate memory if sizes differ
    if (arraySize != rhs.arraySize)
    {
        delete[] aptr;
        arraySize = rhs.arraySize;
        aptr = new int[arraySize];
    }

    // Copy data from rhs
    for (int i = 0; i < arraySize; i++)
        aptr[i] = rhs.aptr[i];

    return *this;
}