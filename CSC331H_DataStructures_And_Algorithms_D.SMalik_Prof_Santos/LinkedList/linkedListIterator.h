#ifndef LINKEDLISTITERATOR_H
#define LINKEDLISTITERATOR_H
#include "nodeType.h"

/*
A iterator is an object that produces each element of a container,
such as a linked list, one element at a time.
*/

template <class Type>
class linkedListIterator
{
private:
    nodeType<Type> *current; // pointer to current node in the list
public:
    // default constructor
    // postcondition: current = NULL;
    linkedListIterator();

    // constructor with one parameter
    // postcondition: current = ptr
    linkedListIterator(nodeType<Type> *ptr);

    // function to overload the dereferencing operator*
    // return the info contained in the node
    Type operator*() const;

    // overload the pre-increment operator
    // the iterator is advanced to next node
    linkedListIterator<Type> &operator++();

    // overload the equality operator
    bool operator==(const linkedListIterator<Type> &right) const;

    // overload the not equal operator
    bool operator!=(const linkedListIterator<Type> &right) const;
};

// implementations

template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = nullptr;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr)
{
    current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*() const
{
    // we are dereferancing the value of the node the ite current pointer is pointing to
    return current->info;
}

template <class Type>
linkedListIterator<Type> &linkedListIterator<Type>::operator++()
{
    current = current->link;
    return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type> &right) const
{
    return current == right.current;
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type> &right) const
{
    return (current != right.current);
}

#endif