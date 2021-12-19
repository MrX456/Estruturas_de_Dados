#include "AVLTree.h"
#include <iostream>
#include <cstddef>

AVLTree::AVLTree()
{
    raiz = NULL;
}

AVLTree::~AVLTree()
{
    deleteTree(raiz);
}

void AVLTree::deleteTree(Node* Noatual)
{
    if (Noatual != NULL){
        deleteTree(Noatual->filhoesquerda);

        deleteTree(Noatual->filhodireita);

        delete Noatual;
    }
}

Node* AVLTree::getNode()
{
    return raiz;
}

bool AVLTree::isEmpty()
{
    return (raiz == NULL);
}

bool AVLTree::isFull()
{
    try{
        Node* temp = new Node;
        delete temp;
        return false;
    } catch(bad_alloc exception){
        return true;
    }
}

void AVLTree::insertAluno(Aluno aluno)
{
    bool cresceu;
    insererecursivo(raiz, aluno, cresceu);
}

void AVLTree::insererecursivo(Node*& noatual, Aluno aluno, bool& cresceu)
{
    if (noatual == NULL) {
        noatual = new Node;
        noatual->filhodireita = NULL;
        noatual->filhoesquerda = NULL;
        noatual->aluno = aluno;
        noatual->fatorB = 0;
        cresceu = true;
        return;
    }
    if (aluno.getRa() < noatual->aluno.getRa()) {
        insererecursivo(noatual->filhoesquerda, aluno, cresceu);
        if (cresceu){
            noatual->fatorB -= 1;
        }
    } else {
        insererecursivo(noatual->filhodireita, aluno, cresceu);
        if (cresceu){
            noatual->fatorB += 1;
        }
    }
    realizarotacao(noatual);

    if (cresceu && noatual->fatorB == 0){
        cresceu = false;
    }
}

void AVLTree::deleteAluno(Aluno aluno)
{
    bool diminuiu;
    deleteSearch(aluno, raiz, diminuiu);
}

void AVLTree::deleteSearch(Aluno aluno, Node*& noatual, bool& diminuiu)
{
    if (aluno.getRa() < noatual->aluno.getRa()){
        deleteSearch(aluno, noatual->filhoesquerda, diminuiu);
        if (diminuiu){
            noatual->fatorB+=1;
        }
    } else if (aluno.getRa() > noatual->aluno.getRa()){
        deleteSearch(aluno, noatual->filhodireita, diminuiu);
        if (diminuiu){
            noatual->fatorB-=1;
        }
    } else{
        deleteNode(noatual, diminuiu);
    }
    if (noatual != NULL){
        realizarotacao(noatual);
        if (diminuiu && noatual->fatorB != 0){
            diminuiu = false;
        }
    }
}

void AVLTree::deleteNode(Node*& noatual, bool& diminuiu)
{
    Node* temp = noatual;
    if (noatual->filhoesquerda == NULL){
        noatual = noatual->filhodireita;
        diminuiu = true;
        delete temp;
    } else if (noatual->filhodireita == NULL){
        noatual = noatual->filhoesquerda;
        diminuiu = true;
        delete temp;
    } else{
        Aluno AlunoSucessor;
        getSucessor(AlunoSucessor, noatual);
        noatual->aluno = AlunoSucessor;
        deleteSearch(AlunoSucessor, noatual->filhodireita, diminuiu);
        if (diminuiu){
            noatual->fatorB -= 1;
        }
    }
}

void AVLTree::getSucessor(Aluno& AlunoSucessor, Node* temp)
{
    temp = temp->filhodireita;
    while (temp->filhoesquerda != NULL){
        temp = temp->filhoesquerda;
    }
    AlunoSucessor = temp->aluno;
}

void AVLTree::searchAluno(Aluno& aluno, bool& busca)
{
    busca = false;
    Node* noatual = raiz;
    while (noatual != NULL){
        if (aluno.getRa() < noatual->aluno.getRa()){
            noatual = noatual->filhoesquerda;
        } else if (aluno.getRa() > noatual->aluno.getRa()){
            noatual = noatual->filhodireita;
        } else{
            busca = true;
            aluno = noatual->aluno;
            break;
        }
    }
}

