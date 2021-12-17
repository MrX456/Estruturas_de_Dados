#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"


class Queue
{
    public:
        Queue();
        ~Queue();
        bool isEmpty() const;
        bool isFull() const;
        void print() const;
        void enqueue(ItemType item);
        ItemType dequeue();

    protected:

    private:
        Node* front;
        Node* rear;
};

#endif // QUEUE_H
