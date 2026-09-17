/*
This class specifies the members to implement the basic
properties of a linked list. This is an abstract class.
We cannot instantiate an object of this class.
*/

#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H

#include <iostream>
#include <cassert>
#include "nodeType.h"
#include "linkedListIterator.h"

using namespace std;

template <class Type>
class linkedListType
{
private:
    // function to make copy of the other list
    // postcondition: a copy of otherList is created and assigned to this list
    void copyList(const linkedListType<Type> &otherList);

protected:
    /*
    The instance variables first and last, as defined earlier, of the class linkedListType
are protected, not private,we will derive the classes unorderedLinkedList and orderedLinkedList
from the class linkedListType.
*/
    int count;             // variable to store the number of list elements
    nodeType<Type> *first; // pointer to the first node of the list
    nodeType<Type> *last;  // pointer to the last node of the list
public:
    // overload the assignment operator
    const linkedListType<Type> &operator=(const linkedListType<Type> &);

    // Initialize the list to an empty state
    // postcondition: first = NULL, last = NULL, count = 0
    void initializeList();

    // Function to determine whether the list is empty
    // Postcondition: returns true if the list is empty, otherwise it returns false
    bool isEmptyList() const;

    // Function to output the data contained in each node
    // postcondition: none
    void print() const;

    // Function to return the number of nodes in the list
    // postcondition: the value of count is returned
    int length() const;

    // Function to delete all the nodes from the list
    // postcondition: first = NULL, last = NULL, count = 0
    void destroyList();

    // Function to return the first element of the list
    // precondition: the list must exist and must not be empty
    // postcondition: if the list is empty, the program terminates;
    // otherwise, the first element of the list is returned
    Type front() const;

    // Function to return the last element of the list.
    // Precondition: The list must exist and must not be empty.
    // Postcondition: If the list is empty, the program
    //  terminates; otherwise, the last
    //  element of the list is returned.
    Type back() const;

    // Function to determin whether searchItem is in the list
    // postcondition: returns true if searchItem is in the list
    // otherwise return false
    virtual bool search(const Type &searchItem) const = 0;

    // Function to insert newItem at the begining of the list
    // postcondition: first points to the new list, newItem is inserted at the
    // beginning of the list, last points to the last node in the list, and
    // count is incremented by 1
    virtual void insertFirst(const Type &newItem) = 0;

    // Function to insert newItem at the end of the list.
    // postcondition: first points to the new list, newItem is inserted at the
    // end of the list, last points to the last node in the list, and count is
    // incremented by 1.
    virtual void insertLast(const Type &newItem) = 0;

    // Functin to delete delete Item from the list
    // postcondition: If found, the node containing deleteItem is deleted from the list.
    // first points to the first node, last points to the last node of the
    // updated list, and count is decremented by 1.
    virtual void deleteNode(const Type &deleteItem) = 0;

    // Function to return an iterator at the beginning of the linked list.
    // postcondition: returns an iterator such that current is set to first.
    linkedListIterator<Type> begin();

    // Function to return an iterator one element past the last element of the
    // linked list.
    // postcondition: returns an iterator such that current is set to NULL
    linkedListIterator<Type> end();

    // default constructor
    // Initializes the list to an empty state.
    // postcondition: first = NULL, last = NULL, count = 0
    linkedListType();

    // copy constructor
    linkedListType(const linkedListType<Type> &otherList);

    // destructor
    // deletes all the nodes from the list
    // postcondition: the list object is destroyed
    ~linkedListType();
};

// implementations

// overload the assignment operator
/*
const   -> don't modify through the returned reference
&       -> return the same object, don't make a copy
*this   -> the current object itself
*/
template <class Type>
const linkedListType<Type> &linkedListType<Type>::operator=(const linkedListType<Type> &otherList)
{
    if (this != &otherList)
    { // avoid self copy
        copyList(otherList);
    }
    return *this;
}

// Initialize the list
/*
The function initializeList initializes the list to an empty state. Note that the default
constructor or the copy constructor has already initialized the list when the list object was
declared. This operation, in fact, reinitializes the list to an empty state, and so it must delete
the nodes (if any) from the list. This task can be accomplished by using the destroyList
operation, which also resets the pointers first and last to NULL and sets count to 0.
*/
template <class Type> // O(n)
void linkedListType<Type>::initializeList()
{
    destroyList(); // if the list has any nodes, delete them
}

// The list is empty if first is NULL.
template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return first == NULL;
}

/*
The member function print prints the data contained in each node. To print the data
contained in each node, we must traverse the list starting at the first node. Because the
pointer first always points to the first node in the list, we need another pointer to
traverse the list. (If we use first to traverse the list, the entire list will be lost.)
*/
template <class Type> // O(n)
void linkedListType<Type>::print() const
{
    nodeType<Type> *current; // pointer to tranverse the list
    current = first;         // set the current to tranvese the list
    while (current != NULL)
    {
        cout << current->info << " ";
        current = current->link;
    }
}

