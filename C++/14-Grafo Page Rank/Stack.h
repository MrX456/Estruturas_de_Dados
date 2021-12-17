#ifndef STACK_H
#define STACK_H
#include "Node.h"


class Stack
{
    public:
        Stack();
        virtual ~Stack();
        bool isEmpty() const;
        bool isFull() const;
        void print() const;

        void push(ItemType item);
        ItemType pop();

    private:
        Node* nodeTop;
};

#endif // STACK_H
