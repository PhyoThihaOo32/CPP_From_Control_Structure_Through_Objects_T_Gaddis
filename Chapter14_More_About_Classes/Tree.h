// specification file for tree class

#ifndef TREE_H
#define TREE_H

class Tree
{
private:
    static int objectCount;

public:
    // Constructor
    Tree()
    {
        objectCount++;
    }

    // accessor function for objectCount
    int getObjectCount() const
    {
        return objectCount;
    }
};

#endif

// definition of static member function written outside the class
int Tree::objectCount = 0;
