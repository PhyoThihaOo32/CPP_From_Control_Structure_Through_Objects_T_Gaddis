#ifndef QUEUELINKEDTYPE_H
#define QUEUELINKEDTYPE_H

#include "nodeType.h"
#include <cassert>

template <class Type>
class queueLinkedType : public nodeType<Type>
{
private:
    nodeType<Type> *queueFront;
    nodeType<Type> *queueRear;

    void copyQueue(const queueLinkedType<Type> &);

public:
    // overload the assignment operator
    const queueLinkedType<Type> &operator=(const queueLinkedType<Type> &);

    // function to determine whether the queue is empty
    bool isEmptyQueue() const;

    // function to determin whether the queue is full
    bool isFullQueue() const;

    // function to initialize the queue - set the queue to empty state
    void initializeQueue();

    // function to return the first element of the queue
    Type front() const;

    // function to return the last element of the queue
    Type back() const;

    // function to add the element to the queue(front)
    void addQueue(const Type &);

    // function to remove element from the queue
    void deleteQueue();

    // constructor
    queueLinkedType();

    // copy constructor
    queueLinkedType(const queueLinkedType<Type> &);

    // destructor
    ~queueLinkedType();
};

template <class Type>
void queueLinkedType<Type>::copyQueue(const queueLinkedType<Type> &other)
{
    nodeType<Type> *current, *newNode;
    // check if this queue is empty, if not initialize
    if (queueFront != nullptr)
    {
        initializeQueue();
    }

    // if the other queue is empty, then set this queue empty as well
    if (other.queueFront == nullptr)
    {
        queueFront = nullptr;
        queueRear = nullptr;
    }
    else
    {
        current = other.queueFront;

        queueFront = new nodeType<Type>;
        queueFront->info = current->info;
        queueFront->link = nullptr;
        queueRear = queueFront;
        current = current->link;
        while (current != nullptr)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = nullptr;
            queueRear->link = newNode;
            queueRear = newNode;
            current = current->link;
        }
    }
}

// constructor - set the queue to empty state - set pointers to null
template <class Type>
queueLinkedType<Type>::queueLinkedType()
{
    queueFront = nullptr;
    queueRear = nullptr;
}

// copy constructor
template <class Type>
queueLinkedType<Type>::queueLinkedType(const queueLinkedType<Type> &other)
{
    /*Initializing the pointers first is important because this is a brand-new object.
    Then copyQueue() can safely build a deep copy of other.
    */
    queueFront = nullptr;
    queueRear = nullptr;
    copyQueue(other);
}

// destructor - deletes all nodes in the queue and
// deallocates their dynamically allocated memory
template <class Type>
queueLinkedType<Type>::~queueLinkedType()
{
    initializeQueue();
}

// assignment operator
template <class Type>
const queueLinkedType<Type> &queueLinkedType<Type>::operator=(const queueLinkedType<Type> &other)
{
    // avoid self copy
    // assert(this != &other);  // self-assignment is valid - shouldn't stop the program
    if (this != &other) // so if other not equal to this
    {
        copyQueue(other); // copy other
    }
    return *this; // then skip the copy - simply return this
}

// empty queue - queue is empty if queueFront is null
template <class Type>
bool queueLinkedType<Type>::isEmptyQueue() const
{
    return (queueFront == nullptr);
}

// full queue - in linkedList implementation of queue - it will never be full (only if memeory run out)
template <class Type>
bool queueLinkedType<Type>::isFullQueue() const
{
    return false;
}

// initialize queue - set the queue to empty state
// constructor initialize the queue to empty state
// if there (might) any element in the queue - we need to delete the elements - by transversing the queue
template <class Type>
void queueLinkedType<Type>::initializeQueue()
{
    nodeType<Type> *temp; // pointer to transverse the queue
    while (queueFront != nullptr)
    { // if the queue is not empty
        temp = queueFront;
        queueFront = queueFront->link;
        delete temp;
    }
    // set queueRear to null as well
    queueRear = nullptr;
}

// addQueue - add newElement to the end of the queue
// queueRear pointer will point to the last added element
template <class Type>
void queueLinkedType<Type>::addQueue(const Type &newElement)
{
    nodeType<Type> *newNode; // pointer to new node to add to queue

    newNode = new nodeType<Type>; // allocate memory for new node
    newNode->info = newElement;   // copy newElement
    newNode->link = nullptr;

    // if the queue is empty - both queueFront and queueRear will point to newNode
    // isEmptyQueue() is clearer and usually just as efficient;
    // it internally checks whether queueFront == nullptr.
    if (isEmptyQueue()) // if(queueFront == nullptr)
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else
    {
        queueRear->link = newNode; // connect current rear to the new node
        queueRear = newNode;       // queueRear = queueRear->link
    }
}

// if the queue is non-empty- front() return the first element of the queue
template <class Type>
Type queueLinkedType<Type>::front() const
{
    assert(!isEmptyQueue());
    return queueFront->info;
}

// if the queue is non-empty - back() return the last element of the queue
template <class Type>
Type queueLinkedType<Type>::back() const
{
    assert(!isEmptyQueue());
    return queueRear->info;
}

// if the queue is non-empty - the function will delete(deallocate memory) the first element from the queue
// the advance the queueFront to next
template <class Type>
void queueLinkedType<Type>::deleteQueue()
{
    nodeType<Type> *current;
    assert(!isEmptyQueue());
    current = queueFront;
    queueFront = queueFront->link;
    delete current;

    // if there is only one element in the queue - so after deletion queueFront will point to null
    // also queueRear will still be pointing to previous element - so we must set queueRear to null as well
    if (queueFront == nullptr)
        queueRear = nullptr;
}

#endif QUEUELINKEDTYPE_H