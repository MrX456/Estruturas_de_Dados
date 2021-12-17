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
    int startLoc = getHash(aluno);
    bool moreToSearch = true;
    int location = startLoc;

    do
    {
        if(structure[location].getRA() == aluno.getRA() ||
           structure[location].getRA() == -1)
        {
            moreToSearch = false; //Não procurar mais
        }
        else
        {
            location = (location + 1) % max_itens;
        }
    }
    while(location != startLoc && moreToSearch);

    found = (structure[location].getRA() == aluno.getRA());
    if(found)
    {
        aluno = structure[location];
    }
}

void Hash::insertItem(Aluno aluno)
{
    int location = getHash(aluno);
    while(structure[location].getRA() > 0)
        location = (location + 1) % max_itens;
    structure[location] = aluno;
    length++;
}

void Hash::deleteItem(Aluno aluno)
{
    int startLoc = getHash(aluno);
    bool moreToSearch = true;
    int location = startLoc;

    do
    {
        if(structure[location].getRA() == aluno.getRA() ||
           structure[location].getRA() == -1)
        {
            moreToSearch = false; //Não procurar mais
        }
        else
        {
            location = (location + 1) % max_itens;
        }
    }
    while(location != startLoc && moreToSearch);

    if(structure[location].getRA() == aluno.getRA())
    {
        structure[location] = Aluno(-2, ""); //Posição que teve aluno excluido recebe -2
        length--;
    }
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

