/*
A queue is a set of elements of the same type in which the elements are added at one end,
called the back or rear, and deleted from the other end, called the front.

The rear of the queue is accessed whenever a new element is added to the queue, and
the front of the queue is accessed whenever an element is deleted from the queue.

A queue is a First In First Out data structure.
*/

#ifndef QUEUEADT_H
#define QUEUEADT_H

template <class Type>
class queueADT
{
public:
    // function to determine whether the queue is empty
    virtual bool isEmptyQueue() const = 0;

    // function to determin whether the queue is full
    virtual bool isFullQueue() const = 0;

    // function to initialize the queue to empty state
    virtual void initializeQueue() = 0;

    // function to return the first element of the queue
    virtual Type front() const = 0;

    // function to return the last element of the queue
    virtual Type back() const = 0;

    // function to add queueElement to the queue
    virtual void addQueue(const Type &queueElement) = 0;

    // function to remove the first element of the queue
    virtual void deleteQueue() = 0;
};

#endif