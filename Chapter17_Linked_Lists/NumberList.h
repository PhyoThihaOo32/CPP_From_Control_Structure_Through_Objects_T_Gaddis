// Specification file for the NumberList class

#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
private:
    // this is known as self-referential data structure which contaiins a pointer to an object of the same type
    struct ListNode
    {
        double value;   // to store the value in the node
        ListNode *next; // to point to the next node
    };
    ListNode *head; // List head pointer
public:
    // constructor
    NumberList()
    {
        head = nullptr; // initialize the head pointer to nullptr - create an empty linked list
    }

    ~NumberList();

    // Linked List operations
    void appendNode(double);
    void insertNode(double);
    void deleteNode(double);
    void displayNodeList() const;
};

#endif