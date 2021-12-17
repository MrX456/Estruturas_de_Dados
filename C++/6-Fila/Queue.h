#ifndef QUEUE_H
#define QUEUE_H

const int MAX_ITENS = 100;

class Queue
{
    public:
        Queue();
        virtual ~Queue();
        bool isEmpty() const; //Não vai alterar atributos privados
        bool isFull() const;
        void print() const;
        void enqueue(char c);
        char dequeue();

    private:
        int front;
        int back;
        char* structure;
};

#endif // QUEUE_H
