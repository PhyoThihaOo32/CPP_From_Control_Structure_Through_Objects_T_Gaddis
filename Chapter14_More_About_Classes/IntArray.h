#ifndef INTARRAY_H
#define INTARRAY_H

#include <stdexcept> // for std::out_of_range

class IntArray
{
private:
    int *aptr;     // Pointer to dynamically allocated array
    int arraySize; // Number of elements in the array

    // Helper function to handle invalid subscripts
    void subscriptError() const;

public:
    // --- Constructors, Destructor ---
    IntArray(int size);            // Constructor
    IntArray(const IntArray &obj); // Copy constructor (deep copy)
    ~IntArray();                   // Destructor

    // --- Accessor ---
    int size() const { return arraySize; }

    // --- Operator Overloads ---
    int &operator[](int sub);              // Non-const version
    const int &operator[](int sub) const;  // Const version
    IntArray &operator=(const IntArray &); // Assignment operator
};

#endif