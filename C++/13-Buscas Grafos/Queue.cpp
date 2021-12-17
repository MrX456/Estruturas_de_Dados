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
    Node* tempPtr;
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
    Node* location;
    try
    {
        location = new Node;
        delete location;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

void Queue::enqueue(ItemType item)
{
    if(!isFull())
    {
        Node* newNode; //Inserção no final
        newNode = new Node;
        newNode->value = item;
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
        Node* tempPtr;
        tempPtr = front;
        ItemType item = front->value;
        front = front->next;
        if(front == NULL)
            rear = NULL;
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
    Node* tempPtr = front;
    cout << "Fila: " << endl;
    while(tempPtr != NULL)
    {
        cout << tempPtr->value << " ";
        tempPtr = tempPtr->next;
    }
    cout << endl;
}
