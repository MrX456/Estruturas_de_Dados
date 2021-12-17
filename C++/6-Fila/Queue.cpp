#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue()
{
    front = 0;
    back = 0;
    structure = new char[MAX_ITENS];
}

Queue::~Queue()
{
    delete [] structure;
}

bool Queue::isEmpty() const
{
    return(front == back);
}

bool Queue::isFull() const
{
    return(back - front == MAX_ITENS);
}

void Queue::enqueue(char c)
{
    if(!isFull())
    {
        structure[back % MAX_ITENS] = c;
        back++;
    }
    else
    {
        throw "Queue is already full!";
    }
}

char Queue::dequeue()
{
    if(!isEmpty())
    {
        front++;
        return structure[(front - 1) % MAX_ITENS];
    }
    else
    {
        throw "Queue is empty!";
    }
}

void Queue::print() const
{
    cout << "Fila = ";

    for(int i = front; i < back; i++)
    {
        cout << structure[i % MAX_ITENS];
    }

    cout << endl;
}
