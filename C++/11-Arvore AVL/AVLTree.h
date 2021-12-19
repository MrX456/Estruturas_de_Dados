#include <iostream>
#include "aluno.h"

struct Node{
    Aluno aluno;
    Node* filhoesquerda;
    Node* filhodireita;

    int fatorB; //fator e balanceamento
};

class AVLTree{
    private:
    Node* raiz;

    public:
    AVLTree();
    ~AVLTree();
    void deleteTree(Node* Noatual);
    Node* getNode();
    bool isEmpty();
    bool isFull();
    void insertAluno(Aluno aluno);
    void deleteAluno(Aluno aluno); // modificada
    void deleteSearch(Aluno aluno, Node*& noatual, bool& diminuiu); //modificada
    void deleteNode(Node*& noatual, bool& diminuiu); // modificada
    void getSucessor(Aluno& AlunoSucessor, Node* temp);
    void searchAluno(Aluno& aluno, bool& busca);
    void printPreOrder(Node* Noatual);
    void printInOrder(Node* Noatual);
    void printPostOrder(Node* Noatual);

    // métodos de rotações:

    void rotacaodireita(Node*& tree);
    void rotacaoesquerda(Node*& tree);
    void rotacaoesquerdadireita(Node*& tree);
    void rotacaodireitaesquerda(Node*& tree);
    void realizarotacao(Node*& tree);
    void insererecursivo(Node*& noatual, Aluno aluno, bool& cresceu);

};
