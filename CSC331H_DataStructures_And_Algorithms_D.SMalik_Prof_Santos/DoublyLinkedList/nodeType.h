#pragma once
#ifndef NODETYPE_H
#define NODETYPE

template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *next;
    nodeType<Type> *back;
};

#endif
