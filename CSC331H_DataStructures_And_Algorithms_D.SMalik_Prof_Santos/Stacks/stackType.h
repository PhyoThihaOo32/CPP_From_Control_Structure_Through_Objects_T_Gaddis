/*
Implementation of stack as array

Array is a random access data structure: that is, you can directly access any element of the
array.
A stack is a data structure in which the elements are accessed at only one end(from top)- LIFO.
Thus, stack element is accessed only through the top, not through the bottom or middle.
*/

#pragma once
#ifndef STACKTYPE_H
#define STACKTYPE_H

#include "stackADT.h"
#include <iostream>
#include <cassert>

using namespace std;

template <class Type>
class stackType : public stackADT<Type>
{
private:
    int maxStackSize; // the maxium size of array
    int stackTop;     // to point to the top of the list
    Type *list;       // pointer to array that hold stack elements

    // function to make a copy of otherStack
    void copyStack(const stackType<Type> &otherStack);

public:
    // overload the assignment operator
    const stackType<Type> &operator=(const stackType<Type> &);

    // function to initialize the stack to an empty state
    void initializeStack();

    // function to determine whether the stack is empty
    bool isEmptyStack() const;

    // function to determine whether the stack is full
    bool isFullStack() const;

    // function to add newItem to the stack
    void push(const Type &);

    // function to return the top element of the stack
    Type top() const;

    // function to remove the top element of the stack
    void pop();

    // constructor
    // create an array of the size stackSize to hold
    // the stack elements. The default stack size is 100.
    stackType(int stackSize = 100);

    // copy constructor
    stackType(const stackType<Type> &);

    // ~destructor
    // remove all the elements from the stack
    ~stackType();
};

/*
Initialize Stack - Because the value of stackTop indicates whether the stack is empty
we can simply set stackTop to 0 to initialize the stack.
*/
template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}

/*
Empty Stack: If stackTop is 0, then the stack is empty.
*/
template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    return (stackTop == 0);
}

/*
Full Stack - if the stackTop is same as maxStackSize of the stack, then the stack is full
*/
template <class Type>
bool stackType<Type>::isFullStack() const
{
    return (stackTop == maxStackSize);
}

/*
Push: stackTop - the number of elements in the stack
      stackTop - 1 - the position of top element in the stack
1. check if the stack is Full
2. store the newItem in the array indicated by the stackTop
3. increase the stackTop
*/
template <class Type>
void stackType<Type>::push(const Type &newItem)
{
    if (!isFullStack())
    {
        list[stackTop] = newItem;
        stackTop++;
    }
    else
    {
        cout << "Cannot add to a full stack" << endl;
    }
}

/*
Return the top element - list[stackTop - 1] return the top element from the stack
*/
template <class Type>
Type stackType<Type>::top() const
{
    // first make sure if the stack is not an empty stack
    assert(stackTop != 0);
    return list[stackTop - 1];
}

/*
Pop: remove or pop element from the stack - we simply decrement the stackTop by 1
*/
template <class Type>
void stackType<Type>::pop()
{
    if (!isEmptyStack())
    {
        stackTop--;
    }
    else
    {
        cout << "Cannot remove from an empty stack." << endl;
    }
}

/*
Copy Stack: to make a copy of the stack
- the stack to be copied is passed as argument to the function
*/
template <class Type>
void stackType<Type>::copyStack(const stackType<Type> &otherStack)
{
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;

    delete[] list;                 // deallocate the current dynamic array
    list = new Type[maxStackSize]; // allocate a new dynamic array using the copied maxStackSize

    // copy each element from otherStack into this stack
    for (int i = 0; i < maxStackSize; i++)
    {
        list[i] = otherStack.list[i];
    }
}

/*
Constructor

Takes size as an argument, sets maxStackSize, and dynamically allocates
an array of generic Type. stackTop is initialized to 0.

If size is less than or equal to 0, print an error message
and use the default size of 100.
*/
template <class Type>
stackType<Type>::stackType(int size)
{
    if (size <= 0)
    {
        cout << "Size of array to hold the stack must be positive."
             << endl;
        cout << "Creating an array of size 100." << endl;
        maxStackSize = 100; // default size to 100
    }
    else
    {
        maxStackSize = size;
    }
    stackTop = 0;
    list = new Type[maxStackSize];
}