void AVLTree::printPreOrder(Node* Noatual)
{
    if (Noatual != NULL){
        cout << Noatual->aluno.getNome() << ": ";
        cout << Noatual->aluno.getRa() << endl;

        printPreOrder(Noatual->filhoesquerda);

        printPreOrder(Noatual->filhodireita);
    }
}

void AVLTree::printInOrder(Node* Noatual)
{
    if (Noatual != NULL){
        printInOrder(Noatual->filhoesquerda);

        cout << Noatual->aluno.getNome() << ": ";
        cout << Noatual->aluno.getRa() << endl;

        printInOrder(Noatual->filhodireita);
    }
}

void AVLTree::printPostOrder(Node* Noatual)
{
    if (Noatual != NULL){
        printPostOrder(Noatual->filhoesquerda);

        printPostOrder(Noatual->filhodireita);

        cout << Noatual->aluno.getNome() << ": ";
        cout << Noatual->aluno.getRa() << endl;
    }
}

void AVLTree::rotacaodireita(Node*& pai) //novo
{
    Node* novopai = pai->filhoesquerda;
    pai->filhoesquerda = novopai->filhodireita;
    novopai->filhodireita = pai;
    pai = novopai;
}

void AVLTree::rotacaoesquerda(Node*& pai) //novo
{
    Node* novopai = pai->filhodireita;
    pai->filhodireita = novopai->filhoesquerda;
    novopai->filhoesquerda = pai;
    pai = novopai;
}

void AVLTree::rotacaoesquerdadireita(Node*& pai)
{
    Node* filho = pai->filhoesquerda;
    rotacaoesquerda(filho);
    pai->filhoesquerda = filho;
    rotacaodireita(pai);
}

void AVLTree::rotacaodireitaesquerda(Node*& pai)
{
    Node* filho = pai->filhodireita;
    rotacaodireita(filho);
    pai->filhodireita = filho;
    rotacaoesquerda(pai);
}

void AVLTree::realizarotacao(Node*& pai)
{
    Node* filho;
    Node* neto; // Caso precise da rotação dupla

    if (pai->fatorB == -2){ //rotaciona para a direita

    filho = pai->filhoesquerda;

    if (filho->fatorB == -1){ // Simples para a direita
        pai->fatorB = 0;
        filho->fatorB = 0;
        rotacaodireita(pai);
    } else if (filho->fatorB == 0){ // Simples para a direita
        pai->fatorB = -1;
        filho->fatorB = 1;
        rotacaodireita(pai);
    } else if (filho->fatorB == 1){ // Rotação dupla
        neto = filho->filhodireita;
        if (neto->fatorB == -1){
            pai->fatorB = 1;
            filho->fatorB = 0;
        } else if (neto->fatorB == 0){
            pai->fatorB = 0;
            filho->fatorB = 0;
        } else if (neto->fatorB == 1){
            pai->fatorB = 0;
            filho->fatorB = -1;
        }
        neto->fatorB = 0;
        rotacaodireitaesquerda(pai);
    }



    } else if(pai->fatorB == 2){ //rotaciona para a esquerda
        filho = pai->filhodireita;
        if (filho->fatorB == 1) { // Simples para a esquerda
            pai->fatorB = 0;
            filho->fatorB = 0;
            rotacaoesquerda(pai);
        } else if (filho->fatorB == 0){ // Simples para a esquerda
            pai->fatorB = 1;
            filho->fatorB = -1;
            rotacaoesquerda(pai);
        } else if (filho->fatorB == -1){ // Rotacao dupla
            neto = filho->filhoesquerda;
            if (neto->fatorB == -1){
                pai->fatorB =  0;
                filho->fatorB = 1;
            } else if (neto->fatorB == 0){
                pai->fatorB =  0;
                filho->fatorB = 0;
            } else if (neto->fatorB == 1){
                pai->fatorB =  -1;
                filho->fatorB = 0;
            }
            neto->fatorB = 0;
            rotacaodireitaesquerda(pai);
        }
    }
}

