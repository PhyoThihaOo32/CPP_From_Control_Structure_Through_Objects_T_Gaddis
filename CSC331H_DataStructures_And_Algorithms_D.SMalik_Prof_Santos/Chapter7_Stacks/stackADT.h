/*
Stack: A data structure in which the elements are added and removed from one end only:
Last In First Out(LIFO) data structure.
*/

#pragma once
#ifndef STACKADT_H
#define STACKADT_H

template <class Type>
class stackADT
{
public:
    // method to initialize the stack to an empty state
    virtual void initializeStack() = 0;

    // function to determine whether the stack is empty
    virtual bool isEmptyStack() const = 0;

    // function to determine whether the stack is full
    virtual bool isFullStack() const = 0;

    // function to add newItem to the stack
    virtual void push(const Type &) = 0;

    // function to return the top element of the list
    virtual Type top() const = 0;

    // function to remove the top element of the stack
    virtual void pop() = 0;
};

#endif