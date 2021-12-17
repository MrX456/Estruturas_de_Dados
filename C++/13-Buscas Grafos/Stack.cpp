#include "Stack.h"
#include <iostream>
#include <new>
#include <cstddef>

using namespace std;

Stack::Stack()
{
    nodeTop = NULL;
}

Stack::~Stack()
{
    Node* temp;
    while(nodeTop != NULL)
    {
        temp = nodeTop;
        nodeTop = nodeTop->next;
        delete temp;
    }
}

bool Stack::isEmpty() const
{
    return(nodeTop == NULL);
}

bool Stack::isFull() const
{
    Node* newNode;
    try
    {
        newNode = new Node;
        delete newNode;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

void Stack::push(ItemType item)
{
    if(!isFull())
    {
        Node* newNode = new Node;
        newNode->value = item;
        newNode->next = nodeTop;
        nodeTop = newNode;
    }
    else
    {
        throw "Stack already full!";
    }
}

ItemType Stack::pop()
{
    if(!isEmpty())
    {
        Node* temp;
        temp = nodeTop;
        ItemType item = nodeTop->value;
        nodeTop = nodeTop->next;
        delete temp;
        return item;
    }
    else
    {
        throw "Stack is empty!";
    }
}

void Stack::print() const
{
    Node* temp = nodeTop;
    cout << "Pilha = ";
    while(temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }

    cout << endl;
}
