#ifndef QUEUE_H
#define QUEUE_H
#include "../ItemType.h"

class Queue
{
    public:
        Queue();
        virtual ~Queue();
        bool isEmpty() const; //N�o vai alterar atributos privados
        bool isFull() const;
        void print() const;
        void enqueue(ItemType);
        ItemType dequeue();

    private:
        NodeType* front;
        NodeType* rear;
};

#endif // QUEUE_H

