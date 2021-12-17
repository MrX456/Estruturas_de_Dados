#include "Hash.h"
#include <iostream>

using namespace std;

Hash::Hash(int max)
{
    length = 0;
    max_itens = max;
    structure = new Aluno[max_itens];
}

Hash::~Hash()
{
    delete [] structure;
}

bool Hash::isFull() const
{
    return(length == max_itens);
}

int Hash::getLength() const
{
    return length;
}

void Hash::retrieveItem(Aluno& aluno, bool& found)
{
    //Referencia de objeto aluno, referencia de bool. O que for feito
    //com variavel interna aluno, vai ser feito fora
    int location = getHash(aluno);
    Aluno aux = structure[location];

    if(aluno.getRA() != aux.getRA())
    {
        found = false;
    }
    else
    {
        found = true;
        aluno = aux;
    }
}

void Hash::insertItem(Aluno aluno)
{
    //Não funciona corretamente se houver colisões
    int location = getHash(aluno);
    structure[location] = aluno;
    length++;
}

void Hash::deleteItem(Aluno aluno)
{
    int location = getHash(aluno);
    structure[location] = Aluno(); //Insere um aluno inválido
    length--;
}

void Hash::print()
{
    //Não pode ultrapassar o tamanho maximo de itens definido
    for(int i = 0; i < max_itens; i++)
    {
        cout << i << ":" <<
            structure[i].getRA() << ", " <<
            structure[i].getNome() << endl;
    }
}

int Hash::getHash(Aluno aluno)
{
    //Devolve inteiro entre 0 e tamanho do array
    return aluno.getRA() % max_itens;
}

