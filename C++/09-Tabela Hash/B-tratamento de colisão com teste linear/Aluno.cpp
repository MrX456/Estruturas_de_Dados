#include "Aluno.h"
#include <string>

Aluno::Aluno()
{
    this->ra = -1; //RA invalido
    this->nome = ""; //Representa uma posição vazia
}

Aluno::Aluno(int ra, string nome)
{
    this->ra = ra;
    this->nome = nome;
}

string Aluno::getNome() const
{
    return nome;
}

int Aluno::getRA() const
{
    return ra;
}

