#include "queueADT.h"
#include "queueType.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    /*
    create two instances of the queue and load each file which consist of names into each of the queues.
    */
    queueType<string> priorityQueue;
    queueType<string> regularQueue;
    queueType<string> tomorrowPQueue;
    queueType<string> tomorrowRQueue;

    string priorityName, regularName, tomorrowName; // variables to store the names
    int count = 0;                                  // to count the names

    ifstream priorityFile("priority.txt");
    ifstream regularFile("regular.txt");

    // adding names from priority file into queue
    while (getline(priorityFile, priorityName))
    {
        priorityQueue.addQueue(priorityName);
    }

    // adding name from regular file into queue
    while (getline(regularFile, regularName))
    {
        regularQueue.addQueue(regularName);
    }

    // process every 2 priority names and then 1 regular name
    // output the names in the order they were processed and remove from the queue
    // process only 50 names
    while (count < 50)
    {
        cout << "Priority Name(From priorityQueue): ";
        cout << priorityQueue.front();
        priorityQueue.deleteQueue();
        count++;
        if (count == 50)
            break;
        cout << " | ";
        cout << priorityQueue.front() << endl;
        priorityQueue.deleteQueue();
        count++;
        if (count == 50)
            break;

        cout << "Regular Name(From regularQueue): ";
        cout << regularQueue.front() << endl;
        regularQueue.deleteQueue();
        count++;
        if (count == 50)
            break;
    }
    cout << count << " names printed." << endl;
    cout << "------------------------" << endl;

    while (!priorityQueue.isEmptyQueue())
    {

        tomorrowPQueue.addQueue(priorityQueue.front());
        priorityQueue.deleteQueue();
    }

    while (!regularQueue.isEmptyQueue())
    {
        tomorrowRQueue.addQueue(regularQueue.front());
        regularQueue.deleteQueue();
    }

    cout << "Printing Tomorrow Priority Queue(From tomorrowPQueue): " << endl;
    while (!tomorrowPQueue.isEmptyQueue())
    {
        cout << tomorrowPQueue.front() << endl;
        tomorrowPQueue.deleteQueue();
    }
    cout << "------------------------" << endl;
    cout << "Printing Tomorrow Regular Queue(From tomorrowRQueue): " << endl;
    while (!tomorrowRQueue.isEmptyQueue())
    {
        cout << tomorrowRQueue.front() << endl;
        tomorrowRQueue.deleteQueue();
    }

    cout << "Submitted By: Phyo Thiha Oo | ID: 24492624" << endl;

    return 0;
}