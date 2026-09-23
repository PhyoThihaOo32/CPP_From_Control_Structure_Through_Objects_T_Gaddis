#pragma once
#ifndef LINKEDSTACKTYPE_H
#define LINKEDSTACKTYPE_H
#include <cassert>

#include "nodeType.h";
#include "stackADT.h";

template <class Type>
class linkedStackType : public stackADT<Type>
{
private:
    nodeType<Type> *stackTop; // pointer to the stack(top)

    void copyStack(const linkedStackType<Type> &);

public:
    // overload the asignment operator
    const linkedStackType<Type> &operator=(const linkedStackType<Type> &);

    // function to determine whether the stack is full
    bool isFullStack() const;

    // function to determin whether the stack is empty
    bool isEmptyStack() const;

    // function to initialize the stack
    void initializeStack();

    // function to add newItem to the stack
    void push(const Type &);

    // function to return newItem from the stack
    Type top() const;

    // function to remove top element from the stack
    void pop();

    // constructor
    linkedStackType();

    linkedStackType(const linkedStackType<Type> &);

    ~linkedStackType();
};

// default constructor - initialize stack to an empty stack
template <class Type>
linkedStackType<Type>::linkedStackType()
{
    stackTop = nullptr;
}

// stack is empty if the stackTop is NULL(point to nullptr)
template <class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
    return (stackTop == nullptr);
}

// stack is never full in linkedStack - only full is run out of memeory
template <class Type>
bool linkedStackType<Type>::isFullStack() const
{
    return false;
}

// initialize stack
// since stack might contain some elements and we are using a linked implementation of stack,
// we must dellocate the memory occupied by the stack elements and set stackTop to null
template <class Type>
void linkedStackType<Type>::initializeStack()
{
    nodeType<Type> *temp;

    while (stackTop != nullptr) // if there are element in the stack
    {
        temp = stackTop;           // set temp to point to top node
        stackTop = stackTop->link; // stackTop will point to the element next to top
        delete temp;               // deallocate memory occupied by temp
    }
}

// push element - add element to top of the stack
// we don't need to check if the stack is full or not - logically the stack is never full
template <class Type>
void linkedStackType<Type>::push(const Type &newItem)
{
    nodeType<Type> *newNode;      // pointer to new node
    newNode = new nodeType<Type>; // create the node

    newNode->info = newItem;  // add newItem to the node
    newNode->link = stackTop; // newNode is linked to the stackTop(top element)
    stackTop = newNode;       // stackTop point to newNode(which make newNode the top node)
}

// top - return the top element from the linkedStack
template <class Type>
Type linkedStackType<Type>::top() const
{
    assert(stackTop != nullptr);
    return stackTop->info;
}

// pop - removes the top element of the stack
template <class Type>
void linkedStackType<Type>::pop()
{
    nodeType<Type> *temp;
    assert(stackTop != nullptr);
    temp = stackTop;
    stackTop = stackTop->link;
    delete temp;
}

// copy stack
// the function makes an identical copy of the other stack
template <class Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type> &otherStack)
{
    nodeType<Type> *newNode, *current, *last;
    // initialize the stack before copy
    if (stackTop != nullptr)
    {
        initializeStack();
    }

    // if other stack is empty - then we are coping the empty stack
    if (otherStack.stackTop == nullptr)
    {
        stackTop = nullptr;
    }
    else
    {
        current = otherStack.stackTop;
        stackTop = new nodeType<Type>;
        stackTop->info = current->info;
        stackTop->link = nullptr;
        last = stackTop;
        current = current->link;
        while (current != nullptr)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

// constructor
template <class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type> &otherStack)
{
    stackTop = nullptr;
    copyStack(otherStack);
}

// destructor
template <class Type>
linkedStackType<Type>::~linkedStackType()
{
    initializeStack();
}

// overloading assignment operator
template <class Type>
const linkedStackType<Type> &linkedStackType<Type>::operator=(const linkedStackType<Type> &other)
{
    if (this != &otherStack) // to avoid self copy (stackA = stackA)
    {
        copyStack(other);
    }
    return *this;
}

#endif