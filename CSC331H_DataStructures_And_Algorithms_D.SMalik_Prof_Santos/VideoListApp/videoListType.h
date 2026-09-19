//*****************************************************************
// Author: D.S. Malik
//
// class videoListType
// This class specifies the members to implement a list of videos.
//*****************************************************************
#pragma once
#include <string>
#include <fstream>
#include "unorderedLinkedList.h"
#include "videoType.h"
using namespace std;

class videoListType : public unorderedLinkedList<videoType>
{
public:
    bool videoSearch(string title) const;
    // Function to search the list to see whether a
    // particular title, specified by the parameter title,
    // is in the store.
    // Postcondition: Returns true if the title is found, and
    //  false otherwise.
    bool isVideoAvailable(string title) const;
    // Function to determine whether a copy of a particular
    // video is in the store.
    // Postcondition: Returns true if at least one copy of the
    //  video specified by title is in the store, and false
    //  otherwise.
    void videoCheckOut(string title);
    // Function to check out a video, that is, rent a video.
    // Postcondition: copiesInStock is decremented by one.
    void videoCheckIn(string title);
    // Function to check in a video returned by a customer.
    // Postcondition: copiesInStock is incremented by one.
    bool videoCheckTitle(string title) const;
    // Function to determine whether a particular video is in
    // the store.
    // Postcondition: Returns true if the video’s title is the
    //  same as title, and false otherwise.
    void videoUpdateInStock(string title, int num);
    // Function to update the number of copies of a video
    // by adding the value of the parameter num. The
    // parameter title specifies the name of the video for
    // which the number of copies is to be updated.
    // Postcondition: copiesInStock = copiesInStock + num;
    void videoSetCopiesInStock(string title, int num);
    // Function to reset the number of copies of a video.
    // The parameter title specifies the name of the video
    // for which the number of copies is to be reset, and the
    // parameter num specifies the number of copies.
    // Postcondition: copiesInStock = num;
    void videoPrintTitle() const;
    // Function to print the titles of all the videos in the store.

    void videoPrintDetail() const;
    // Function to print the detail info of all video in the store

    friend ostream &operator<<(ostream &out, const videoListType &);

private:
    void searchVideoList(string title, bool &found,
                         nodeType<videoType> *&current) const;
    // This function searches the video list for a particular
    // video, specified by the parameter title.
    // Postcondition: If the video is found, the parameter found is
    //  set to true, otherwise it is set to false. The parameter
    //  current points to the node containing the video.
};
void videoListType::searchVideoList(string title, bool &found,
                                    nodeType<videoType> *&current) const
{
    found = false;                           // set found to false
    current = first;                         // set current to point to the first node
    while (current != NULL && !found)        // search the list
        if (current->info.checkTitle(title)) // the item is found
            found = true;
        else
            current = current->link; // advance current to
    // the next node
} // end searchVideoList

bool videoListType::isVideoAvailable(string title) const
{
    bool found;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);
    if (found)
        found = (location->info.getNoOfCopiesInStock() > 0);
    else
        found = false;
    return found;
}

void videoListType::videoCheckIn(string title)
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location); // search the list
    if (found)
        location->info.checkIn();
    else
        cout << "The store does not carry " << title << endl;
}
void videoListType::videoCheckOut(string title)
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location); // search the list
    if (found)
        location->info.checkOut();
    else
        cout << "The store does not carry " << title << endl;
}
bool videoListType::videoCheckTitle(string title) const
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location); // search the list
    return found;
}
void videoListType::videoUpdateInStock(string title, int num)
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location); // search the list
    if (found)
        location->info.updateInStock(num);
    else
        cout << "The store does not carry " << title << endl;
}
void videoListType::videoSetCopiesInStock(string title, int num)
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);
    if (found)
        location->info.setCopiesInStock(num);
    else
        cout << "The store does not carry " << title << endl;
}
bool videoListType::videoSearch(string title) const
{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);
    return found;
}
void videoListType::videoPrintTitle() const
{
    nodeType<videoType> *current;
    current = first;
    while (current != NULL)
    {
        current->info.printTitle();
        current = current->link;
    }
}

void videoListType::videoPrintDetail() const
{
    nodeType<videoType> *current;
    current = this->first;
    while (current != nullptr)
    {
        current->info.printInfo();
        current = current->link;
    }
}

ostream &operator<<(ostream &out, const videoListType &videoList)
{
    linkedListIterator<videoType> ite;
    // videoType video;
    for (ite = videoList.begin(); ite != videoList.end(); ++ite)
    {
        out << *ite;
    }
    return out;
}
