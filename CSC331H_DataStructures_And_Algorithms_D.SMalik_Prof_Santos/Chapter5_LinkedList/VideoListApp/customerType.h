#ifndef CUSTOMERTYPE_H
#define CUSTOMERTYPE_H

#include "personType.h"
#include "videoListType.h"
#include "linkedListIterator.h"

using namespace std;

class customerType : public personType
{
private:
    int accNumber;
    videoListType customerVideoList;

public:
    // function to print customer Account Number
    void printAccNumber() const;

    // function to set Account Number
    void setAccNumber(int);

    // function to return Account Number
    int getAccNumber() const;

    // function to check the Account Number
    bool checkAccNumber(int) const;

    // function to print customer video list - title only
    void printCustomerVideoList() const;

    // function to print detail customer video list
    void printDetailCustomerVideoList() const;

    // function to rent a video
    // this function will look for the video list from the store using title
    // if found - will check out the video from the store and add to the customer video list
    void rentVideo(string, videoListType &);

    // function to return a video
    // this function will look for the video from the customer video list using the title
    // if found will remove the video from the customer video list
    // and then return(check in) to the store - if store don't have the video don't have that title
    // then customer can't return
    void returnVideo(string, videoListType &);

    // function to create new customer
    void createCustomer(string, string, int, const videoListType &);

    // check equality operator ==
    bool operator==(const customerType &other) const;

    bool operator!=(const customerType &other) const;

    friend ostream &operator<<(ostream &, const customerType &);
};

void customerType::printAccNumber() const
{
    cout << accNumber;
}

void customerType::setAccNumber(int accNumber)
{
    this->accNumber = accNumber;
}

int customerType::getAccNumber() const
{
    return accNumber;
}

bool customerType::checkAccNumber(int accNumber) const
{
    return (this->accNumber == accNumber);
}

void customerType::printCustomerVideoList() const
{
    customerVideoList.videoPrintTitle();
}

void customerType::printDetailCustomerVideoList() const
{
    customerVideoList.videoPrintDetail();
}

// function to rent a video
// this function will look for the video list from the store using title
// if found - will check out the video from the store and add to the customer video list
void customerType::rentVideo(string title, videoListType &storeVideoList)
{
    bool isInStock;
    linkedListIterator<videoType> ite;
    videoType video;
    int count = 0;

    for (ite = storeVideoList.begin(); ite != storeVideoList.end(); ++ite)
    {
        video = *ite;
        isInStock = video.getTitle() == title;
        if (isInStock)
        {
            storeVideoList.videoCheckOut(title);
            customerVideoList.insertFirst(video);
            break;
        }
    }
}

// function to return a video
// this function will look for the video from the customer video list using the title
// if found will remove the video from the customer video list
// and then return(check in) to the store - if store don't have the video don't have that title
// then customer can't return
void customerType::returnVideo(string title, videoListType &storeVideoList)
{
    linkedListIterator<videoType> ite;
    videoType currentVideo;
    for (ite = customerVideoList.begin(); ite != customerVideoList.end(); ++ite)
    {
        currentVideo = *ite;
        if (currentVideo.getTitle() == title)
        {
            customerVideoList.deleteNode(currentVideo);
            // also update the store list
            storeVideoList.videoCheckIn(title);
            break;
        }
    }
}

// create customer
void customerType::createCustomer(string firstN, string lastN, int accN, const videoListType &videoList)
{
    this->setName(firstN, lastN);
    this->setAccNumber(accN);
    this->customerVideoList = videoList;
}

// operator overload ==
bool customerType::operator==(const customerType &other) const
{
    return this->accNumber == other.accNumber;
}

bool customerType::operator!=(const customerType &other) const
{
    return this->accNumber != other.accNumber;
}

ostream &operator<<(ostream &out, const customerType &customer)
{
    linkedListIterator<videoType> ite;
    out << customer.getFirstName() << " " << customer.getLastName() << endl;
    out << customer.getAccNumber() << endl;

    if (customer.customerVideoList.isEmptyList())
    {
        out << "---" << endl;
        return out;
    }
    for (ite = customer.customerVideoList.begin(); ite != customer.customerVideoList.end(); ++ite)
    {
        out << *ite;
        // if this is NOT the last video
        linkedListIterator<videoType>
            next = ite;
        ++next;

        if (next != customer.customerVideoList.end())
        {
            out << "+++" << endl;
        }
    }
    out << "---" << endl;
    return out;
}

#endif