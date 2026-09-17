/*
Author: D.S Malik
This class specifies the members to implement the basic
properties of an unordered linked list. This class is derived from
the class linkedListType.
*/

#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H

#include "linkedListType.h"

using namespace std;

template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
public:
    // function to determine whether searchItem is in the list
    // postcondition: returns true if searchItem is in the list,
    //                otherwise return false
    bool search(const Type &searchItem) const;

    // function to insert newItem at the begining of the list
    // postcondition: first points to the new list, newItem is
    // inserted at the begining of the list, last point to the last node,
    // count is incremented by 1
    void insertFirst(const Type &newItem);

    // function to insert newItem at the end of the list
    // postcondition: first points to the new list, newItem is
    // inserted at the end of the list, last points to the last node,
    // and count is incremented by 1
    void insertLast(const Type &newItem);

    // function to deleteItem from the list
    // postcondition: if found, the node containing deleteItem
    // is deleted from the list. first point to the first node,
    // last point to the last node of the updated list, and count is
    // decremented by 1.
    void deleteNode(const Type &deleteItem);
};

// Implementations

/*
Because the linked list is not a random access data structure, we must
squentially search the list starting from the first node.
1. compare the serach item with the current node(info) in the list.
if the info is found, stop the search, otherwise make the next node the current node
2. repeat step 1 until either the item is found or no more data is left in the
list to compare with the search item.
*/
template <class Type>
bool unorderedLinkedList<Type>::search(const Type &searchItem) const
{
    // create the point to transverse the list
    nodeType<Type> *current;
    // point to the first node
    current = this->first;
    // flage to stop the loop
    bool found = false;

    while (current != NULL && !found)
    {
        if (current->info == searchItem)
        { // if the item is in the linkedList
            found = true;
        }
        else
        {                            // if the searchItem is not equal to the current item
            current = current->link; // move to the next node, and repeat the serach
        }
    }
    return found;
} // O(n)

// INSERT THE FIRST NODE
/*
The function insertFirst inserts the new item at the beginning of the list—that is, before
the node pointed to by first. The steps needed to implement this function are as follows:
1. Create a new node.
2. If unable to create the node, terminate the program.
3. Store the new item in the new node.
4. Insert the node before first.
5. Increment count by 1.
*/
template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type &newItem)
{
    // create pointer to new node
    nodeType<Type> *newNode;
    // create new node
    newNode = new nodeType<Type>;
    // copy date(from newItem) to new node
    newNode->info = newItem;
    // put new node before the first node
    newNode->link = this->first;
    // first node now must point to new node
    this->first = newNode;
    // incrase the count
    this->count++; // count is the protected member of linkedListType class -> can call it directly in here because it is protected member variable

    // now that we have add new node in the first but what if the list is empty
    // meaning last is pointing to null

    if (this->last == NULL)
    {
        this->last = this->first;
        // is that same? last = newNode;
    }
}

// INSERT THE LAST NODE
template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type &newItem)
{
    // create pointer to new node
    nodeType<Type> *newNode;
    // create new node
    newNode = new nodeType<Type>;
    // copy newItem into newNode info
    newNode->info = newItem;
    // new node will be the last node so it must point to null
    newNode->link = NULL;
    if (this->first == NULL)
    { // if the list is empty
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        // and then add new node to the end of the list
        this->last->link = newNode;
        // last poitn to new node
        this->last = newNode;
        this->count++;
    }
} // O(1)

/*
Case 1: if the list is empty
Case 2: the list is not empty and node to be delete is the first node
        2a: list has only one node -> after delete both first and last to set to NULL and count is 0
        2b: list has one than one node -> after delete -> second node become first node
Case 3: 3a:node to be delete is somewhere in the list
        3b: node to be delete is the last node
Case 4: The node to be delete is not in the list
*/

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type &deleteItem)
{
    // we need to pointer -> pointer to tranvser the list (the current pointer) and pointer before the current
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found; // flag

    // Case 1: empty list
    if (this->first == NULL)
    {
        cout << "Cannot delete from an empty list." << endl;
    }
    else
    {
        // Case 2: if not empty -> deleteItem is the first node
        // 2a: list has only one node
        // 2b: more than one node
        if (this->first->info == deleteItem)
        {
            current = this->first;
            this->first = this->first->link;
            this->count--;
            if (this->first == NULL)
            {
                this->last = NULL;
            }
            delete current;
        }
        else
        { // case 3: deleteItem is somewhere or in the last
            found = false;
            trailCurrent = this->first;  // trail point to first
            current = this->first->link; // current point to second( and so on)
            while (current != NULL && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current->link;
                }
                else
                {
                    found = true;
                }
            }
            if (found)
            {
                // if we found NOT in the last node
                // delete the current node -> connect the trail and next of current
                trailCurrent->link = current->link;
                this->count--;
                if (this->last == current)
                {
                    this->last = trailCurrent;
                }
                delete current;
            }
            // case 4: not found
            else
            {
                cout << "The item to be deleted is not in the list." << endl;
            }
        }
    }
}

#endif

