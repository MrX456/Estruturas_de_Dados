#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
    length = 0;
    structure = new char[MAX_ITENS];
}
//destrutor
Stack::~Stack()
{
    delete [] structure;
}

bool Stack::isEmpty() const
{
    return(length == 0);
}

bool Stack::isFull() const
{
    return(length == MAX_ITENS);
}

void Stack::push(char c)
{
    if(!isFull())
    {
        structure[length] = c;
        length++;
    }
    else
    {
        throw "Stack already full!";
    }
}

char Stack::pop()
{
    if(!isEmpty())
    {
        char aux = structure[length - 1];
        length--;
        return aux;
    }
    else
    {
        throw "Stack is empty!";
    }
}

void Stack::print() const
{
    cout << "Pilha = ";

    for(int i = 0; i < length; i++)
    {
        cout << structure[i] << " ";
    }

    cout << endl;
}


