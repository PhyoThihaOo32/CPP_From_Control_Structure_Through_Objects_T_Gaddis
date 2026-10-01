#pragma once
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "nodeType.h"

template <class Type>
class doublyLinkedList
{
protected:
    int count;             // length of the list
    nodeType<Type> *first; // pointer to the first node
    nodeType<Type> *last;  // pointer to last node
private:
    // function to make a copy of otherlist
    void copyList(const doublyLinkedList<Type> &otherList);

public:
    // CONSTRUCTOR
    // default constructor - initialize the list to empty state
    doublyLinkedList();
    // copy constructor
    doublyLinkedList(const doublyLinkedList<Type> &);
    // DESTRUCTOR
    ~doublyLinkedList();

    // overload assignment operator
    const doublyLinkedList<Type> &operator=(const doublyLinkedList<Type> &);

    // function to initialize the list to an empty state
    void initializeList();

    // function to determine whether the list is empty
    bool isEmptyList() const;

    // function to delete all the nodes from the list
    void destroy();

    // function to output the info contained in each node
    void print() const;

    // function to output the info contained in each node - in reverse order
    void reversePrint() const;

    // function to return the number of nodes in the list
    int length() const;

    // function to return the first element of the list
    Type first() const;

    // function to return the last element of the list
    Type back() const;

    // function to determine whether searchItem is in the list
    bool search(const Type &) const;

    // function to insert item in the list
    void insert(const Type &) const;

    // function to delete an item from the list
    void deleteNode(const Type &);
};

// IMPLEMENTATIONS


#endif