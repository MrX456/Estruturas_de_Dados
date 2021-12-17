#include "Queue.h"
#include <iostream>
#include <cstddef>
#include <new>

using namespace std;

Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

Queue::~Queue()
{
    NodeType* tempPtr;
    while(front != NULL)
    {
        tempPtr = front;
        front = front->next;
        delete tempPtr;
    }
    rear = NULL;
}

bool Queue::isEmpty() const
{
    return(front == NULL);
}

bool Queue::isFull() const
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

void Queue::enqueue(ItemType newItem)
{
    if(!isFull())
    {
        NodeType* newNode; //Inserção no final
        newNode = new NodeType;
        newNode->info = newItem;
        newNode->next = NULL; //Ultimo da fila sempre aponta para NULL
        if(rear == NULL)
            front = newNode;
        else
            rear->next = newNode;
        rear = newNode;
    }
    else
    {
        throw "Queue is already full!";
    }
}

ItemType Queue::dequeue()
{
    if(!isEmpty())
    {
        NodeType* tempPtr;
        tempPtr = front;
        ItemType item = front->info;
        front = front->next; //Aponta para próximo elemento
        if(front == NULL)
            rear = NULL; //Já esta no ultimo elemento
        delete tempPtr;
        return item;
    }
    else
    {
        throw "Queue is empty!";
    }
}

void Queue::print() const
{
    NodeType* tempPtr = front;
    while(tempPtr != NULL)
    {
        cout << tempPtr->info;
        tempPtr = tempPtr->next;
    }
    cout << endl;
}
