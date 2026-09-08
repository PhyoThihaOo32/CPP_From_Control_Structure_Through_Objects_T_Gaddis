#ifndef SEARCHABLEVECTOR_H
#define SEARCHABLEVECTOR_H

#include "SimpleVector.h"

template <class T>
class SearchableVector : public SimpleVector<T>
{
public:
    // default constructor
    SearchableVector() : SimpleVector<T>() {}

    // constructor
    SearchableVector(int size) : SimpleVector<T>(size) {}

    // copy constructor
    SearchableVector(const SearchableVector &);

    // accessor to find an item
    int findItem(const T);
};

// copy constructor

template <class T>
SearchableVector<T>::SearchableVector(const SearchableVector &obj) : SimpleVector<T>(obj.size())
{
    for (int i = 0; i < this->obj.size(); i++)
    {
        this->operator[](i) = obj[i];
    }
}

/*
1️⃣ Purpose of the Copy Constructor
This constructor creates a new SearchableVector that is an exact copy of another SearchableVector object.
It’s needed to ensure a deep copy — meaning the new object gets its own separate copy of the data in memory (not just a pointer to the same array).
2️⃣ Base-Class Initialization
: SimpleVector<T>(obj.size())
→ This part calls the base class constructor (SimpleVector) and passes it the size of obj.
That ensures memory for the internal array is allocated before copying elements.
    The loop copies each element from obj to the new vector.
    •	this->operator[](count) accesses the derived class’s array (through inheritance).
    •	obj[count] uses the overloaded [] operator from SimpleVector to get each element from the source vector.

🔍 Why this->operator[](count)?
Because operator[] is inherited from the base class template (SimpleVector<T>), and in template-derived classes, you must use this-> to tell the compiler to look for it in the base class template.
Without this->, the compiler might not find it due to dependent name lookup rules.
*/

// find item function
// This function searches for item. If item is found the subscript is returned. Otherwise -1 is returned.

template <class T>
int SearchableVector<T>::findItem(const T item)
{
    for (int count = 0; count < this->size(); count++)
    {
        if (this->getElementAt(count) == item)
        /*
        ⚙️ 'this->' required because getElementAt() is defined
        in a dependent base class template (SimpleVector<T>).
        Without it, the compiler won’t find the function.
        */
        {
            return count;
        }
    }
    return -1;
}

/*
⚠️ Important:
Use count < this->size(), not <=.
Array indices go from 0 to size - 1.
Using <= tries to access one element beyond the valid range,
causing undefined behavior.
*/

#endif