/*
The length of a linked list (that is, how many nodes are in the list) is stored in the variable
count. Therefore, this function returns the value of this variable
*/
template <class Type>
int linkedListType<Type>::length() const
{
    return count;
}

/*
The function destroyList deallocates the memory occupied by each node. We traverse
the list starting from the first node and deallocate the memory by calling the operator
delete. We need a temporary pointer to deallocate the memory. Once the entire list is
destroyed, we must set the pointers first and last to NULL and count to 0.
*/

template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp; // pointer to deallocate the memory occupied by the node
    while (first != NULL)
    {                        // while there are nodes in the list
        temp = first;        // set temp to the current node(first)
        first = first->link; // advance first to the next node
        delete temp;         // deallocate the memory occupied by temp
    }

    last = NULL; // initialize last to NULL; first has already been set to NULL by the while loop
    count = 0;
}

// retrieve the data of the first node
/*
The function front returns the info contained in the first node, and its definition is
straightforward.
*/
template <class Type>
Type linkedListType<Type>::front() const
{
    assert(first != NULL); // if the list is empty, the assert statement terminates the program.
    return first->info;    // return the info of the first node
}

/*
The function back returns the info contained in the last node.
*/
template <class Type> // O(1)
Type linkedListType<Type>::back() const
{
    assert(last != NULL);
    return last->info;
}

/*
The function begin returns an iterator to the first node in the linked list.
*/
template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);
    return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(NULL);
    return temp;
}

/*
end() represents the position AFTER the last node,
not the last node itself.

In a singly linked list:

[10] -> [20] -> [30] -> nullptr
                         ^
                         |
                        end

So end() uses NULL/nullptr because the link after
the last node is NULL.

This allows iterator loops to stop after processing
the actual last node.

begin() -> first node
end()   -> one position past the last node -> nullptr
*/

// constructors and destructors
/*
The default constructor, linkedListType, is quite straightforward. It simply initializes
the list to an empty state.
*/
template <class Type>
linkedListType<Type>::linkedListType()
{
    first = NULL;
    last = NULL;
    count = 0;
}

/*
The destructor deallocates the memory occupied by the nodes of a list when the class
object goes out of scope. Because memory is allocated dynamically, resetting the pointers
first and last does not deallocate the memory occupied by the nodes in the list. We
must traverse the list, starting at the first node, and delete each node in the list.
*/
template <class Type>
linkedListType<Type>::~linkedListType()
{
    destroyList();
}

// copy constructor
// the class linkedListType contains pointer data members, the definition of
// this class contains the copy constructor.
template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type> &otherList)
{
    /*
    Because the function copyList checks whether the
original is empty by checking the value of first, we must first initialize the pointer
first to NULL before calling the function copyList.
    */
    first = NULL;
    copyList(otherList);
}

// copy the list
/*
The function copyList makes an identical copy of a linked list. Therefore, we traverse
the list to be copied starting at the first node. Corresponding to each node in the original
list, we do the following:
1. Create a node and call it newNode.
2. 3. Copy the info of the node (in the original list) into newNode.
Insert newNode at the end of the list being created.
*/
template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type> &otherList)
{
    nodeType<Type> *newNode; // pointer to create a node
    nodeType<Type> *current; // pointer to traverse the list

    if (first != NULL) // if the list if not empty, make it empty
        destroyList();
    if (otherList.first == NULL)
    { // if otherList is empty
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = otherList.first; // current points to the list to be copied
        count = otherList.count;

        // copy the first node
        first = new nodeType<Type>;  // create the node
        first->info = current->info; // copy the info
        first->link = NULL;          // set the link field of the node to NULL
        last = first;                // make the last point to the first node
        current = current->link;     // make the current point to the next node

        while (current != NULL)
        {
            newNode = new nodeType<Type>;  // create a node
            newNode->info = current->info; // copy the info
            newNode->link = NULL;
            last->link = newNode; // attach newNode after last
            last = newNode;       // make last point to the acutal last node
            current = current->link;
        }
    }
}

#endif

