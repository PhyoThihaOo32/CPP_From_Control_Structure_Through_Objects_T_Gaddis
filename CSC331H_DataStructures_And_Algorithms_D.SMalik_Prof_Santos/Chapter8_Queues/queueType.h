#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include "queueADT.h"
#include <cassert>
#include <iostream>

using namespace std;

template <class Type>
class queueType : public queueADT<Type>
{
private:
    int queueFront;   // index of first element of the queue
    int queueRear;    // index of last element of the queue
    int maxQueueSize; // max queue size
    int count;        // number of element in the queue
    Type *list;       // pointer to the queue Type
    void copyQueue(const queueType<Type> &);

public:
    // overload the assignment operator
    const queueType<Type> &operator=(const queueType<Type> &);

    // function to determine the queue is empty
    bool isEmptyQueue() const;

    // function to determine the queue is full
    bool isFullQueue() const;

    // function to initialize the queue to an empty state
    void initializeQueue();

    // function to return the first element of the queue
    Type front() const;

    // function to return the last element of the queue
    Type back() const;

    // function to add queueElement to the queue
    void addQueue(const Type &);

    // function to delete element from the queue
    void deleteQueue();

    // constructor
    queueType(int queueSize = 100);

    // copy constructor
    queueType(const queueType<Type> &);

    // destructor
    ~queueType();
};

// copy queue
template <class Type>
void queueType<Type>::copyQueue(const queueType<Type> &otherQueue)
{

    // avoid self copy
    if (this == &otherQueue)
    {
        return;
    }

    maxQueueSize = otherQueue.maxQueueSize;
    count = otherQueue.count;
    queueFront = otherQueue.queueFront;
    queueRear = otherQueue.queueRear;

    int current = queueFront; // temp index to transverse the queue

    delete[] list; // first deallocate the memory
    list = new Type[maxQueueSize];

    // then copy each element from other queue
    for (int i = 0; i < count; i++)
    {
        list[current] = otherQueue.list[current];
        current = (current + 1) % maxQueueSize;
    }
}

// assignment operator
template <class Type>
const queueType<Type> &queueType<Type>::operator=(const queueType<Type> &otherQueue)
{
    // check self copy
    copyQueue(otherQueue);
    return *this;
}

// empty queue
template <class Type>
bool queueType<Type>::isEmptyQueue() const
{
    return count == 0; // if there is no element in the queue, then queue is empty
}

// full queue
template <class Type>
bool queueType<Type>::isFullQueue() const
{
    return count == maxQueueSize; // the count == max size, then queue is full
}

// initialize queue to empty state
// queueFront to 0 and queueRear to maxSize - 1
template <class Type>
void queueType<Type>::initializeQueue()
{
    queueFront = 0;
    queueRear = maxQueueSize - 1;
    count = 0;
}

// front - return the first element of the queue
template <class Type>
Type queueType<Type>::front() const
{
    assert(!isEmptyQueue());
    return list[queueFront];
}

// back - return the last element of the queue
template <class Type>
Type queueType<Type>::back() const
{
    assert(!isEmptyQueue());
    return list[queueRear];
}

// add queue - advance queueRear by one in the circular array(that is % by maxSize)
// and add the element
template <class Type>
void queueType<Type>::addQueue(const Type &newElement)
{
    if (!isFullQueue())
    {
        queueRear = (queueRear + 1) % maxQueueSize; // advance 1 then round (% maxSize) -> circular array
        list[queueRear] = newElement;
        count++; // increse number of element by one
    }
    else
    {
        cout << "Cannot add to the full queue." << endl;
    }
}

// delete queue - access from the front
// advance front to next element(but round inside the circular array - % maxSize) - decrease the number of element by one
template <class Type>
void queueType<Type>::deleteQueue()
{
    if (!isEmptyQueue())
    {
        queueFront = (queueFront + 1) % maxQueueSize;
        count--;
    }
    else
    {
        cout << "Cannot remove from an empty queue" << endl;
    }
}

// constructor - default array size is 100
template <class Type>
queueType<Type>::queueType(int queueSize)
{
    if (queueSize <= 0)
    {
        cout << "Size of the array to hold the queue must "
             << " be positive." << endl;
        cout << "Creating an array of size 100." << endl;
        maxQueueSize = 100;
    }
    else
    {
        maxQueueSize = queueSize;
    }

    queueRear = maxQueueSize - 1;
    queueFront = 0;
    count = 0;
    list = new Type[maxQueueSize];
}

// copy constructor
template <class Type>
queueType<Type>::queueType(const queueType<Type> &otherQueue)
{
    // make sure list list point to nul
    list = nullptr;
    copyQueue(otherQueue);
}

// destructur - remember to dellocate the memory
template <class Type>
queueType<Type>::~queueType()
{
    delete[] list; // because we allocate array of objects
                   // delete[] tells C++:
                   // this pointer points to an array, so destroy all array elements correctly and release the whole allocation.
}

#endif