/*
Destructor - deallocates the dynamic array allocated for the stack.
No need to reset stackTop or maxStackSize because the entire object
is being destroyed.
*/
template <class Type>
stackType<Type>::~stackType()
{
    delete[] list;
}

/*
Copy Constructor: is called when stack object is passed as argument to the function.
*/
template <class Type>
stackType<Type>::stackType(const stackType<Type> &otherStack)
{
    list = nullptr;
    copyStack(otherStack);
}

/*
Overloading Assignment Operator
*/
template <class Type>
const stackType<Type> &stackType<Type>::operator=(const stackType<Type> &otherStack)
{
    /*
Self-assignment check:

`this` is a pointer to the current object on the left side of the assignment.

`&otherStack` is the address of the object on the right side of the assignment.

If both addresses are the same, then both names refer to the same stack object.

In that case, calling copyStack() would be dangerous because copyStack()
first deletes the current dynamic array:

    delete[] list;

But if both objects are the same, otherStack.list refers to that same array.

After deleting it, the function would then try to copy data from memory
that has already been deallocated.

Therefore, only call copyStack() when the two objects are different.
*/
    if (this != &otherStack) // avoid self copy
        copyStack(otherStack);
    return *this;
}

#endif

/*
========================================================
UNINITIALIZED VARIABLES AND POINTERS
========================================================

1. Uninitialized variables
--------------------------
A local variable that is declared but not given a value is not
automatically 0, empty, or null.

Example:

int number;

At this point, number has an indeterminate value.

Do not assume:

number == 0

because it has not been initialized.

Better:

int number = 0;


========================================================
2. Uninitialized pointers
========================================================

A pointer is also a variable.

Example:

int *ptr;

ptr has not been initialized.

It is NOT automatically:

ptr = nullptr;

It contains an indeterminate pointer value.

Conceptually:

ptr
 |
 v
???

The pointer does not safely point to a valid object.


========================================================
3. Why an uninitialized pointer is dangerous
========================================================

Suppose:

int *ptr;

Then doing:

delete ptr;

is unsafe.

delete assumes that ptr is either:

1. nullptr

or

2. pointing to dynamic memory that was previously allocated
   using new

Example of valid ownership:

int *ptr = new int;

ptr
 |
 v
+------+
| int  |   dynamic memory
+------+

delete ptr;

This is valid because ptr points to memory created by new.


========================================================
4. delete nullptr is safe
========================================================

This is completely safe:

int *ptr = nullptr;

delete ptr;

Nothing is deallocated because ptr points to nothing.

So initializing a pointer to nullptr gives it a known and safe state.

Example:

int *ptr = nullptr;

Later:

ptr = new int;

Then:

delete ptr;
ptr = nullptr;


========================================================
5. Why we initialize list = nullptr in a copy constructor
========================================================

Example:

stackType<Type>::stackType(const stackType<Type> &otherStack)
{
    list = nullptr;
    copyStack(otherStack);
}

Suppose copyStack contains:

delete[] list;

If list was never initialized:

list -> ???

then:

delete[] list;

would attempt to deallocate an unknown memory location.

That causes undefined behavior.


By doing:

list = nullptr;

first:

list
 |
 v
nullptr

then:

delete[] list;

is safe and simply does nothing.

After that:

list = new Type[maxStackSize];

allocates valid dynamic memory.


========================================================
6. Example with 100 uninitialized pointers
========================================================

int *ptrs[100];

This creates an array containing 100 pointer variables.

It does NOT create 100 integers.

Conceptually:

ptrs[0]  -> ???
ptrs[1]  -> ???
ptrs[2]  -> ???
...
ptrs[99] -> ???

Each pointer has an indeterminate value.


Doing this is unsafe:

for (int i = 0; i < 100; i++)
{
    delete ptrs[i];
}

The program is trying to delete memory that it may not own.

Possible results include:

- program crash
- corrupted memory
- unexpected behavior
- program appearing to work temporarily
- errors occurring later in unrelated code

This is called undefined behavior.


========================================================
7. Safely initialize an array of pointers
========================================================

One option:

int *ptrs[100] = {};

This initializes every pointer to nullptr.

Conceptually:

ptrs[0]  -> nullptr
ptrs[1]  -> nullptr
ptrs[2]  -> nullptr
...
ptrs[99] -> nullptr

Now this is safe:

for (int i = 0; i < 100; i++)
{
    delete ptrs[i];
}

because deleting nullptr is safe.


Another option:

int *ptrs[100];

for (int i = 0; i < 100; i++)
{
    ptrs[i] = nullptr;
}


========================================================
8. Allocating objects later
========================================================

After initialization:

int *ptrs[100] = {};

we can allocate memory for selected elements:

ptrs[0] = new int;
ptrs[1] = new int;
ptrs[2] = new int;

Now:

ptrs[0] -> valid dynamically allocated int
ptrs[1] -> valid dynamically allocated int
ptrs[2] -> valid dynamically allocated int
ptrs[3] -> nullptr
...
ptrs[99] -> nullptr


========================================================
9. Safe cleanup
========================================================

for (int i = 0; i < 100; i++)
{
    delete ptrs[i];
    ptrs[i] = nullptr;
}

For pointers that contain nullptr:

delete nullptr;

does nothing.

For pointers that point to dynamically allocated integers:

delete ptrs[i];

releases that dynamic memory.


========================================================
10. delete vs delete[]
========================================================

The type of delete must match how the memory was allocated.

Single object:

int *ptr = new int;

delete ptr;


Dynamic array:

int *ptr = new int[100];

delete[] ptr;


Remember:

new        -> delete

new[]      -> delete[]


========================================================
11. Pointer variable vs memory it points to
========================================================

These are two different things:

int *ptr = new int;

Stack/local memory:

ptr
+----------------+
| address        |
+----------------+
        |
        v

Heap/dynamic memory:

+----------------+
| int object     |
+----------------+


When we do:

delete ptr;

the dynamic int is destroyed and its memory is released.

The pointer variable ptr itself still exists until its scope ends.

After delete:

ptr still contains the old address,
but that address is no longer valid to use.

Therefore it is common to do:

delete ptr;
ptr = nullptr;


========================================================
12. Dangling pointer
========================================================

Example:

int *ptr = new int;

delete ptr;

At this moment, ptr still contains the old address.

Conceptually:

ptr
 |
 v
X   memory is no longer valid

This is called a dangling pointer.

Using:

*ptr

after delete is invalid.

Setting:

ptr = nullptr;

removes that dangling address.


========================================================
13. Important rule about initialization
========================================================

Do not think:

"uninitialized means empty."

Instead think:

"uninitialized means I have not given this variable
a known usable value."


Examples:

int x;          // indeterminate value

int *ptr;       // indeterminate pointer value


Safer:

int x = 0;

int *ptr = nullptr;


========================================================
14. Important rule about delete
========================================================

Only use delete when the pointer is:

1. nullptr

OR

2. pointing to memory allocated using matching new


Safe:

int *ptr = nullptr;
delete ptr;


Safe:

int *ptr = new int;
delete ptr;


Unsafe:

int *ptr;
delete ptr;


========================================================
15. Relation to the stack copy constructor
========================================================

Copy constructor:

stackType<Type>::stackType(const stackType<Type> &otherStack)
{
    list = nullptr;
    copyStack(otherStack);
}

copyStack:

void stackType<Type>::copyStack(
    const stackType<Type> &otherStack)
{
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;

    delete[] list;

    list = new Type[maxStackSize];

    for (int i = 0; i < stackTop; i++)
    {
        list[i] = otherStack.list[i];
    }
}


Why list = nullptr first?

Because this is a brand-new object.

Its list pointer does not yet point to an allocated array.

Setting:

list = nullptr;

creates a known safe starting state.

Then:

delete[] list;

is harmless.

Then:

list = new Type[maxStackSize];

allocates the new array needed for the copied stack.


========================================================
SUMMARY
========================================================

Uninitialized variable:
    has no known usable value

Uninitialized pointer:
    does not safely point to valid memory

nullptr:
    intentionally points to nothing

new:
    allocates dynamic memory

delete:
    deallocates one dynamically allocated object

new[]:
    allocates a dynamic array

delete[]:
    deallocates a dynamic array

dangling pointer:
    pointer still contains the address of memory
    that has already been deallocated

Best practice:
    initialize pointers when they are created

Example:

Type *ptr = nullptr;
*/