#ifndef STACK_H
#define STACK_H

const int MAX_ITENS = 100; //Tamanho maximo do vetor

class Stack
{
    public:
        Stack();
        ~Stack();
        bool isEmpty() const;
        bool isFull() const;
        void print() const;

        void push(char c);
        char pop();

    private:
        int length;
        char* structure; //Vetor de char
};

#endif // STACK_H
