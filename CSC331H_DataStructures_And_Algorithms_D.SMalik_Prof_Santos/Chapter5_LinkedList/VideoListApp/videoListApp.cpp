//****************************************************************
// Author: D.S. Malik
//
// This program illustrates how to use the classes videoType and
// videListType to create and process a list of videos.
//****************************************************************
#include <iostream>
#include <fstream>
#include <string>
#include "videoListType.h"
#include "customerListType.h"
#include "customerType.h"
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

void createCustomerList(ifstream &infile, customerListType &);
void createVideoList(ifstream &infile, videoListType &videoList);
void displayMenu();
void registerCustomer(customerListType &);

int main()
{
    videoListType videoList;
    customerListType customerList;
    nodeType<customerType> *currentCustomer; // pointer to point to current customer
    int userAccNum;                          // user will enter the account number
    bool isFound;                            // to check if the customer is int the list
    int num;
    int choice;
    char ch;
    char cusChoice;
    string title;
    ifstream videoFile;
    ifstream customerFile;
    // open the input file
    videoFile.open("videoDat.txt");
    if (!videoFile)
    {
        cout << "The input file does not exist. "
             << "The program terminates!!!" << endl;
        return 1;
    }
    // create the video list
    createVideoList(videoFile, videoList);
    videoFile.close();

    // opent customerFile and get the data
    customerFile.open("customerList.txt");
    if (!customerFile)
    {
        cout << "The customer file does not exist."
             << "The program terminates!!!" << endl;
        return 1;
    }
    createCustomerList(customerFile, customerList);
    customerFile.close();

    // ask user for account number
    cout << "Welcome to 1990's Video Store" << endl;
    do
    {
        cout << "Are you existing customer? Y/N" << endl;
        cin >> cusChoice;

        // validate cusChoise
    } while (!(cusChoice == 'Y' || cusChoice == 'y' || cusChoice == 'N' || cusChoice == 'n'));

    if (cusChoice == 'Y' || cusChoice == 'y')
    {
        cout << "Please Enter your 5-digits Account Number to continue: ";
        cin >> userAccNum;

        // validate the user input
        while (cin.fail())
        {
            cout << "Invalid input. Please Enter your 5-digits Account Number." << endl;
            cin.clear();  // clear the error state
            cin.ignore(); // remove the invalid input from the buffer
            cin >> userAccNum;
        }

        // search the customer from the list
        customerList.searchCustomerList(userAccNum, isFound, currentCustomer);

        if (!isFound)
        {
            cout << "We can't find the account Number. You must be new customer." << endl;
            cout << "Would you like to create a new account? Y/N" << endl;
            cin.ignore();
            cin >> cusChoice;
            while (cin.fail())
            {
                cout << "Invalid Respond. Please Type Y or N." << endl;
                cin.clear();
                cin.ignore();
                cin >> cusChoice;
            }
            if (cusChoice == 'Y' || cusChoice == 'y')
            {
                registerCustomer(customerList);
                cout << "Thank you for opening new account!" << endl;
                cout << "Here is your Info: " << endl;
                cout << "Customer Name: ";
                customerList.front().print();
                cout << "\nAccount Number: ";
                customerList.front().printAccNumber();
                cout << "\nCurrent Movie List: " << endl;
                customerList.front().printCustomerVideoList();
                userAccNum = customerList.front().getAccNumber();
            }
            else
            {
                cout << "Thank you for visiting us! Please register next time." << endl;
                return 0;
            }
        }
    }
    else
    {
        cout << "Would you like to create a new account? Y/N" << endl;
        cin.ignore();
        cin >> cusChoice;
        while (cin.fail())
        {
            cout << "Invalid Respond. Please Type Y or N." << endl;
            cin.clear();
            cin.ignore();
            cin >> cusChoice;
        }
        if (cusChoice == 'Y' || cusChoice == 'y')
        {
            registerCustomer(customerList);
            cout << "Thank you for opening new account!" << endl;
            cout << "Here is your Info: " << endl;
            cout << "Customer Name: ";
            customerList.front().print();
            cout << "\nAccount Number: ";
            customerList.front().printAccNumber();
            cout << "\nCurrent Movie List: " << endl;
            customerList.front().printCustomerVideoList();
            userAccNum = customerList.front().getAccNumber();
        }
        else
        {
            cout << "Thank you for visiting us! Please register next time." << endl;
            return 0;
        }
    }

    customerList.searchCustomerList(userAccNum, isFound, currentCustomer);

    if (isFound)
    {
        // show the menu
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice; // get the request
        cin.get(ch);
        cout << endl;
        // process the requests
        while (choice != 9)
        {
            switch (choice)
            {
            case 1:
                cout << "Enter the title: ";
                getline(cin, title);
                cout << endl;
                if (videoList.videoSearch(title))
                    cout << "The store carries " << title << endl;
                else
                    cout << "The store does not carry " << title << endl;
                break;
            case 2:
                cout << "Enter the title: ";
                getline(cin, title);
                cout << endl;
                if (videoList.videoSearch(title))
                {
                    if (videoList.isVideoAvailable(title))
                    {
                        // videoList.videoCheckOut(title);
                        currentCustomer->info.rentVideo(title, videoList);
                        cout << "Enjoy your movie: " << title << endl;
                        cout << endl;
                    }
                    else
                        cout << "Currently " << title << " is out of stock." << endl;
                }
                else
                    cout << "The store does not carry " << title << endl;
                break;
            case 3:
                cout << "Enter the title: ";
                getline(cin, title);
                cout << endl;
                if (videoList.videoSearch(title))
                {
                    // videoList.videoCheckIn(title);
                    currentCustomer->info.returnVideo(title, videoList);
                    cout << "Thanks for returning " << title << endl;
                }
                else
                    cout << "The store does not carry " << title << endl;
                break;
            case 4:
                cout << "Enter the title: ";
                getline(cin, title);
                cout << endl;
                if (videoList.videoSearch(title))
                {
                    if (videoList.isVideoAvailable(title))
                        cout << title << " is currently in " << "stock." << endl;
                    else
                        cout << title << " is currently out " << "of stock." << endl;
                }
                else
                    cout << "The store does not carry " << title << endl;
                break;
            case 5:
                videoList.videoPrintTitle();
                break;
            case 6:
                videoList.print();
                break;
            case 7:
                customerList.printCustomer(currentCustomer);
                break;
            default:
                cout << "Invalid selection." << endl;
            } // end switch

            displayMenu(); // display menu
            cout << "Enter your choice: ";
            cin >> choice; // get the next request
            cin.get(ch);
            cout << endl;
        } // end while
        cout << "--------------------------" << endl;
        cout << "Thank you for visiting Us!" << endl;
    }

    // save the updated video list to the file
    ofstream videoFileOut("videoDat.txt"); // you cann't use the same variable name in the same scope
    videoFileOut << videoList;

    // save the updated customer list to the file
    ofstream customerFileOut("customerList.txt");
    customerFileOut << customerList;

    return 0;
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

void displayMenu()
{
    cout << "Select one of the following:" << endl;
    cout << "1: To check whether the store carries a particular video." << endl;
    cout << "2: To check out a video." << endl;
    cout << "3: To check in a video." << endl;
    cout << "4: To check whether a particular video is in stock." << endl;
    cout << "5: To print only the titles of all the videos." << endl;
    cout << "6: To print a list of all the videos." << endl;
    cout << "7: To show customer Info." << endl;
    cout << "9: To exit" << endl;
} // end createVideoList

// create customer list
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

void registerCustomer(customerListType &customerList)
{
    string firstN, lastN;
    int accNum;
    videoListType videoList;
    customerType customer;
    cout << "Please Enter your First Name: ";
    cin >> firstN;
    cout << "Please Enter your Last Name: ";
    cin >> lastN;
    srand(time(0));
    accNum = rand() % 100000;
    videoList.initializeList();
    customer.createCustomer(firstN, lastN, accNum, videoList);
    customerList.insertFirst(customer);
}
