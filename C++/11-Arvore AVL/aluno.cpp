#include "aluno.h"
using namespace std;

    Aluno::Aluno()
    {
        ra = -1;
        nome = " ";
    }

    Aluno::Aluno(int ra, string nome)
    {
        this->ra = ra;
        this->nome = nome;
    }

    string Aluno::getNome()
    {
        return nome;
    }

    int Aluno::getRa()
    {
        return ra;
    }
