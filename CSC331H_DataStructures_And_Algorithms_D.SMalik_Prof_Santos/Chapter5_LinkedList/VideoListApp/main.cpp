#include "customerType.h"
#include "videoListType.h"
#include "customerListType.h"
#include <iostream>
#include <fstream>

using namespace std;

void createVideoList(ifstream &, videoListType &);
void createCustomerList(ifstream &, customerListType &);

int main()
{
    ifstream customerListFile("customerList.txt");
    ifstream videoListFile("videoDat.txt");
    nodeType<customerType> *currentCustomer;
    bool isCustomerFound;
    customerListType customers;

    createCustomerList(customerListFile, customers);
    // customers.printCustomerList();

    customers.searchCustomerList(19032, isCustomerFound, currentCustomer);

    if (isCustomerFound)
    {
        cout << "We Found your customer!" << endl;
        // customers.printCustomer(currentCustomer);
        currentCustomer->info.print(); // can do it struct member info is public - anyone can have access to them
    }
}

// create customer list
void createCustomerList(ifstream &infile, customerListType &customerList)
{
    string firstName;
    string lastName;
    int accNumber;
    customerType customer;

    // video information
    string title;
    string star1;
    string star2;
    string producer;
    string director;
    string productionCo;
    char ch;
    int inStock;
    videoType newVideo;

    // check next customer
    string checkNext;

    getline(infile, firstName);
    while (infile)
    {
        // re-create the videolist for next customer
        videoListType videoList;

        getline(infile, lastName);
        infile >> accNumber;
        infile.ignore(); // remove the leftover newline
        getline(infile, title);
        while (infile)
        {
            getline(infile, star1);
            getline(infile, star2);
            getline(infile, producer);
            getline(infile, director);
            getline(infile, productionCo);
            infile >> inStock;
            infile.get(ch);
            newVideo.setVideoInfo(title, star1, star2, producer, director, productionCo, inStock);
            videoList.insertFirst(newVideo);
            getline(infile, checkNext);
            if (checkNext == "---")
            {
                break;
            }
            getline(infile, title);
        }
        customer.createCustomer(firstName, lastName, accNumber, videoList);
        customerList.insertFirst(customer);
        getline(infile, firstName);
    }
}

void createVideoList(ifstream &infile, videoListType &videoList)
{
    string title;
    string star1;
    string star2;
    string producer;
    string director;
    string productionCo;
    char ch;
    int inStock;
    videoType newVideo;
    getline(infile, title);
    while (infile)
    {
        getline(infile, star1);
        getline(infile, star2);
        getline(infile, producer);
        getline(infile, director);
        getline(infile, productionCo);
        infile >> inStock;
        infile.get(ch);
        newVideo.setVideoInfo(title, star1, star2, producer, director, productionCo, inStock);
        videoList.insertFirst(newVideo);
        getline(infile, title);
    } // end while
} // end createVideoList