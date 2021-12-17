#ifndef ITEMTYPE_H_INCLUDED
#define ITEMTYPE_H_INCLUDED

typedef char ItemType;


struct NodeType
{
    ItemType info;
    NodeType* next;
};

#endif // ITEMTYPE_H_INCLUDED
