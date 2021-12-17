#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <iostream>

using namespace std;

typedef string ItemType;

struct Node
{
    ItemType value;
    Node* next;
};

#endif // NODE_H_INCLUDED
