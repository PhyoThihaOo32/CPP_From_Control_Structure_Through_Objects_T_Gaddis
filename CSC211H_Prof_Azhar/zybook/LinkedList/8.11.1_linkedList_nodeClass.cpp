#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int dataValue)
    {
        cout << "In Node constructor (" << dataValue << ")" << endl;
        data = dataValue;
    }

    ~Node()
    {
        cout << "In Node destructor (" << data << ")" << endl;
    }
};

class LinkedList
{
    Node *head;

    LinkedList()
    {
        cout << "In LinkedList constructor." << endl;
        head = nullptr;
    }
    ~LinkedList()
    {
        cout << "In LinkedList destructor." << endl;
        while (head != nullptr)
        {
            Node *next = head->next;
            delete head;
            head = next;
        }
    }
};