#ifndef HASH_H
#define HASH_H
#include "Aluno.h"

class Hash
{
    public:
        Hash(int max_itens = 100);
        ~Hash();
        bool isFull() const;
        int getLength() const;

        void retrieveItem(Aluno& aluno, bool& found);
        void insertItem(Aluno aluno);
        void deleteItem(Aluno aluno);
        void print();

    private:
        int getHash(Aluno aluno);
        int max_itens;
        int length;
        Aluno* structure;
};

#endif // HASH_H