/*
========================================================
VISUAL EXPLANATION OF copyList()
========================================================

Purpose:
copyList() creates a completely separate copy of another linked list.

The original list and the copied list will contain the same data,
but their nodes will be stored at different memory addresses.

Example original list:

otherList.first
      |
      v
    [10 | *] ---> [20 | *] ---> [30 | NULL]
                                      ^
                                      |
                               otherList.last


We want to create:

first
  |
  v
[10 | *] ---> [20 | *] ---> [30 | NULL]
                                  ^
                                  |
                                 last


IMPORTANT POINTERS:

current
    - moves through the ORIGINAL list
    - used to read the data that needs to be copied

newNode
    - points to each newly created node
    - used to build the NEW list

first
    - points to the first node of the NEW list

last
    - always points to the last node of the NEW list


--------------------------------------------------------
STEP 1: Point current to the original list
--------------------------------------------------------

current = otherList.first;

Original list:

       current
          |
          v
        [10] ---> [20] ---> [30] ---> NULL


--------------------------------------------------------
STEP 2: Create the first node of the copied list
--------------------------------------------------------

first = new nodeType<Type>;

Now a new node exists:

Original:

       current
          |
          v
        [10] ---> [20] ---> [30]


Copied list:

first
  |
  v
[ ? ]


Copy the data:

first->info = current->info;

Copied list:

first
  |
  v
[10]


Set its link to NULL:

first->link = NULL;

first
  |
  v
[10] ---> NULL


Because there is only one node so far,
it is both the first node and the last node:

last = first;

      first
        |
        v
      [10] ---> NULL
        ^
        |
       last


--------------------------------------------------------
STEP 3: Move current to the next ORIGINAL node
--------------------------------------------------------

current = current->link;

Original:

                  current
                     |
                     v
        [10] ---> [20] ---> [30] ---> NULL


Copied:

first
  |
  v
[10] ---> NULL
  ^
  |
 last


--------------------------------------------------------
STEP 4: Create a new node for 20
--------------------------------------------------------

newNode = new nodeType<Type>;

newNode
   |
   v
[ ? ]


Copy the value from current:

newNode->info = current->info;

newNode
   |
   v
[20]


Set its link to NULL:

newNode->link = NULL;

newNode
   |
   v
[20] ---> NULL


--------------------------------------------------------
STEP 5: CONNECT newNode to the copied list
--------------------------------------------------------

last->link = newNode;

Before:

first
  |
  v
[10] ---> NULL
  ^
  |
 last

newNode
   |
   v
[20] ---> NULL


After:

first
  |
  v
[10] ---> [20] ---> NULL
  ^          ^
  |          |
 last      newNode


IMPORTANT:
last still points to 10 at this moment.

So we now move last:

last = newNode;

Now:

first
  |
  v
[10] ---> [20] ---> NULL
            ^
            |
           last


--------------------------------------------------------
WHY WE NEED BOTH OF THESE LINES:
--------------------------------------------------------

last->link = newNode;
last = newNode;


1. last->link = newNode;

   CONNECTS the old last node to the new node.

   [10] ---> [20]


2. last = newNode;

   MOVES the last pointer so it points to the new last node.

   [10] ---> [20]
              ^
              |
             last


If we ONLY wrote:

last = newNode;

we would get:

first
  |
  v
[10] ---> NULL


[20] ---> NULL
  ^
  |
 last


The new node exists, but it is NOT connected to the list.

Traversal from first would still stop at 10.


--------------------------------------------------------
STEP 6: Move current again
--------------------------------------------------------

current = current->link;

Original:

                            current
                               |
                               v
        [10] ---> [20] ---> [30] ---> NULL


Copied:

first
  |
  v
[10] ---> [20] ---> NULL
            ^
            |
           last


The while loop repeats.


--------------------------------------------------------
STEP 7: Copy 30
--------------------------------------------------------

Create:

newNode
   |
   v
[30] ---> NULL


Connect it:

last->link = newNode;


Copied list becomes:

first
  |
  v
[10] ---> [20] ---> [30] ---> NULL


Move last:

last = newNode;


Now:

first
  |
  v
[10] ---> [20] ---> [30] ---> NULL
                      ^
                      |
                     last


--------------------------------------------------------
STEP 8: Move current to NULL
--------------------------------------------------------

current = current->link;

Original:

[10] ---> [20] ---> [30] ---> NULL
                                ^
                                |
                             current


Since:

current == NULL

the while loop stops.


========================================================
FINAL RESULT
========================================================

ORIGINAL LIST:

otherList.first
      |
      v
    [10] ---> [20] ---> [30] ---> NULL


COPIED LIST:

first
  |
  v
[10] ---> [20] ---> [30] ---> NULL
                      ^
                      |
                     last


The data is the same,
but these are DIFFERENT nodes in memory.


Example:

ORIGINAL:

0x1000       0x2000       0x3000
[ 10 ] ---> [ 20 ] ---> [ 30 ]


COPY:

0x5000       0x6000       0x7000
[ 10 ] ---> [ 20 ] ---> [ 30 ]


This is called a DEEP COPY.

The nodes are independent.

Changing a node in the copied list does NOT change the
corresponding node in the original list.


========================================================
MAIN IDEA
========================================================

current  -> walks through the OLD list

newNode  -> creates nodes for the NEW list

first    -> stays at the beginning of the NEW list

last     -> always moves to the newest node added


The repeated process is:

1. Create a new node.
2. Copy current->info into the new node.
3. Connect last->link to the new node.
4. Move last to the new node.
5. Move current to the next original node.


Time Complexity:

The function visits each node once.

If there are n nodes:

Time Complexity = O(n)
*/