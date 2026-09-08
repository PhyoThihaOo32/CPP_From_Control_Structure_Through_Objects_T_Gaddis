// SimpleVector Class template

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <new> // for bad_alloc exception
#include <cstdlib>

using namespace std;

template <class T>
class SimpleVector
{
private:
    T *aptr; // to point to allocated array
    int arraySize;
    void memError();
    void subError();

public:
    // default constructor
    SimpleVector()
    {
        aptr = nullptr;
        arraySize = 0;
        /*
        This line sets the pointer aptr to nullptr (or 0, which is an older equivalent).
        It means:
        “Right now, this object doesn’t point to any valid memory.”
        This is safe initialization — so the pointer doesn’t accidentally point to garbage memory.
        */
    }

    // constructor declaration
    SimpleVector(int);
    SimpleVector(int, T);

    // copy constructor declaration
    SimpleVector(const SimpleVector &);

    // destructor declaration
    ~SimpleVector();

    // accessor function
    int size() const { return arraySize; }

    T getElementAt(int);

    // overloaded []operator declaration
    T &operator[](const int &);
};

// constructor for simple vector class
// set the size of the array and allocate the memory for it
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    arraySize = s;
    try
    {
        aptr = new T[arraySize];
    }
    catch (bad_alloc)
    {
        /*
        When the new operator fails to allocate memory,
        it throws an exception of type std::bad_alloc.
        */
        memError();
    }

    // initialize the array
    for (int i = 0; i < arraySize; i++)
    {
        *(aptr + i) = 0;
    }
}

// Constructor for SimpleVector
// ----------------------------
// • Allocates dynamic memory for 'size' elements.
// • Initializes each element to the specified 'value'.
// • Uses exception handling to catch memory allocation errors.

template <class T>
SimpleVector<T>::SimpleVector(int size, T value)
{
    arraySize = size;
    try
    {
        aptr = new T[arraySize];
    }
    catch (bad_alloc)
    {
        memError();
    }
    for (int i = 0; i < arraySize; i++)
    {
        *(aptr + i) = value;
    }
}

// copy constructor for simple vector class
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    // copy the array size
    arraySize = obj.arraySize;

    aptr = new T[arraySize];
    if (aptr == 0)
    /*
    ✅ Purpose:
    This line checks if memory allocation failed.
    If new returns 0 (meaning it couldn’t allocate memory), then memError() is called.
    ⸻
    ⚠️ However — Important Note:
    In modern C++, new never returns 0 on failure.
    It throws a std::bad_alloc exception instead
    */
    {
        memError();
    }

    // copy the element of the obj array
    for (int i = 0; i < arraySize; i++)
    {
        *(aptr + i) = *(obj.aptr + i);
    }
}

// destructor for simple vector class
template <class T>
SimpleVector<T>::~SimpleVector()
{
    if (arraySize > 0)
    {
        delete[] aptr;
    }
}

// memError function. Displays an error message and terminates the program when memory allocation fails
template <class T>
void SimpleVector<T>::memError()
{
    cout << "ERROR: Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

// subError function. Displays an error message and terminates the program when a subscript is out of range
template <class T>
void SimpleVector<T>::subError()
{
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

// getElementAt function. The argument is a subscript.
// This function returns the value stored at the subcript in the array.

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
    if (sub < 0 || sub >= arraySize)
    {
        subError();
    }
    return aptr[sub];
}

// overloaded [] operator. The argument is a subscript.
// This function return a reference to the element in the array indexed by the subscript.
template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
    if (sub < 0 || sub >= arraySize)
    {
        subError();
    }
    return *(aptr + sub);
}

/*
💡 Takeaway: Difference between `int sub` and `const int& sub`

1️⃣ `int sub`
   • Passed **by value** — the function gets a **copy** of the argument.
   • Any change inside the function does not affect the original variable.
   • Copying an int is cheap, so this is perfectly fine for small built-in types.
   • Example: Used in getElementAt(int sub) since we only need to read a simple value.

2️⃣ `const int& sub`
   • Passed **by reference**, but marked as **const**, so it cannot be modified.
   • No copy is made — the function refers directly to the original variable.
   • Saves copying overhead when used with larger or complex types (e.g., objects).
   • Adds safety: prevents accidental modification of the argument.
   • Example: Used in operator[](const int& sub) for flexibility and generality.

✅ Summary:
   - For small types like int → either version works the same.
   - `const int&` is a best practice for templates or overloaded functions,
     because it avoids unnecessary copying and ensures the argument is read-only.
*/

/*
💡 Why returning a reference (T&) here is safe:
----------------------------------------------

T& SimpleVector<T>::operator[](const int& sub)
{
    // Return a reference to an element in the internal array (aptr)
    return aptr[sub];
}

🧠 Key idea:
- `aptr` points to a dynamically allocated array stored on the **heap**.
- Elements of that array persist for the entire lifetime of the SimpleVector object.
- So returning `aptr[sub]` by reference is safe — it refers to a real element in memory,
  not a temporary variable.

⚠️ It would be unsafe ONLY if we returned a reference to a **local (stack) variable**
   that disappears after the function ends.

Example (unsafe):
-----------------
int& badFunc() {
    int x = 10;   // local variable on stack
    return x;     // ❌ BAD — x is destroyed after the function ends
}

✅ But here, `aptr[sub]` is in heap memory that belongs to the object,
   so it remains valid until the SimpleVector object is destroyed.
*/

#endif