/*
========================================================
VISUAL EXPLANATION OF deleteNode()
========================================================

Purpose:
deleteNode() searches for deleteItem in the linked list
and removes the node containing that value.

We use two pointers:

current
    -> points to the node currently being examined

trailCurrent
    -> points to the node immediately BEFORE current


Example list:

first
  |
  v
[10] -> [20] -> [30] -> [40] -> NULL
                          ^
                          |
                         last


========================================================
CASE 1: THE LIST IS EMPTY
========================================================

If:

first == NULL

then:

first -> NULL
last  -> NULL

There is no node to delete.

So:

cout << "Cannot delete from an empty list.";


========================================================
CASE 2: deleteItem IS IN THE FIRST NODE
========================================================

Example:

deleteItem = 10

Before:

first
  |
  v
[10] -> [20] -> [30] -> NULL
                  ^
                  |
                 last


First save the node we want to delete:

current = first;

Now:

current
  |
  v
[10] -> [20] -> [30] -> NULL
  ^
  |
 first


Move first to the next node:

first = first->link;

Now:

current       first
  |             |
  v             v
[10] --------> [20] -> [30] -> NULL
                        ^
                        |
                       last


Decrease the number of nodes:

count--;


Then delete the old first node:

delete current;


Final list:

first
  |
  v
[20] -> [30] -> NULL
          ^
          |
         last


--------------------------------------------------------
SPECIAL CASE: THE LIST HAS ONLY ONE NODE
--------------------------------------------------------

Before:

first
  |
  v
[10] -> NULL
  ^
  |
 last


current = first;

current
  |
  v
[10] -> NULL


Then:

first = first->link;

Since the only node points to NULL:

first -> NULL


Now:

if (first == NULL)
{
    last = NULL;
}

So:

first -> NULL
last  -> NULL

Then:

delete current;

The list is now completely empty.


========================================================
CASE 3: deleteItem IS NOT THE FIRST NODE
========================================================

We must search through the list.

Example:

deleteItem = 30

List:

first
  |
  v
[10] -> [20] -> [30] -> [40] -> NULL
                          ^
                          |
                         last


We start with:

trailCurrent = first;
current = first->link;


So:

trailCurrent     current
      |             |
      v             v
    [10] --------> [20] -> [30] -> [40] -> NULL


trailCurrent stays ONE NODE BEHIND current.


========================================================
SEARCHING THROUGH THE LIST
========================================================

while (current != NULL && !found)


If current does NOT contain deleteItem:

if (current->info != deleteItem)


Move both pointers forward:

trailCurrent = current;
current = current->link;


Before:

trailCurrent     current
      |             |
      v             v
    [10] --------> [20] -> [30] -> [40]


After:

                trailCurrent     current
                      |             |
                      v             v
    [10] --------> [20] --------> [30] -> [40]


Now current points to 30.


Check:

current->info == deleteItem


So:

found = true;


========================================================
DELETE THE FOUND NODE
========================================================

At this point:

trailCurrent     current
      |             |
      v             v
    [20] --------> [30] --------> [40]


We want to remove [30].


The important line is:

trailCurrent->link = current->link;


current->link points to [40].

So we change the link inside [20].


Before:

[20] -> [30] -> [40]
         ^
         |
      current


After:

[20] ----------> [40]

         [30]
          ^
          |
       current


Node [30] is no longer connected to the list.


Then:

delete current;


Final list:

[10] -> [20] -> [40] -> NULL


========================================================
WHY trailCurrent IS NEEDED
========================================================

In a singly linked list, a node only knows
the node AFTER it.

Example:

[20] -> [30] -> [40]

Node [30] does NOT know that [20] comes before it.


Therefore, when deleting [30], we need trailCurrent
to remember the previous node:

trailCurrent
      |
      v
    [20] -> [30] -> [40]
              ^
              |
            current


Then we can bypass current:

trailCurrent->link = current->link;


Result:

[20] ----------> [40]

          [30]
           ^
           |
        current


Then:

delete current;


========================================================
SPECIAL CASE: DELETE THE LAST NODE
========================================================

Example:

deleteItem = 40

Before:

first
  |
  v
[10] -> [20] -> [30] -> [40] -> NULL
                  ^       ^
                  |       |
             trailCurrent current
                          last


First bypass current:

trailCurrent->link = current->link;


Since current is the last node:

current->link == NULL


So:

[30] -> NULL


But last is still pointing to the node we are
about to delete.

Therefore:

if (last == current)
{
    last = trailCurrent;
}


Now:

first
  |
  v
[10] -> [20] -> [30] -> NULL
                  ^
                  |
                 last


Then:

delete current;


========================================================
CASE 4: deleteItem IS NOT FOUND
========================================================

If current keeps moving until:

current == NULL

and found is still false:

found == false


Example:

deleteItem = 99

[10] -> [20] -> [30] -> NULL
                         ^
                         |
                       current


The item does not exist in the list.

So:

cout << "The item to be deleted is not in the list.";


========================================================
MAIN IDEA
========================================================

current
    -> points to the node being checked

trailCurrent
    -> stays one node behind current

found
    -> becomes true when deleteItem is found


To delete a node in the middle:

trailCurrent->link = current->link;

This makes the previous node skip over current.


Before:

trailCurrent     current
      |             |
      v             v
    [20] --------> [30] --------> [40]


After:

trailCurrent
      |
      v
    [20] ----------------------> [40]

                    [30]
                     ^
                     |
                   current


Then:

delete current;


========================================================
TIME COMPLEXITY
========================================================

Best case:
deleteItem is the first node

O(1)


Worst case:
deleteItem is near the end or not found

We may have to traverse the entire list.

O(n)
*/