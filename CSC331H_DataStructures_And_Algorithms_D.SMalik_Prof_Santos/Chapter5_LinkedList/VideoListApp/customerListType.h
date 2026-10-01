#pragma once
#ifndef CUSTOMERLISTTYPE_H
#define CUSTOMERLISTTYPE_H

#include "customerType.h"
#include "unorderedLinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;

class customerListType : public unorderedLinkedList<customerType>
{
public:
    void searchCustomerList(int, bool &, nodeType<customerType> *&) const;
    void printCustomerList() const;
    void printCustomer(nodeType<customerType> *) const;
    friend ostream &operator<<(ostream &, const customerListType &);
};

void customerListType::searchCustomerList(int accNumber, bool &found, nodeType<customerType> *&current) const
{
    found = false;
    current = this->first;
    while (current != nullptr && !found)
    {
        if (current->info.checkAccNumber(accNumber))
        {
            found = true;
        }
        else
        {
            current = current->link;
        }
    }
}

void customerListType::printCustomerList() const
{
    nodeType<customerType> *current;
    current = this->first;
    while (current != nullptr)
    {
        cout << "Customer Name: ";
        current->info.print(); // print first and last name
        cout << "\nAccount Number: ";
        current->info.printAccNumber(); // print account number
        cout << endl;
        current->info.printCustomerVideoList();
        current = current->link;
    }
}

void customerListType::printCustomer(nodeType<customerType> *current) const
{
    cout << "Customer Name: ";
    current->info.print();
    cout << "\nAccount Number: ";
    current->info.printAccNumber();
    cout << endl;
    current->info.printCustomerVideoList();
}

ostream &operator<<(ostream &out, const customerListType &customerList)
{
    linkedListIterator<customerType> ite;
    for (ite = customerList.begin(); ite != customerList.end(); ++ite)
    {
        out << *ite;
    }
    return out;
}

#endif