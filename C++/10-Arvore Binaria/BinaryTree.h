#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Aluno.h"
#include <iostream>>

struct Node
{
    Aluno aluno;
    Node* filhoEsqueda;
    Node* filhoDireita;
};

class BinaryTree
{
    public:
        BinaryTree();
        ~BinaryTree();
        void deletarArvore(Node* noAtual);
        Node* getNode();
        bool isEmpty();
        bool isFull();
        void insertAluno(Aluno aluno);
        void removeAluno(Aluno aluno);
        void removeSearch(Aluno aluno, Node*& noAtual);
        void deleteNode(Node*& noAtual);
        void getSucessor(Aluno& alunoSucessor, Node* temp);
        void search(Aluno& aluno, bool& busca);
        void printPreOrder(Node* noAtual);
        void printInOrder(Node* noAtual);
        void printPostOrder(Node* noAtual);

    private:
        Node* raiz;
};

#endif // BINARYTREE_H
