#include "Stack.h"
#include <cstddef>
#include <new>
#include <iostream>

using namespace std;

Stack::Stack()
{
    structure = NULL; //Não aponta para nada no momento(requer cstddef)
}

//Destrutor
Stack::~Stack()
{
    //A cada nova inserção será alocada memória
    NodeType* tempPtr;
    //Varrer a estrutura para desalocar todos elementos
    while(structure != NULL)
    {
        tempPtr = structure; //Apontar para o nó que será removido
        structure = structure->next; //Apontar para próximo elemento(como de trata de um ponteiro usamos ->)
        delete tempPtr;
    }
}

bool Stack::isEmpty() const
{
    return(structure == NULL); //ponteiro inicial não aponta para ninguem
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
        return true; //Memória do usuário está cheia, não da pra alocar mais espaço
    }
}

void Stack::push(ItemType item)
{
    if(!isFull())
    {
        NodeType* location;
        location = new NodeType;
        location->info = item;
        location->next = structure; //aponta para cabeça da pilha
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
        tempPtr = structure; //aponta para a cabeça da piilha
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
    NodeType* tempPtr = structure; //cabeça da pilha
    //a cada iteração vai apontar para o elemento seguinte da pilha
    while(tempPtr != NULL)
    {
        cout << tempPtr->info;
        tempPtr = tempPtr->next;
    }
    cout << endl;
}

