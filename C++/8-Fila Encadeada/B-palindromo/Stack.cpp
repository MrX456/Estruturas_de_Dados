#include "Stack.h"
#include <cstddef>
#include <new>
#include <iostream>

using namespace std;

Stack::Stack()
{
    structure = NULL; //N�o aponta para nada no momento(requer cstddef)
}

//Destrutor
Stack::~Stack()
{
    //A cada nova inser��o ser� alocada mem�ria
    NodeType* tempPtr;
    //Varrer a estrutura para desalocar todos elementos
    while(structure != NULL)
    {
        tempPtr = structure; //Apontar para o n� que ser� removido
        structure = structure->next; //Apontar para pr�ximo elemento(como de trata de um ponteiro usamos ->)
        delete tempPtr;
    }
}

bool Stack::isEmpty() const
{
    return(structure == NULL); //ponteiro inicial n�o aponta para ninguem
}

bool Stack::isFull() const
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(bad_alloc exception) //Requer <new>
    {
        return true; //Mem�ria do usu�rio est� cheia, n�o da pra alocar mais espa�o
    }
}

void Stack::push(ItemType item)
{
    if(!isFull())
    {
        NodeType* location;
        location = new NodeType;
        location->info = item;
        location->next = structure; //aponta para cabe�a da pilha
        structure = location;
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
        NodeType* tempPtr;
        tempPtr = structure; //aponta para a cabe�a da piilha
        ItemType item = structure->info;
        structure = structure->next; //aponta para segundo elemento
        delete tempPtr;
        return item;
    }
    else
    {
        throw "Stack is empty!";
    }
}

void Stack::print() const
{
    NodeType* tempPtr = structure; //cabe�a da pilha
    //a cada itera��o vai apontar para o elemento seguinte da pilha
    while(tempPtr != NULL)
    {
        cout << tempPtr->info;
        tempPtr = tempPtr->next;
    }
    cout << endl;
}

