#include <iostream>
#include "BinaryTree.h"
#include <string>

using namespace std;

int main()
{
    BinaryTree alunoTree;
    int opt,
        ra,
        pri;
    string nome;
    bool found = false;

    cout << "Arvore Binaria de Busca" << endl;

    do
    {
        cout << "Digite 0 para parar o algoritmo" << endl;
        cout << "Digite 1 para inserir um elemento" << endl;
        cout << "Digite 2 para remover uma elemento" << endl;
        cout << "Digite 3 para buscar um elemento" << endl;
        cout << "Digite 4 para imprimir a arvore" << endl;
        cin >> opt;

        if(opt == 1)
        {
            cout << "Digite o nome do aluno" << endl;
            cin >> nome;
            cout << "Digite o RA do aluno" << endl;
            cin >> ra;
            Aluno aluno(ra, nome);

            if(alunoTree.isFull())
            {
                cout << "Arvore esta cheia, impossivel inserir aluno" << endl;
            }
            else
            {
                alunoTree.insertAluno(aluno);
            }
        }
        else if(opt == 2)
        {
             cout << "Digite o RA do aluno a ser removido:" << endl;
             cin >> ra;
             Aluno aluno(ra, "");
             alunoTree.removeAluno(aluno);
        }
        else if(opt == 3)
        {
             cout << "Digite o RA do aluno a ser buscado:" << endl;
             cin >> ra;
             Aluno aluno(ra, "");
             alunoTree.search(aluno, found);
             if(found)
             {
                 cout << "Aluno encontrado." << endl;
                 cout << "Nome : " << aluno.getNome()<< endl;
                 cout << "RA : " << aluno.getRA()<< endl;
             }
             else
            {
                cout << "Aluno nao encontrado." << endl;
            }
        }
        else if(opt == 4)
        {
            cout << "Digite 1 para impressao pre-order" << endl;
            cout << "Digite 2 para impressao in-order" << endl;
            cout << "Digite 3 para impressao post-order" << endl;
            cin >> pri;
            switch(pri)
            {
                case 1:
                    cout << "Pre-order" << endl;
                    alunoTree.printPreOrder(alunoTree.getNode());
                    break;
                case 2:
                    cout << "In-order" << endl;
                    alunoTree.printInOrder(alunoTree.getNode());
                    break;
                case 3:
                    cout << "Post-order" << endl;
                    alunoTree.printPostOrder(alunoTree.getNode());
                    break;
                default:
                    cout << "Opcao invalida";
                    break;
            }
        }
    }
    while(opt != 0);

    return 0;
}
