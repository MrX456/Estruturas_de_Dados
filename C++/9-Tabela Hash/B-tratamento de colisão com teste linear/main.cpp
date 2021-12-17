#include <iostream>
#include <string>
#include "Aluno.h"
#include "Hash.h"

using namespace std;

int main()
{
    Hash alunoHash(10); //Vetor tem tamanho 10(0 a 9)
    //Ras e nomes de 7 alunos
    int ras[7] = {12704, 31300, 1234, 49001, 52202, 65606, 91234};
    string nomes[7] = {"Pedro", "Raul", "Paulo", "Carlos", "Lucas", "Maria", "Samanta"};

    for(int i = 0; i < 7; i++)
    {
        Aluno aluno = Aluno(ras[i], nomes[i]);//Criar instancia de cada aluno
        alunoHash.insertItem(aluno);//Inserir cada aluno na tabela
    }

    alunoHash.print();

    cout << "------------------------------------" << endl;

    //Procurando aluno()
    Aluno aluno(12704, "");//Não existe mais devido a colisão
    bool found = false;
    alunoHash.retrieveItem(aluno, found);
    cout << aluno.getNome() << "->" << found << endl; //Não encontrou nada

    cout << "------------------------------------" << endl;

    //|Excluido aluno
    alunoHash.deleteItem(aluno);
    alunoHash.print();

    return 0;
}
