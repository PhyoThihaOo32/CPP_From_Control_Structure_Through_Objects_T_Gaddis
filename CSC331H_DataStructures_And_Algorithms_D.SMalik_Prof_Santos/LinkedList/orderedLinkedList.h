#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H

#include "linkedListType.h"

using namespace std;

template <class Type>
class orderedLinkedList : public linkedListType<Type>
{
public:
    // function to determine whether the search item is in the list
    // postcondition: return true is searchItem is in the list, otherwise return false
    bool search(const Type &searchItem) const;

    // function to insert newItem in the list
    // postcondition: first points to the new list, newItem is inserted at the proper
    // place in the list, and count is incremented by 1
    void insert(const Type &newItem);

    // function to insert newItem in the list - because resulting list must be sorted
    // newItem still must be inserted at the proper order
    void insertFirst(const Type &newItem);
    void insertLast(const Type &newItem);

    // function to delete deleteItem from the list
    // postcondition: if found, node containing deleteItem is deleted from the list
    // first point to the first node of the new list, and count is decremented by 1
    // if deleteItem is not in the list, an appropriate message is printed
    void deleteNode(const Type &deleteItem);
};

// Note: the loop does not explicitly check whether the search item is equal to an item in the list
template <class Type>
bool orderedLinkedList<Type>::search(const Type &searchItem) const
{
    nodeType<Type> *current; // pointer to transver the list
    bool found = false;
    current = this->first; // point to the first node
    while (current != nullptr && !found)
    {
        if (current->info >= searchItem)
        {
            found = true; // and end the loop
        }
        else
        {                            // if the serachItem is not found yet
            current = current->link; // look for next node
        }
    }
    if (found)
    { // if the searchItem is found - same as or greater than the current info
      // we still need to check for equality
        found = (current->info == searchItem);
    }
    return found;
}

// INSERT A NODE - In Ascending Order
/*
Two pointers - current to poinnt the current node and trailCurrent - point the node after current.
Case1: The list is initially empty. The node containing the new item is the only node
and thus the first node in the list
Case2: The new item is the smallest and goes to the beginning of the list.
The first pointer need to be adjusted -> point to newly added node.
Case3: The new item is to be inserted somewhere.
3a: The new item is the largest and goes to the end of the list.
current point to NULL, new item is inserted after trailCurrent
3b: The new item is inserted somewhere - (between trailCurrent and current).
*/
template <class Type>
void orderedLinkedList<Type>::insert(const Type &newItem)
{
    nodeType<Type> *current;      // pointer to traverse the list -> point current node
    nodeType<Type> *trailCurrent; // pointer to point the node after the current
    nodeType<Type> *newNode;      // pointer to point new node

    bool found; //  flag to end the loop which is to find the item
    // first create a new node and copy the data
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = nullptr;

    // case 1 if the list is empty
    if (this->first == nullptr)
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        // if the list is not empty
        current = this->first;
        found = false;
        while (current != nullptr && !found)
        {
            if (current->info >= newItem)
            {
                found = true; // end the loop
            }
            else
            { // move to the next node
                trailCurrent = current;
                current = current->link;
            }
        }

        // if newItem is equal or greater than the current info
        // Case2: new item is the smallest and to be inserted in the beginning
        // that mean the first item in the node is larger than the newItem
        // and current pointer still pointing to the first
        if (current == this->first)
        {
            // inserted new node before the first node and adjust first pointer
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        }
        else
        { // if not newItem will be inserted somewhere - either in the middle or end
            trailCurrent->link = newNode;
            newNode->link = current;

            // if the item is to be inserted in the end
            if (current == nullptr)
            {
                this->last = newNode;
            }
            this->count++;
        }
    }
}

/*
In reality, the function insertFirst and insertLast do not apply to ordered linked lists
because new item is inserted at the proper place.
*/
template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type &newItem)
{
    insert(newItem);
}

template <class Type>
void orderedLinkedList<Type>::insertLast(const Type &newItem)
{
    insert(newItem);
}

// DELETE A NODE
/*
Case1: The list is initially empty.
Case2: delete item is in the first node of the list.
Case3: delete item is somewhere in the list - either in between or at the end.
Case4: delete item is not in the list.
*/

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type &deleteItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found; // flag to stop the search

    // case1: empty list
    if (this->first == nullptr)
    {
        cout << "Cannot delete from an empty list." << endl;
    }
    else
    { // if the list is not empty -> then we have to tranverse the list - and search
        found = false;
        current = this->first;
        while (current != nullptr && !found)
        {
            if (current->info >= deleteItem)
            {
                found = true; // end the loop
            }
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        }
        // case 4: not in the list
        // tranverse is done and the current point to nullptr - that mean the item is not in the list
        // eg- largest item in the list is 19 and we are looking for 25
        if (current == nullptr)
        {
            cout << "The item to be deleted is not in the list." << endl;
        }
        else
        { // otherwise, delete item is in the list - in between or at the end
            if (current->info == deleteItem)
            {
                // Case 2: delete item is the first node
                if (current == this->first) // if we found the deleteItem and current point to first node
                {
                    this->first = this->first->link; // first point to next node
                    // if there is only one node
                    if (this->first == nullptr)
                    {
                        this->last = nullptr; // before last point to first -> we must also point last to nullptr
                    }
                    delete current;
                }
                else
                {
                    // if the delete item is not in the first node
                    trailCurrent->link = current->link;

                    // if the delete item is the last node
                    if (current == this->last)
                    {
                        this->last = trailCurrent;
                    }
                    delete current;
                }
                // in both cases item will be deleted, decrement the count
                this->count--;
            }
            else
            {
                // if the delete item is like 10 and current is 12
                // that also mean the delete item is not in the list
                cout << "The item to be deleted is not in the list." << endl;
            }
        }
    }
}

#endif