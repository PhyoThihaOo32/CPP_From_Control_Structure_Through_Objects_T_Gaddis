#ifndef NODETYPE_H
#define NODETYPE_H

template <class Type>
struct nodeType
{
    /* data */
    Type info;
    nodeType<Type> *link;
};

#endif NODETYPE_H
