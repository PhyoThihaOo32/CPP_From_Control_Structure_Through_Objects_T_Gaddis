// implementation file for NumberList
#include "NumberList.h"
#include <iostream>

/*
To append a node to a linked list means to add the node to the end of the list.
The appendNode member function accepts a double argument, num. The function will allocate a new ListNode structure,
store the value in the num in the node's value member, and append the node to the end of the list.

Pseudocode representation

Create a new node
Store data in the new node
If there are no nodes in the list
    Make the new node the first node.
Else
    Transverse the list to find the last node.
    Add the new node to the end of the list.
End if.
*/
void NumberList::appendNode(double num)
{
    ListNode *newNode; // to point to the new node
    ListNode *nodePtr; // to transverse through the nodes

    // allocate new node and store num
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    // if there are no node in the list make the newNode the first node(the head)
    if (!head)
    {
        head = newNode;
    }
    // otherwise insert the new node at the end
    else
    {
        nodePtr = head; // initialize the nodePtr to head of the list
        while (nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }

        // insert newNode as the end
        nodePtr->next = newNode;
    }
}

/*
Display member function transverse the list, displaying the value member of each node.

Pseudocode representation

Assign List head to node pointer.
While node pointer is not null
    Display the value member of the node pointed to by node pointer
    Assign node pointer to its own next member.
End While.
*/

void NumberList::displayNodeList() const
{
    ListNode *nodePtr; // to transverse through the lists

    nodePtr = head; // position nodePtr at the head of the list

    while (nodePtr)
    {
        std::cout << nodePtr->value << std::endl;
        nodePtr = nodePtr->next; // move to the next node
    }
}

/*
Pseudocode

Create a new node
Store data in the new node.
If there are no nodes in the list
    Make the new node the first node.
Else
    Find the first node whose value is greater than or equal to the new value,
    or the end of the list(whichever is first)
    Insert the new node before the found node, or at the end of the list if no such node was found
End if

This algorithm finds the first node whose value is greater than or equal to the new value.
The new node is then inserted before the found node. This will require the use of tow node pointers during traversal:
one to point to the node being inspected and another to pointer to the previous node.

*/
void NumberList::insertNode(double num)
{
    // create three nodes
    ListNode *newNode;     // to store the value of num
    ListNode *nodePtr;     // to transverse through the list
    ListNode *previousPtr; // to point to the node after nodePtr(the previous node)

    // allocate new node and store the value of num in newNode
    newNode = new ListNode;
    newNode->value = num;

    // if there are no node in the list make the newNode the first node
    if (!head)
    { // head == nullptr
        head = newNode;
        newNode->next = nullptr;
    }
    else
    {
        // position the nodePtr at the head of the list
        nodePtr = head;

        // initialize previousNode to the nullptr
        previousPtr = nullptr;

        // skips all nodes whose value is less than num
        while (nodePtr != nullptr && nodePtr->value < num)
        {
            previousPtr = nodePtr;
            nodePtr = nodePtr->next;
        }

        // if the new node is to be the first in the lis, insert it before all other nodes
        if (previousPtr == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else
        { // otherwise insert it after the previous node
            previousPtr->next = newNode;
            newNode->next = nodePtr;
        }
    }
}
/*
This function
1. remove the node from the list without breaking the links created by the next pointers
2. delete the node from the memory
*/
void NumberList::deleteNode(double num)
{
    ListNode *nodePtr;      // to tranverse the list
    ListNode *previousNode; // to point to the previous node

    // if the list is empty, do nothing
    if (!head)
        return; // head == nullptr

    // check if the first node is the one to be deleted
    if (head->value == num)
    {
        nodePtr = head->next; // point to the node next to head
        delete head;          // delete dynamic memory head is pointing to(delete head)
        head = nodePtr;       // re-point head to nodePtr
    }

    else
    {
        // initialize the nodePtr to head of list
        nodePtr = head;

        // skip all nodes whose value member is not equal to num
        while (nodePtr != nullptr && nodePtr->value != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // if the nodePtr is not at the end of the list, link the previous node to the node after nodePtr
        // then delete the nodePtr
        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

/*
Destructor is to release all the memory used by the list. It does so by stepping through the list,
deleting one node at a time.
*/

NumberList::~NumberList()
{
    ListNode *nodePtr; // to point to the current node
    ListNode *nextNode;

    // position the nodePtr at the head of the list
    nodePtr = head;

    // while nodePtr is not at the end of the list
    while (nodePtr != nullptr)
    {
        // save a pointer to the next node
        nextNode = nodePtr->next;

        // delete the current node
        delete nodePtr;

        // position nodePtr at the next node
        nodePtr = nextNode;
    }
}