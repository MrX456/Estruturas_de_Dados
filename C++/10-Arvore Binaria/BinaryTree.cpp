#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
    raiz = NULL;
}

BinaryTree::~BinaryTree()
{
    deletarArvore(raiz);
}

void BinaryTree::deletarArvore(Node* noAtual)
{
    if(noAtual != NULL)
    {
        deletarArvore(noAtual->filhoEsqueda);
        deletarArvore(noAtual->filhoDireita);
        delete noAtual;
    }
}

Node* BinaryTree::getNode()
{
    return raiz;
}

bool BinaryTree::isEmpty()
{
    return (raiz == NULL);
}

bool BinaryTree::isFull()
{
    try
    {
        Node* temp = new Node;
        delete temp;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

void BinaryTree::insertAluno(Aluno aluno)
{
    if(isFull())
    {
        cout << "Tree is already full!" << endl;
    }
    else
    {
        Node* newNode = new Node;
        newNode->aluno = aluno;
        newNode->filhoDireita = NULL;
        newNode->filhoEsqueda = NULL;
        if(raiz == NULL)
        {
            raiz = newNode;
        }
        else
        {
            Node* temp = raiz;
            while(temp != NULL)
            {
                if(aluno.getRA() < temp->aluno.getRA())
                {
                    if(temp->filhoEsqueda == NULL)
                    {
                        temp->filhoEsqueda = newNode;
                        break;
                    }
                    else
                    {
                        temp = temp->filhoEsqueda;
                    }
                }
                else
                {
                    if(temp->filhoDireita == NULL)
                    {
                        temp->filhoDireita = newNode;
                        break;
                    }
                    else
                    {
                        temp = temp->filhoDireita;
                    }
                }
            }
        }
    }
}

void BinaryTree::removeAluno(Aluno aluno)
{
    removeSearch(aluno, raiz);
}

void BinaryTree::removeSearch(Aluno aluno, Node*& noAtual)
{
    if(aluno.getRA() < noAtual->aluno.getRA())
        removeSearch(aluno, noAtual->filhoEsqueda);
    else if(aluno.getRA() > noAtual->aluno.getRA())
        removeSearch(aluno, noAtual->filhoDireita);
    else
        deleteNode(noAtual);
}

void BinaryTree::deleteNode(Node*& noAtual)
{
    Node* temp = noAtual;
    if(noAtual->filhoEsqueda == NULL)
    {
        noAtual = noAtual->filhoDireita;
        delete temp;
    }
    else if(noAtual->filhoDireita == NULL)
    {
        noAtual = noAtual->filhoEsqueda;
        delete temp;
    }
    else
    {
        Aluno alunoSucessor;
        getSucessor(alunoSucessor, noAtual);
        noAtual->aluno = alunoSucessor;
        removeSearch(alunoSucessor, noAtual->filhoDireita);
    }
}

void BinaryTree::getSucessor(Aluno& alunoSucessor, Node* temp)
{
    temp = temp->filhoDireita;
    while(temp->filhoEsqueda != NULL)
    {
        temp = temp->filhoEsqueda;
    }
    alunoSucessor = temp->aluno;
}

void BinaryTree::search(Aluno& aluno, bool& busca)
{
    busca = false;
    Node* noAtual = raiz;
    while(noAtual != NULL)
    {
        if(aluno.getRA() < noAtual->aluno.getRA())
        {
            noAtual = noAtual->filhoEsqueda;
        }
        else if(aluno.getRA() > noAtual->aluno.getRA())
        {
            noAtual = noAtual->filhoDireita;
        }
        else
        {
            busca  = true;
            aluno = noAtual->aluno;
            break;
        }
    }
}

void BinaryTree::printPreOrder(Node* noAtual)
{
    if(noAtual != NULL)
    {
        cout << noAtual->aluno.getNome() << ": ";
        cout << noAtual->aluno.getRA() << endl;

        printPreOrder(noAtual->filhoEsqueda);
        printPreOrder(noAtual->filhoDireita);
    }
}

void BinaryTree::printInOrder(Node* noAtual)
{
    if(noAtual != NULL)
    {
        printInOrder(noAtual->filhoEsqueda);

        cout << noAtual->aluno.getNome() << ": ";
        cout << noAtual->aluno.getRA() << endl;

        printInOrder(noAtual->filhoDireita);
    }
}

void BinaryTree::printPostOrder(Node* noAtual)
{
    if(noAtual != NULL)
    {
        printPostOrder(noAtual->filhoEsqueda);
        printPostOrder(noAtual->filhoDireita);

        cout << noAtual->aluno.getNome() << ": ";
        cout << noAtual->aluno.getRA() << endl;
    }
}
